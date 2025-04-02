/*
N�� �ƴ°� �� ������ Ű��� ������
1. M��° ���ڸ� �����ϰ� �ִ� N�� ã�´�. : FindLength
2. N�� ã�Ҵٸ� �ش� ���ڿ��� M��° ���ڸ� ã�´� : FindChar
*/
#include<iostream>
using namespace std;
long long len[100];
int N = 1;
int M;

long long FindLength(int n) {
   if (n == 1)return 5;
   if (n == 2)return 13;
   if (len[n] != 0)return len[n];
   return len[n] = FindLength(n - 1) + FindLength(n - 2) + 1;  // ���� �� ���ڵ� �־��ֱ�
}

char FindChar(int n, long long M) {
   if (n == 1)return "Messi"[M - 1];
   if (n == 2)return "Messi Gimossi"[M - 1];

   long long len = FindLength(n - 1);
   if (M <= len) {
      return FindChar(n - 1, M);
   }
   else if (M == len + 1) {
      return ' ';
   }
   else {
      return FindChar(n - 2, M - len - 1);
   }
}

int main() {
   cin >> M;

   while (FindLength(N) < M)N++;

   char result = FindChar(N, M);

   if (result == ' ') {
      cout << "Messi Messi Gimossi";
   }
   else {
      cout << result;
   }

   return 0;
}