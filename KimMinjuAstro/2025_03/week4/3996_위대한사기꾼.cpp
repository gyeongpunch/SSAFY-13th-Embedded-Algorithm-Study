///*
//n�� ¦�� �����鸸 �̾Ƽ� ����� ���� ������
//*/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//long long n;    // üũ�ؾ��� ����
//int k;            // k����
//int digit;        // n���� �����ϴµ� �ʿ��� �ڸ���
//int digitArr[1000];// digit-1 ������ ������ȯ��
//int cases;
//int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   cin >> n >> k;
//
//   // digit ���, digitArr�� k�������� ��ȯ�� �� �ֱ�
//   while (1) {
//      if (n / k > 0) {
//         digitArr[digit] = n % k;
//         digit++;
//         n /= k;
//      }
//      else {
//         digitArr[digit] = n;
//         digit++;
//         break;
//      }
//   }
//   // ����ϱ� ���� �������� ����
//   reverse(digitArr, digitArr + digit);
//
//   // n���� �۰ų� ���� �ִ����� ����
//   bool isChanging = false;
//   if (digit % 2 == 1) {
//      for (int i = 0; i < digit; i++)
//      {
//         if (isChanging && (i % 2 == 0)) {
//            digitArr[i] = k - 1;
//         }
//         if (i % 2 == 1) {
//            if (digitArr[i] > 0) {
//               digitArr[i] = 0;
//               isChanging = true;
//            }
//         }
//      }
//   }
//   else {
//      for (int i = 0; i < digit; i++)
//      {
//         if (isChanging && (i % 2 == 1)) {
//            digitArr[i] = k - 1;
//         }
//         if (i % 2 == 0) {
//            if (digitArr[i] > 0) {
//               digitArr[i] = 0;
//               isChanging = true;
//            }
//         }
//      }
//   }
//
//
//   int power = (digit % 2 == 0) ? digit / 2 - 1 : digit / 2;
//   if (digit % 2 == 1) {
//      for (int i = 0; i < digit; i++) {
//         if (i % 2 == 0) {
//            cases += digitArr[i] * (int)(pow(k, power));
//            power--;
//         }
//      }
//   }
//   else {
//      for (int i = 0; i < digit; i++) {
//         if (i % 2 == 1) {
//            cases += digitArr[i] * (int)(pow(k, power));
//            power--;
//         }
//      }
//   }
//
//
//   cout << int(cases + 1);
//   return 0;
//}