#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;

    for (int i = 0; i<floor; i++){
        for( int j = 0; j <= i; j++){
            cout << "S";
        }
        for (int k = 11-2*i; k>0; k--) {
            cout << "*";
        }
        cout << endl;//
    }
    return 0;
}