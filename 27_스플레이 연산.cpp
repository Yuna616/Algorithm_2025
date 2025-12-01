#include <iostream>

using namespace std;

struct Node {
	int key; // 키값
	int cnt; // 키와 동일한 키를 삽입한 횟수
	int sz; // 현재 노드를 루트로하는 서브트리에 저장된 모든 키의 개수
	Node* left, * right;
	Node(int key, Node* left = nullptr, Node* right = nullptr)
		: key(key), cnt(1), sz(1), left(left), right(right) {}
};
void DestroySplayTree(Node* root)
{
	if (root->left) DestroySplayTree(root->left);
	if (root->right) DestroySplayTree(root->right);
	delete root;
}
int GetSize(Node* x)
{
	return x ? x->sz : 0;
}
void Resize(Node* x)
{
	if (!x) return;
	x->sz = x->cnt + GetSize(x->left) + GetSize(x->right);
}
Node* Zig(Node* y)
{
	Node* x = y->left;
	y->left = x->right;
	x->right = y;
	Resize(y); Resize(x); // 순서가 바뀌면 안됨
	return x;
}
Node* Zag(Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	y->left = x;
	Resize(x); Resize(y); // 순서가 바뀌면 안됨
	return y;
}

Node* ZigZag(Node* z) {
	z->left = Zag(z->left);
	return Zig(z);
}
Node* ZagZig(Node* z) {
	z->right = Zig(z->right);
	return Zag(z);
}

Node* ZigZig(Node* z) {
	return Zig(Zig(z));
}
Node* ZagZag(Node* x) {
	return Zag(Zag(x));
}

Node* Splay(Node* t, int key) {
	if (t == NULL) {
		return NULL;
	}
	if (key == t->key) {
		return t;
	}
	else if (key < t->key) {
		if (t->left == nullptr)return t;
		if (key < t->left->key) {
			t->left->left = Splay(t->left->left, key);
			return (t->left->left != nullptr) ? ZigZig(t) : Zig(t);
		}
		else if (key > t->left->key) {
			t->left->right = Splay(t->left->right, key);
			return (t->left->right != nullptr) ? ZigZag(t) : Zig(t);
		}
		else {
			return Zig(t);
		}
	}
	else {
		if (t->right == nullptr)return t;
		if (key < t->right->key) {
			t->right->left = Splay(t->right->left, key);
			return (t->right->left != nullptr) ? ZagZig(t) : Zag(t);
		}
		else if (key > t->right->key) {
			t->right->right = Splay(t->right->right, key);
			return (t->right->right != nullptr) ? ZagZag(t) : Zag(t);
		}

		else {
			return Zag(t);
		}
	}
}

Node* Search(Node*& root, int key) {
	root = Splay(root, key);
	if (key == root->key)
		return root;
	else
		return NULL;
}

Node* Insert(Node* root, int key) {
	if (root == NULL)
		return new Node(key);

	root = Splay(root, key);

	if (key == root->key) {
		root->cnt++;
		Resize(root);
		return root;
	}

	Node* node = new Node(key);

	if (key < root->key) {
		node->left = root->left;
		node->right = root;
		root->left = nullptr;
	}
	else {
		node->right = root->right;
		node->left = root;
		root->right = nullptr;
	}

	Resize(root);
	Resize(node);
	return node;
}


Node* Delete(Node* root, int key) {
	root = Splay(root, key);

	if (root == NULL || root->key != key)
		return root;
	if (root->cnt > 1) {
		root->cnt -= 1;
		Resize(root);
		return root;
	}
	Node* oldRoot = root;
	if (root->left == nullptr) {
		root = root->right;
	}
	else {
		Node* r = root->right;
		root = Splay(root->left, key);
		root->right = r;
		Resize(root);
	}
	delete oldRoot;
	return root;
}

int FindByOrder(Node*& root, int k) {
	if (!root) return -1;
	if (k <= 0 || k > GetSize(root)) return -1;
	Node* cur = root;
	while (cur) {
		int leftSize = GetSize(cur->left);
		if (k <= leftSize) {
			cur = cur->left;
		}
		else if (k <= leftSize + cur->cnt) {

			root = Splay(root, cur->key); 
			return cur->key;
		}
		else {
			k -= leftSize + cur->cnt;
			cur = cur->right;
		}
	}
	return -1;
}


int OrderOfKey(Node*& root, int x) {
	if (!root) return 0;
	root = Splay(root, x);
	
	if (root->key >= x) {
		return GetSize(root->left);
	}
	else {
		
		return GetSize(root->left) + root->cnt;
	}
}

int main() {

	int NumTestCases;
	cin >> NumTestCases;
	while (NumTestCases--) {
		int queries;
		cin >> queries;
		Node* root = nullptr;
		for (int i = 0; i < queries; i++) {
			int query; int x;
			cin >> query >> x;
			if (query == 1) { // 삽입
				root = Insert(root, x);
			}
			else if (query == 2) { // 삭제
				root = Delete(root, x);
			}
			else if (query == 3) { // k-th
				int ans = FindByOrder(root, x);
				if (ans == -1) cout << -1 << "\n";
				else cout << ans << "\n";
			}
			else if (query == 4) { // x 보다 작은 key 의 개수
				cout << OrderOfKey(root, x) << "\n";
			}
		}
		DestroySplayTree(root); root = nullptr;
	}
	return 0;
}