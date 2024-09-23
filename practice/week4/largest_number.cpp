#include <iostream>
using namespace std;

int main() 
{
    int a, b, c, largest ;

    cout << "3개의 정수를 입력하세요 :";
    cin >> a >> b >> c;

     if (a==b==c) {
      cout <<"3개의 정수가 모두 같습니다"<< endl;  
    largest = a;
    } // 3개의 정수가 모두 같다면 가장 큰 정수는 모두 같다. 

    else if (a>=b && a>=c)
    {largest = a;}

    else if (b>=a && b>=c)
    largest =b;
    else 
    largest = c;

    cout <<"가장 큰 정수는" << largest << endl;
    return 0;
}

