#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string name[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람" << i + 1 << "의 이름: ";
        cin >> name[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    while(1){

    
    cout << "메뉴 번호(1~3)을 선택하세요: ";
    int select;
    cin >> select;
    
    if (select==1) {
        int max_number = ages[0]; // 첫 번째 사람의 나이로 초기화
        for (int i = 1; i < maxPeople; i++) {
            if (ages[i] > max_number) { // 나이를 비교하여 최대값 업데이트
                max_number = ages[i];
            }
        for (int i =0; i<maxPeople; i++){
            if(ages[i] == max_number){
                 cout << "가장 나이가 많은 사람은 " << name[i] << "입니다.";
            }
        }
        }
       
        break;
    }
    else if (select == 2) {
        string min_person = name[0]; // 첫 번째 사람의 이름으로 초기화
        int min_number = ages[0]; // 첫 번째 사람의 나이로 초기화
        for (int i = 1; i < maxPeople; i++) {
            if (ages[i] < min_number) { // 나이를 비교하여 최소값 업데이트
                min_number = ages[i];
                min_person = name[i];
            }
        }
        cout << "가장 나이가 적은 사람은 " << min_person << "입니다." << endl;
        break;
    }
    else if (select == 3){}
        cout << "종료합니다." << endl;
        break;
    }
    else if  {
        cout << "잘못된 입력입니다." << endl;
        break;
    }

    return 0;
}
