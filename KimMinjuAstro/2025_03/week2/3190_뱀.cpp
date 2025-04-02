#include <iostream>
#include <queue>
using namespace std;

int N, K, L; // N : ���� ũ��, K : ��� ����, L : ���� ��ȯ Ƚ��
int board[101][101]; // 0: �� ĭ, 1: ���, 2: ��
int ydir[] = { -1, 0, 1, 0 };
int xdir[] = { 0, 1, 0, -1 };
int curDir = 1; // ó�� ����: ������
int curY = 1, curX = 1; // ���� �ʱ� ��ġ
int cnt = 0; // ���� ���� �ð�
queue<pair<int, int>> snake; // ���� ��ġ (���� -> �Ӹ� ����)

struct Turn {
   int time;
   char direction;
};

queue<Turn> turns; // ���� ��ȯ ����

void GoStraightAnd() {
   while (true) {
      cnt++;

      int ny = curY + ydir[curDir];
      int nx = curX + xdir[curDir];

      // �� or �ڱ� �ڽŰ� �ε����� ����
      if (ny < 1 || ny > N || nx < 1 || nx > N || board[ny][nx] == 2) {
         cout << cnt << "\n";
         return;
      }

      // ����� �ִ� ���
      if (board[ny][nx] == 1) {
         board[ny][nx] = 2;
         snake.push({ ny, nx });
      }

      // ����� ���� ���
      else {
         board[ny][nx] = 2;
         snake.push({ ny, nx });

         // ���� ����
         int tailY = snake.front().first;
         int tailX = snake.front().second;
         snake.pop();
         board[tailY][tailX] = 0;
      }

      curY = ny;
      curX = nx;

      if (!turns.empty() && turns.front().time == cnt) {
         char c = turns.front().direction;
         turns.pop();
         if (c == 'D') {
            curDir = (curDir + 1) % 4; // ������ ȸ��
         }
         else {
            curDir = (curDir + 3) % 4; // ���� ȸ��
         }
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> K;

   for (int i = 0; i < K; i++) {
      int y, x;
      cin >> y >> x;
      board[y][x] = 1;
   }

   cin >> L;
   for (int i = 0; i < L; i++) {
      int t;
      char dir;
      cin >> t >> dir;
      turns.push({ t, dir });
   }

   board[1][1] = 2;
   snake.push({ 1, 1 });

   GoStraightAnd();

   return 0;
}
