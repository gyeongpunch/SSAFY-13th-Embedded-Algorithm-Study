#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, L;
int map[101][101];
int ramp[101][101];
int cnt = 0;
void rowCheck(int line) {
	bool failFlag = false;

	for (int i = 0; i < N-1; i++)
	{
		int now = map[line][i];
		int next = map[line][i + 1];
		
		// �ٸ� ���� �߰�
		if (now != next) {

			// ���ΰ� 2�̻� ���� ���� �Ұ�
			if (abs(now - next) >= 2)failFlag = true;

			// �� ĭ �ö�
			else if (now - next == -1) {
				bool onRamp = true;

				if(ramp[line][i]==1)failFlag = true;
				// ���� ���� �� Ȯ��
				for (int j = 1; j < L; j++)
				{
					// ���� ��ŭ�� ���̰� �ִ������� Ȯ��
					if (i - j < 0) { failFlag = true; break; }

					// �̹� ���θ� ���� ���̸� �Ұ�
					if (ramp[line][i - j] == 1) { failFlag = true; break; }
					else {
						// ���� ���̸�ŭ�� ������ now ���̿� ���� ������ �Ұ�
						if (map[line][i - j] != now) { failFlag = true; 
						onRamp = false;
						break; }
					}
				}
				// ���� ���̸� �� Ȯ���ߴµ� ���θ� ���� �� �ִٸ�
				if (!failFlag&&onRamp) {
					for (int j = 0; j < L; j++)
					{
						// ���� ���� ������ ���
						ramp[line][i - j] = 1;
					}
				}
			}

			// �� ĭ ������
			else if (now - next == 1) {
				bool onRamp = true;
				for (int j = 1; j <= L; j++)
				{

					if (i + j >= N) { failFlag = true; break; }

					if (ramp[line][i + j] == 1) { failFlag = true; break; }
					else {
						if (map[line][i + j] != next) { failFlag = true; 
						onRamp = false;
						}
					}
				}
				if (!failFlag&&onRamp) {
					for (int j = 1; j <= L; j++)
					{
						ramp[line][i + j] = 1;
					}
				}
			}
		}
	}

	// �� ���� ������ �հ� �÷��׸� �� �����ٸ� �߰�
	if (!failFlag) {
		//cout << "rowCheck " << line << " ����" << "\n";
		cnt++;
	}
}

void colCheck(int line) {
	bool failFlag = false;
	for (int i = 0; i < N - 1; i++)
	{
		int now = map[i][line];
		int next = map[i + 1][line];

		// �ٸ� ���� �߰�
		if (now != next) {

			// ���ΰ� 2�̻� ���� ���� �Ұ�
			if (abs(now - next) >= 2)failFlag = true;

			// �� ĭ �ö�
			else if (now - next == -1) {
				if (ramp[i][line] == 1)failFlag = true;

				bool onRamp = true;
				// ���� ���� �� Ȯ��
				for (int j = 1; j < L; j++)
				{
					// ���� ��ŭ�� ���̰� �ִ������� Ȯ��
					if (i - j < 0) { failFlag = true; break; }

					// �̹� ���θ� ���� ���̸� �Ұ�
					if (ramp[i - j][line] == 1) { failFlag = true; break; }
					else {
						// ���� ���̸�ŭ�� ������ now ���̿� ���� ������ �Ұ�
						if (map[i - j][line] != now) { failFlag = true; 
						onRamp = false;
						break; }
					}
				}
				// ���� ���̸� �� Ȯ���ߴµ� ���θ� ���� �� �ִٸ�
				if (!failFlag&&onRamp) {
					for (int j = 0; j < L; j++)
					{
						// ���� ���� ������ ���
						ramp[i - j][line] = 1;
					}
				}
			}

			// �� ĭ ������
			else if (now - next == 1) {
				bool onRamp = true;
				for (int j = 1; j <= L; j++)
				{

					if (i + j >= N) { failFlag = true; break; }

					if (ramp[i + j][line] == 1) { failFlag = true; break; }
					else {
						if (map[i + j][line] != next) { failFlag = true;onRamp = false; }
					}
				}
				if (!failFlag&&onRamp) {
					for (int j = 1; j <= L; j++)
					{
						ramp[i + j][line] = 1;
					}
				}
			}
		}
	}

	// �� ���� ������ �հ� �÷��׸� �� �����ٸ� �߰�
	if (!failFlag) {
		//cout << "colCheck " << line << " ����" << "\n";
		cnt++;
	}
}
int main() {
	cin >> N >> L;	// L : ������ ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		rowCheck(i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// ���� üũ �迭 �ʱ�ȭ
			ramp[i][j] = 0;
		}
	}


	for (int j = 0; j < N; j++)
	{
		colCheck(j);
	}
	cout << cnt << "\n";


}
