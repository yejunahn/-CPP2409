#include <iostream>
using namespace std;

int main() {
    const int Students = 5;
    int scores[Students];
    int sum = 0;
    int i, average;

    for (i=0; i<Students; i++){
        cout<<"학생들의 성적을 입력하시오:";
        cin >> scores[i];

    }
    for (i=0; i<Students; i++)
        sum += scores[i];
    
    average = sum/Students;
    cout << "성적 평균= " << average << endl;

    return 0;//
}