#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
map<string, string> dic;
dic["boy"] = "소년";
dic["school"] = "학교";
dic["office"] = "직장";
dic["house"] = "집";
dic["morning"] = "아침";
dic["evening"] = "저녁";
string word;
while (true) {
cout << "단어를 입력하시오: ";
cin >> word;
if (word == "quit") break;
string meaning = dic[word];
if (meaning != "")
cout << word << "의 의미는 " << meaning << endl;
}
return 0;
}
