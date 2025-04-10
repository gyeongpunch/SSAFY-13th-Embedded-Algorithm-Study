#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int K;

// ���� �̵� �Լ�
void HanoiTop(int n, int start, int mid, int end) {
	if (n == 1) {
		cout << start << " " << end << "\n";
	}
	else
	{
		// n-1���� ������ ó������ ���� ���� �߰��� ����
		HanoiTop(n - 1, start, end, mid);

		// ���� �Ʒ����� ������ ���� ���´�
		cout << start << " " << end << "\n";

		// �߰��� ���� n-1���� ������ ó���� ���� ���� ���´�
		HanoiTop(n - 1, mid, start, end);
	}
}

int main() {
	cin >> K;
	// int�� �������� ���� ����. ���� �̻���
	cout << (int)(pow(2, K) - 1) << "\n";
	HanoiTop(K, 1, 2, 3);
}
