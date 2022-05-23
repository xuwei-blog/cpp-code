#include <iostream>
using namespace std;
/*虚函数：
class base{
    virtual int get();
};
int base::get(){}

1.成员函数+virtual关键字 就是 虚函数
2.virtual关键字只用在类定义里的函数声明中，函数体中不用加
3.构造函数和静态成员函数不能是虚函数
4.虚函数可以参与多态
*/

/*多态（2种表现形式）
1.派生类的指针可以赋给基类指针
2.基类指针调用虚函数时：
    1）基类指针指向一个基类对象时，基类的虚函数被调用
    2）基类指针指向一个派生类对象时，派生类的虚函数被调用
class CBase{
    public:
        virtual void SomeVirtualFunction(){};
};
class CDerived:public CBase{
    public:
        virtual void SomeVirtualFunction(){}
};
int main(){
    CDerived ODerived;
    CBase * p = & ODerived;
    p->SomeVirtualFunction();   //派生类的虚函数被调用

    system("pause");
    return 0;
}

3.派生类对象可以赋值给基类引用
4.基类引用调用虚函数时：
    1）引用的是一个基类对象时，基类的虚函数被调用
    2）引用的是一个派生类对象时，派生类的虚函数被调用
class CBase{
    public:
        virtual void SomeVirtualFunction(){};
};
class CDerived:public CBase{
    public:
        virtual void SomeVirtualFunction(){}
};
int main(){
    CDerived ODerived;
    CBase & r = ODerived;
    p.SomeVirtualFunction();  //派生类的虚函数被调用

    system("pause");
    return 0;
}
*/
class A
{
public:
    virtual void Print()
    {
        cout << "A" << endl;
    }
};
class B : public A
{
public:
    virtual void Print()
    {
        cout << "B" << endl;
    }
};
class D : public A
{
public:
    virtual void Print()
    {
        cout << "D" << endl;
    }
};
class E : public B
{
public:
    virtual void Print()
    {
        cout << "E" << endl;
    }
};

//多态的作用
//增强程序的可扩充性
int main()
{
    A a;
    B b;
    E e;
    D d;
    A *pa = &a;
    B *pb = &b;
    E *pe = &e;
    D *pd = &d;

    pa->Print();
    pa = pb;
    pa->Print();
    pa = pd;
    pa->Print();
    pa = pe;
    pa->Print();//调用间接派生类的虚函数
    
    system("pause");
    return 0;
}