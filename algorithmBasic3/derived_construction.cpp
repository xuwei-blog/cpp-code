#include <iostream>
using namespace std;
//派生类的构造函数
/*
1.创建派生类对象时，需要调用基类的构造函数，
来初始化基类的成员
2.先执行基类的构造函数，再执行派生类的构造函数
3.显式调用基类构造函数，
derived::derived(arg_derived-list):base(arg_base-list)
4.隐式调用基类构造函数，
在派生类的构造函数中，省略基类构造函数，自动调用基类默认的无参构造
5.基类没有无参构造，派生类 必须 显示调用基类构造函数
6.封闭派生类 对象构造函数执行顺序：
1）先执行基类的构造函数
2）再执行成员对象类的构造函数
3）最后执行派生类自己的构造函数
*/
class Bug{
    private:
        int nLegs;
        int nColor;
    public:
        int nType;
        Bug(int legs,int color);
        void PrintBug(){};
};
Bug::Bug(int legs,int color){
    nLegs = legs;
    nColor = color;
}

class FlyBug:public Bug{
        int nWings;
    public:
        FlyBug(int legs,int color,int wings);
};
/*错误的构造
FlyBug::FlyBug(int legs,int color,int wings){
    nLegs = legs;  //不能访问
    nColor = color;//不能访问
    nType = 1;     //ok
    nWings = wings;
}
*/
FlyBug::FlyBug(int legs,int color,int wings):Bug(legs,color){
    nWings = wings;
}

int main(){
    FlyBug fb(2,3,4);
    fb.PrintBug();
    fb.nType = 1;   
    //fb.nLegs = 2; //err

    system("pause");
    return 0;
}