#include <iostream>
using namespace std;

class Rectangle{
    public:
    int width, height;
    int CalcArea(){
        return width*height;
    }
};
int main() {
    Rectangle obj;
    obj.width = 10;
    obj.height = 10;
    int area = obj.CalcArea();
cout << "사각형의 넒이: " << area << endl;
    return 0;
}