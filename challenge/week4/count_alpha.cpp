#include <iostream>
using namespace std;

int main() {
    int vowel = 0;      // 모음 개수
    int consonant = 0;  // 자음 개수
    char ch;           // 사용자 입력 저장 변수

    cout << "영문자를 입력하고 ctrl+z를 치세요:" << endl;

    while (cin >> ch) {
        switch (ch) {
            // 모음인 경우
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowel++;
                break;
            // 자음인 경우
            default:
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                    consonant++;
                }
                break;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}
