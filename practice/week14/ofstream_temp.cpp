#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream os{"temp.txt"};
    if(!os){
        cerr << "파일 오픈에 실패하였습니다."<<endl;
        exit(1);

    }
    for(int i=1;i<5;i++)
        os << i <<" "<<i+23.0<<endl;
        return 0;
}