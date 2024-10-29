#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // 난수 생성을 위한 시드 설정

    int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
    int firstNum;  // 정답의 첫 번째 자리수
    int secondNum; // 정답의 두 번째 자리수
    int thirdNum;  // 정답의 세 번째 자리수

    // 모든 자릿수가 다른 3자리 수 생성
    while (1) {        
        randomNum = rand() % 900 + 100; // 100~999 사이의 랜덤한 3자리 수 생성

        firstNum = randomNum / 100;         // 첫 번째 자리수
        secondNum = (randomNum / 10) % 10;  // 두 번째 자리수
        thirdNum = randomNum % 10;          // 세 번째 자리수

        // TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
        bool same = (firstNum != secondNum && firstNum != thirdNum && secondNum != thirdNum);

        if (same == true) {
            break;
        }
    }

    int turn = 0;
    while (1) {
        cout << turn + 1 << "번째 시도입니다. " << endl;

        int userNumber; // 사용자가 입력한 세자리수 저장 변수
        int guessFirst; // 추측한 숫자의 첫 번째 자리수
        int guessSecond; // 추측한 숫자의 두 번째 자리수
        int guessThird; // 추측한 숫자의 세 번째 자리수

        // 사용자에게 세자리 수를 입력받는 코드 블록
        while (1) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
            // TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
            guessFirst = userNumber / 100;
            guessSecond = (userNumber / 10) % 10;
            guessThird = userNumber % 10;

            // 입력한 숫자의 각 자릿수가 모두 다른지 확인
            same = (guessFirst != guessSecond && guessFirst != guessThird && guessSecond != guessThird);

            if (to_string(userNumber).length() != 3) {
                cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
                continue;
            }

            if (same == true) {
                break;
            } else {
                cout << "모든 자릿수가 다른 3자리 수를 입력해주세요." << endl;
            }
        }

        int strike = 0; // 스트라이크 갯수를 저장하는 변수
        int ball = 0;   // 볼 갯수를 저장하는 변수

        // TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
        if (guessFirst == firstNum) strike++;
        if (guessSecond == secondNum) strike++;
        if (guessThird == thirdNum) strike++;

        // 볼을 판별하기 위한 조건
        if (guessFirst == secondNum || guessFirst == thirdNum) ball++;
        if (guessSecond == firstNum || guessSecond == thirdNum) ball++;
        if (guessThird == firstNum || guessThird == secondNum) ball++;

        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << " 볼 입니다." << endl;

        if (strike == 3) {
            cout << "정답을 맞췄습니다. 축하합니다.";
            break;
        }

        turn += 1;
    }

    return 0;
}
