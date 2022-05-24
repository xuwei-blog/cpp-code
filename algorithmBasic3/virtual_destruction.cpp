#include <iostream>
using namespace std;
/*虚析构函数：
1.通过基类的指针删除派生类对象时，通常情况下只调用基类的析构函数
2.基类的虚析构virtual声明后。派生类的析构函数，也变成虚析构
3.通过基类指针删除派生类对象时，先调用派生类的析构函数，再调用基类的析构函数
4.一个类定义了虚函数，应该将析构函数也定义成虚函数
5.一个类作为基类使用，应该将析构函数定义成虚函数
6.虚析构的作用是：方便用基类指针delete派生类对象
7.构造函数不能是虚函数
*/
class son{
    public:
        //虚析构delete时，先调用派生类，再基类
        //~son(){cout<<"bye from son"<<endl;}
        virtual ~son(){cout<<"bye from son"<<endl;}
};
class grandson:public son{
    public:
        ~grandson(){cout<<"bye from grandson"<<endl;}
};
int main(){
    son *pson;
    pson = new grandson();
    delete pson;
    system("pause");
    return 0;
}