#include<iostream>
#include<algorithm>
using namespace std;
int N, H;	// N : ������ ����
// H : ������ ����
int bottom[100001];
int top[100001];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

void input() {
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++)
	{
		cin >> bottom[i];
		cin >> top[i];
	}
}

int Crash(int num, int arr[]) {
	int left = 0;				// ���� ���� ����
	int right = N / 2 - 1;	// ���� ������ ����
	int mid;						// Ȯ���� ��

	while (left <= right) {	// �� ������ ���������� ����������
		mid = (left + right) / 2;	// �� ������ �߰����� Ȯ��

		if (arr[mid] < num)	// Ȯ���� ���� ��ǥ������ ������ ���������� �����ϴϱ�
			left = mid + 1;	// ���� ������ Ȯ���� �� ���������� ����ش�
		else
			right = mid - 1;
	}

	return N / 2 - left;	// �� �������� ������ �����ϴ� ó�� ���� �ε����� ���ָ� �׺��� ū ��ֹ����� ������ ���´� = �浹 ����
}

void solution() {
	sort(bottom, bottom + N / 2);
	sort(top, top + N / 2);

	int cnt = 0;
	int Min = 21e8;

	for (int i = 1; i <= H; i++)
	{
		int num = Crash(i, bottom) + Crash(H - i + 1, top);	// �浹 ���� ����
		if (num < Min) {	// ��������� ��ֹ� �������� ������ ������Ʈ
			cnt = 1;
			Min = num;
		}
		else if (num == Min) {	// �ƴϸ� ī��Ʈ �߰�
			cnt++;
		}
	}

	cout << Min << " " << cnt;
}

int main() {
	init();
	input();
	solution();

}