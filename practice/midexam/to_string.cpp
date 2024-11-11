#include <iostream>
using namespace std;

int main()
{
    int num = 72;
    string numStr = to_string(num);
    cout << numStr << endl;
    cout << numStr[0] << " " << numStr[1] << endl;

    int firstNum = (int)numStr[0];
    cout << firstNum;

    return 0;
}