#include <iostream>
#include <vector>

using namespace std;

// Merge 함수: 두 개의 정렬된 부분 배열을 병합
void Merge(vector<int>& A, int l, int m, int h) {
    // 두 부분 배열의 크기를 계산
    int n1 = m - l + 1;
    int n2 = h - m;

    // 두 부분 배열을 위한 임시 배열 생성
    vector<int> L(n1), R(n2);

    // 임시 배열에 값 복사
    for (int i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[m + 1 + j];
    }

    // 병합 과정
    int i = 0, j = 0, k = l; // i는 L 배열의 인덱스, j는 R 배열의 인덱스, k는 병합된 배열 A의 인덱스
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // L 배열의 남은 요소 처리
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // R 배열의 남은 요소 처리
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort 함수: 배열의 부분을 정렬
void MS(vector<int>& A, int l, int h) {
    if (l < h) {
        int m = l + (h - l) / 2;

        // 배열의 앞쪽 절반 정렬
        MS(A, l, m);
        // 배열의 뒤쪽 절반 정렬
        MS(A, m + 1, h);
        // 두 정렬된 부분 병합
        Merge(A, l, m, h);
    }
}

int main() {
    // 정수 배열
    vector<int> A = {3, 2, 5, 7, 4, 8, 6, 9, 1};

    // 배열 정렬 전 출력
    cout << "정렬 전 배열: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Merge Sort 호출
    MS(A, 0, A.size() - 1);

    // 배열 정렬 후 출력
    cout << "정렬 후 배열: ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
