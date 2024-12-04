#include <iostream>
#include <deque>
using namespace std;
int main()
{
deque<int> dq = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
dq.pop_front(); // 앞에서 삭제
dq.push_back(11); // 끝에서 추가
for (auto& n : dq)
cout << n << " ";
cout << endl;
return 0;
}