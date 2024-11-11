#include <iostream>
#include <vector>
#include <string>  // 문자열을 사용하기 위한 헤더 파일
using namespace std;

// 영화 정보를 저장하기 위한 구조체
struct Movie {
    string name;   // 영화 이름
    double rating; // 영화 평점
};

int main() {
    vector<Movie> movies;  // Movie 구조체를 저장할 벡터
    string name;
    double rating;
    char cont = 'y';  // 영화 정보를 계속 입력할지 여부

    // 영화 정보를 동적으로 입력받기
    while (cont == 'y' || cont == 'Y') {
        cout << "영화 이름을 입력하세요: ";
        cin.ignore();  // 버퍼 비우기 (getline 사용 전에 필요)
        getline(cin, name);  // 영화 이름 입력

        cout << "영화 평점을 입력하세요 (0.0 ~ 10.0): ";
        cin >> rating;

        // 입력된 영화 정보를 구조체에 저장하고 벡터에 추가
        movies.push_back({name, rating});

        cout << "다른 영화를 입력하시겠습니까? (y/n): ";
        cin >> cont;
    }

    // 입력된 영화 정보 출력
    cout << "\n입력된 영화 목록:\n";
    for (const Movie& movie : movies) {
        cout << "영화: " << movie.name << ", 평점: " << movie.rating << endl;
    }

    return 0;
}


