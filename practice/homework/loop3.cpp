#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int i ;
    int ans ;
    cout << "산수 문제를 자동으로 출력합니다" << endl;

    while(true) {
        int firstnum = rand() %100;
        int secondnum = rand() %100;

        cout << firstnum << '+' << secondnum << '=' ;
        cin >> ans;

        if (firstnum + secondnum == ans) {
            cout << "맞았습니다. " << endl;
            break;
        }
        else {
            cout << "틀렸습니다." << endl;
        }
    }
    return 0; 
}