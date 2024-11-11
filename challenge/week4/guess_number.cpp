#include <iostream>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL)); // random 함수 초기화
    int answer = rand() % 100; // 정답
    int tries = 0; // 시도 횟수
    int guess; // 사용자 입력 저장 변수

    cout << "0부터 99 사이의 정수를 맞추세요!" << endl;

    
    do {
        cout << "입력하세요: ";
        cin >> guess; // 사용자 입력

        tries++; // 시도 횟수 증가

        if (guess > answer) {
            cout << "너무 높습니다!" << endl;
        } else if (guess < answer) {
            cout << "너무 낮습니다!" << endl;
        } else {
            cout << "축하합니다! 정답입니다." << endl;
            cout << "시도 횟수: " << tries << endl;
        }
    } while (guess != answer); // 정답을 맞출 때까지 반복

    return 0;
}
