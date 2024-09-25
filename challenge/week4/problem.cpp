#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(NULL)); // 랜덤 함수 초기화
    int ans;           // 정답 저장 변수

    cout << "산수 문제를 자동으로 출제합니다." << endl;

    while (true) {
        int firstNum = rand() % 100;  // 첫 번째 숫자
        int secondNum = rand() % 100; // 두 번째 숫자
        ans = firstNum + secondNum;    // 정답 계산

        cout << firstNum << " + " << secondNum << " = ? " << endl;

        int userAnswer; // 사용자 입력 저장 변수
        cout << "답을 입력하세요: ";
        cin >> userAnswer; // 사용자 입력 받기

        // 정답 평가
        if (userAnswer == ans) {
            cout << "정답입니다!" << endl;
        } else {
            cout << "틀렸습니다. 정답은 " << ans << "입니다." << endl;
        }

        char continueGame; // 게임 계속 여부
        cout << "계속 하시겠습니까? (y/n): ";
        cin >> continueGame;
        if (continueGame != 'y' && continueGame != 'Y') {
            break; // 'y' 또는 'Y'가 아닐 경우 종료
        }
    }

    return 0;
}


