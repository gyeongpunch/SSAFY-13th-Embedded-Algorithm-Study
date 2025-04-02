#include<iostream>
using namespace std;

int scoreDP[301] = {};    // index : n , value : n�� ��ܱ��� ���� ��� �� �ִ�
int stairs[301] = {};    // �� ��ܸ��� ����

int StairsUp(int n) {
   scoreDP[1] = stairs[1];
   scoreDP[2] = stairs[1] + stairs[2];
   scoreDP[3] = max(stairs[1], stairs[2]) + stairs[3];

   for (int i = 4; i <= n; i++)
   {
      // �� �ܰ� �������� �����ϰų�
      // �� �ܰ� ���� + ���� ��ܿ��� �����ϰų�
      scoreDP[i] = max(scoreDP[i - 2], scoreDP[i - 3] + stairs[i - 1]) + stairs[i];
   }
   return scoreDP[n];
}
int main() {
   int stairsCnt;
   cin >> stairsCnt;

   for (int i = 1; i <= stairsCnt; i++)
   {
      cin >> stairs[i]; // index�� �� ��� ��° 
   }
   cout << StairsUp(stairsCnt);
}