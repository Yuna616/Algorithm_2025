#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> result;

void preToPost(int l, int r)
{
	if (l > r)
		return;

	int root = v[l];
	int m = l + 1;
	while (m <= r && v[m] < root)
		m++;

	preToPost(l + 1, m - 1);
	preToPost(m, r);
	result.push_back(root);
}

void postToPre(int l, int r)
{
	if (l > r)
		return;

	int root = v[r];
	int m = l;
	while (m < r && v[m] < root)
		m++;

	result.push_back(root);
	postToPre(l, m - 1);
	postToPre(m, r - 1);
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		v.resize(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		result.clear();
		if (k == 1)
			preToPost(0, n - 1);
		else
			postToPre(0, n - 1);

		for (int i : result)
			cout << i << " ";
		cout << "\n";
	}

	return 0;
}