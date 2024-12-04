#include <iostream>
#include <stack>
using namespace std;
int main()
{
stack<string> st;
string sayings[3] =
{ "The grass is greener on the other side of the fence",
"Even the greatest make mistakes",
"To see is to believe" };
for (auto& s : sayings)
st.push(s);
while (!st.empty()) {
cout << st.top() << endl;
st.pop();
}
return 0;
}