#include<iostream>
#include<algorithm>
using namespace std;
int ydir[] = { -1,0,1,0 };    // ��, ��, ��, �� ���⺤��
int xdir[] = { 0,1,0,-1 };
string go;
char map[101][101];
int n;
int minY = 101;
int maxY = 0;
int minX = 101;
int maxX = 0;

void Check(int y, int x) {    // �� ���� �ٿ���� üũ
	minY = min(minY, y);
	maxY = max(maxY, y);
	maxX = max(maxX, x);
	minX = min(minX, x);
}

void Move() {    // �����̰���
	int dirIdx = 2;    // ���ʺ���
	int y = 50, x = 50;    // �߾ӿ��� ����
	for (int i = 0; i < go.size(); i++)
	{
		if (go[i] == 'L') {    // �������� �����Ÿ�
			dirIdx -= 1;       // ���⺤�� �� ĭ ��
			if (dirIdx < 0)dirIdx = 3;
		}
		else if (go[i] == 'R') {    // ���������� �����Ÿ�
			dirIdx += 1;            // ���⺤�� �� ĭ ��
			if (dirIdx > 3)dirIdx = 0;
		}
		else {
			map[y][x] = '.';    // �̵��ߴٸ� �� ���
			Check(y, x);        // �ٿ���� üũ

			y += ydir[dirIdx];
			x += xdir[dirIdx];
			Check(y, x);
		}
	}
	map[y][x] = '.';
	Check(y, x);
}

int main() {
	cin >> n;

	cin >> go;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			map[i][j] = '_';	// '_'�� ���� �� ���� ����
		}
	}
	Move();
	for (int i = minY; i <= maxY; i++)    // �ٿ���� ��������
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (map[i][j] == '_')
				cout << "#";            // �� ���
			else
				cout << map[i][j];      // �̵��� �Ÿ� ���  
		}cout << "\n";
	}
}