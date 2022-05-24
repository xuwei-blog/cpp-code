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
5.类中有虚函数（包括父类），存储空间就会多一个指向 虚函数表 的指针
6.调用虚函数有时间开销，多态的代价就是时间开销。
*/
/*纯虚函数和抽象类
1.没有函数体的虚函数 叫做 纯虚函数
2.包含纯虚函数的类叫抽象类
3.抽象类只能作为基类来派生新类使用，不能 独立 创建抽象类的对象
4.抽象类的指针和引用可以指向由抽象类派生出来的类的对象
5.在抽象类的成员函数内可以调用纯虚函数（多态），但是在构造函数或析构函数内部不能调用纯虚函数
6.如果一个类从抽象类派生而来，那么当且仅当它实现了基类中的
所有纯虚函数，他才能成为非抽象类（把纯虚函数重载）

抽象类A
A a;            err
A * pa = new A; err
A * pa ;        ok

纯虚函数示例:
class A{
    public:
        virtual void f() = 0;  纯虚函数
        void g() {this->f();}   ok ，执行时this指向派生类的对象
        a() { f(); }            err  构造、析构调用 不是多态
};
class B:public A{
    public:
        void f() {cout<<"B:f()" <<endl;}
};
int main(){
    B b;
    b.g();  调用B的f()

    sysre
}

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