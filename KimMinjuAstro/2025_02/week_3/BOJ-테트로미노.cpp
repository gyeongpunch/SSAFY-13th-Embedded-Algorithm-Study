#include<iostream>
#include<cstring>
#include<utility>
using namespace std;
int N, M;
int paper[501][501];
int sum = 0;
int maxSum = -21e8;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

// T�� ��� ���� dfs
void dfs(int y, int x, int level, int sum, int prevY, int prevX)
{
   if (level == 4) {
      maxSum = max(maxSum, sum);
      return;
   }

   for (int i = 0; i < 4; i++)
   {
      int dy = y + ydir[i];
      int dx = x + xdir[i];

      if (dy == prevY && dx == prevX)continue;
      if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;
      if (sum + paper[dy][dx] + (3 - level) * 1000 < maxSum)continue;   // ���� ���� �������� �ִ����� �����ص� ���� maxSum���� ������ ��Ʈ��ŷ
      dfs(dy, dx, level + 1, sum + paper[dy][dx], y, x);
   }
}

// T�� ��縸 ��������
void Tshape(int y, int x) {
   int sum = paper[y][x];
   int ydir[4][3] = {
      0,0,1,
      1,2,1,
      -1,0,0,
      1,1,2
   };
   int xdir[4][3] = {
      1,2,1,
      0,0,1,
      1,1,2,
      -1,0,0
   };
   int maxT = 0;
   for (int i = 0; i < 4; i++)
   {
      int totalSum = sum;
      for (int j = 0; j < 3; j++)
      {
         int dy = y + ydir[i][j];
         int dx = x + xdir[i][j];
         if (dy < 0 || dy >= N || dx < 0 || dx >= M)break;
         totalSum += paper[dy][dx];
      }
      maxT = max(maxT, totalSum);
   }
   maxSum = max(maxT, maxSum);
}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N >> M;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         cin >> paper[i][j];
      }
   }

   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         dfs(i, j, 1, paper[i][j], -1, -1);
         Tshape(i, j);
      }
   }
   cout << maxSum;
   return 0;
}