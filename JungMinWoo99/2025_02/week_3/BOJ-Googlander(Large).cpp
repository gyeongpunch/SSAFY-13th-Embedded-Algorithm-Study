#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define endl '\n'

constexpr int MAX_R = 25;
constexpr int MAX_C = 25;
using namespace std;
using ll = long long;

/*
DP[i][l] = i * l ũ���� ���븦 ���� �� �ִ� ����� ��
i * l ũ���� ���븦 ���� �� k��° ĭ���� ó�� ȸ���ߴٸ� ȸ���� ���� ���븦 �ɿ� �� �ִ� ����� ���� l-1 * k ũ���� ���븦 ���� �� �ִ� ����� ���� ����
	=> DP[i][l] = sum(DP[l-1][k]+ ... + DP[l][k])
*/

class Walk
{
public:
	Walk(int r = MAX_R, int c = MAX_C) :DP(r + 1, vector<ll>(c + 1, 0)), row(r), col(c)
	{
		for (int i = 0;i < col;i++)
		{
			DP[1][i] = 1;
		}

		for (int i = 0;i < row;i++)
		{
			DP[i][1] = 1;
		}
	}

	ll recursion(int y, int x)
	{
		if (DP[y][x] != 0)
			return DP[y][x];

		DP[y][x] = 0;
		for (int i = 1;i <= y;i++)
			DP[y][x] += recursion(x - 1, i);

		return DP[y][x];
	}
private:
	int row, col;
	vector<vector<ll>> DP;
};

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	Walk walk;
	walk.recursion(MAX_R, MAX_C);
	int T;
	cin >> T;
	for (int tc = 1;tc <= T;tc++)
	{
		int r, c;
		cin >> r >> c;
		cout << "Case #" << tc << ": " << walk.recursion(r, c) << endl;
	}

	return 0;
}