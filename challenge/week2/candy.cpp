#include <iostream>
using namespace std;

int main()
{ int money,candy ;
cout << "가지고있는 돈을 입력하세요";
cin >> money;
cout << "캔디의 가격을 입력하세요";
cin >> candy;

int max = money/candy;
int remain = money % candy;

cout << "현재가지고 있는 돈 :" << money << endl;
cout << "캔디의 가격 :" << candy << endl;
cout << "최대로 살 수 있는 캔디 :" << max << endl;
cout << "캔디 구입후 남은돈 :" << remain << endl;
return 0;


}