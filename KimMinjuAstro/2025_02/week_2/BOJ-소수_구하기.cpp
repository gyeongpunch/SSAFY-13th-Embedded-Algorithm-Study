#include <iostream>
using namespace std;

int main()
{
	int start, end;
	cin >> start >> end;

	// i : �Ҽ����� �Ǻ��Ϸ��� ��
	for (int i = start; i <= end; ++i)
	{
		int flag = 0;
		// j : ������� �Ǻ�
		for (int j = 2; j * j <= i; ++j)
		{
			if (i % j == 0)
			{
				flag = 1; // �ռ���
				break;
			}
		}
		// 1 ����
		if (i != 1)
		{
			if (flag == 0)	// �Ҽ�
			{
				cout << i << "\n";
			}
		}
	}

	return 0;
}