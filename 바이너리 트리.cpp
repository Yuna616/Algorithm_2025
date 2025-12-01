#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* buildTree() {
    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');
    Node* F = createNode('F');
    Node* G = createNode('G');

    A->left = B;
    A->right = C;
    B->left = D;
    D->right = G;
    C->left = E;
    C->right = F;

    return A;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void order(Node* root) {
    if (!root) return;

    order(root->left);
    cout << root->data << " ";
    order(root->right);
    cout << root->data << " ";

}




int main() {
    Node* root = buildTree();

    

    /*cout << "Inorder  : ";
    inorder(root);
    cout << "\n";

    cout << "Preorder : ";
    preorder(root);
    cout << "\n";

    cout << "Postorder: ";
    postorder(root);
    cout << "\n";*/

    cout << "order  : ";
    order(root);
    cout << "\n";

    return 0;
}
