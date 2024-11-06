#include <iostream>
#include <vector>  // 벡터를 사용하기 위한 헤더 파일
using namespace std;

class StudentGrades {
private:
    vector<double> scores;  // 성적을 저장할 벡터

public:
    // 성적을 입력하는 함수
    void addScore(double score) {
        scores.push_back(score);  // 벡터에 성적 추가
    }

    // 성적 평균을 계산하는 함수
    double calculateAverage() {
        if (scores.empty()) {
            cout << "성적이 입력되지 않았습니다." << endl;
            return 0.0;
        }

        double sum = 0;
        for (double score : scores) {
            sum += score;  // 성적 합계 계산
        }

        return sum / scores.size();  // 평균 반환
    }

    // 학생 수 반환 함수
    int getStudentCount() {
        return scores.size();  // 벡터의 크기가 학생 수
    }
};

int main() {
    StudentGrades studentGrades;  // StudentGrades 클래스의 객체 생성
    double score;
    char cont = 'y';  // 계속 입력받을지 여부를 묻기 위한 변수

    // 성적을 동적으로 입력받기
    while (cont == 'y' || cont == 'Y') {
        cout << "학생의 성적을 입력하세요: ";
        cin >> score;
        studentGrades.addScore(score);  // 클래스의 addScore 함수 호출

        cout << "다른 학생의 성적을 입력하시겠습니까? (y/n): ";
        cin >> cont;
    }

    // 입력된 학생 수와 평균 출력
    if (studentGrades.getStudentCount() > 0) {
        cout << "입력된 학생 수: " << studentGrades.getStudentCount() << endl;
        cout << "학생들의 평균 성적은: " << studentGrades.calculateAverage() << endl;
    } else {
        cout << "입력된 성적이 없습니다." << endl;
    }

    return 0;
}
