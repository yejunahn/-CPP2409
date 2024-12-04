#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
vector<int> data = { 1, 2, 3, 4, 5 };
reverse(data.begin(), data.end());
// reverse(data.end(), data.begin()); 에러, 탐사할 수 없음
for (int n : data) {
cout << n << ' ';
}
cout << '\n';
return 0;
}