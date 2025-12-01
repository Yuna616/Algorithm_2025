#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		vector<int> bolts(N);
		unordered_map<int, int> nutTable;

		for (int i = 0; i < N; i++)
			cin >> bolts[i];

		int nut;
		for (int i = 0; i < N; i++)
		{
			cin >> nut;
			nutTable[nut] = i + 1;
		}

		for (int bolt : bolts)
			cout << nutTable[bolt] << " ";

		cout << "\n";
	}

	return 0;
}