#include <iostream>
using namespace std;

int main(){
    int a = 0;
    int b = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;
    
    char ch;

    while (cin>> ch){
        switch (ch)
        {
        case 'a' : case 'e' : case 'o': case 'i': case 'u':
            a++;
            break;
        
        default:
            b++;
        }
    }

    cout << "모음: " << a << endl;
    cout << "자음: " << b << endl;
    return 0;

 }


    