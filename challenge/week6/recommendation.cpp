#include <iostream>
using namespace std;
    const int NUM_USERS = 3;
    const int NUM_ITEMS = 3;
    int userPreferences[NUM_USERS][NUM_ITEMS];
void initializePreference(int preferences[NUM_USERS][NUM_ITEMS]){

    for(int i =0; i < NUM_USERS; ++i){
        cout << "사용자" << (i + 1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";
        for(int j =0; j < NUM_ITEMS; ++j){
            cin >> preferences[i][j];
        }
    }
}
void findRecommendeditems(const int preferences[NUM_USERS][NUM_ITEMS]){
    for(int i =0; i < NUM_USERS; ++i){
        int maxPreferenceindex = 0;
        for(int j = 1; j < NUM_ITEMS; ++j){
            if (preferences[i][j] > preferences[i][maxPreferenceindex]){
                maxPreferenceindex = j;
            }
        }
    cout << "사용자 " << (i+1) << "에게 추천하는 항목:";
    cout << (maxPreferenceindex + 1) << std::endl;    
    }
}