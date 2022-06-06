#include <iostream>
using namespace std;

/*cpp11 强制类型转换
- static_cast
    - 用来进行比较比较自然和低风险的转换，比如整型和实数型、字符型之间互相转换
    - 不能在不同类型的指针之间互相转换，也不能用于整型和指针之间的互相转换，也不能用于不同类型的引用之间的转换
- reinterpret_cast
    - 用来进行各种不同类型的指针之间的转换，不同类型的引用之间转换、以及指针和能容纳得下指针的整型类型之间的转换。
        转换的时候，执行的是逐个比特的拷贝
    
- const_cast
    - 用来去除const属性的转换。
    - 将const引用转换成同类型的非const引用，将const指针转换为同类型的非const指针时用它
    const string s = "abc";
    string & p = const_cast<string&>(s);
    string * ps = const_cast<string*>(&s); //&s 的类型是 const string*

- dynamic_cast 
    - 专门用于将多态基类的指针或引用，强制转换为派生类的指针或引用，而且能够检查转换的安全性。
        对于不安全的指针转换，转换结果返回NULL
    - 不能用于将非多态基类的指针或引用，强制转换为派生类的指针或引用
    - 包含虚函数的 叫 多态基类
    Derived & r = dynamic_cast<Derived&>(b); //不安全则抛出异常

*/




/*cpp11 强制类型转换 使用方法

- static_cast

class A{
public:
    operator int(){return 1;}  //重载类型转换 不写返回值
    operator char*(){return NULL;}
};
int main(){
    A a;
    int n;
    char* p = "New Dragon Inn";
    n = static_cast<int>(3.14);
    cout << n << endl;

    n = static_cast<int>(a);
    cout << n << endl;

    p = static_cast<char*>(a); //调用a.operator char*,p的值变为NULL
    //n = static_cast<int> (p);  //编译错误，static_cast不能将指针转换成整型
    //p = static_cast<char*>(n); //编译错误，static_cast不能将整型转换成指针
    system("pause");
    return 0;
}

- reinterpret_cast
    
class A{
    public:
        int i ;
        int j;
        A(int n):i(n),j(n){}
};
int main(){
    A a(100);
    int & r = reinterpret_cast<int&>(a); //强行让r引用a
    r = 200;                             //把a.i变成了200
    cout << a.i << "," << a.j << endl;   //200  100
    int n = 300;
    A* pa = reinterpret_cast<A*>(& n);   //强行让pa指向n
    pa->i = 400; //n变成400
    pa->j = 500; //不安全 越界了
    cout << n << endl;
    long long la = 0x12345678abcdLL;
    pa = reinterpret_cast<A*>(la); //la太长，只取低32位0x5678abcd拷贝给pa
    unsigned int u = reinterpret_cast<unsigned int>(pa); //pa逐个比特拷贝到u
    cout << hex << u << endl; //输出5678abcd
    typedef void(*PF1)(int);
    typedef int(*PF2)(int,char*);
    PF1 pf1;
    PF2 pf2;
    pf2 = reinterpret_cast<PF2>(pf1); //两个不同类型的函数指针之间可以互相转换

    system("pause");
    return 0;
}

- const_cast
    ...

- dynamic_cast 

#include <string>
class Base{
    public:
        virtual~Base(){}
};
class Derived:public Base{};
int main(){
    Base b;
    Derived d;
    Derived* pd;
    pd = reinterpret_cast<Derived*>(&b);
    if(pd == NULL)//reinterpret_cast不会检查安全性，总是进行转换
        cout << "unsafe reinterpret_cast" << endl;////不会执行
    pd = dynamic_cast<Derived*>(&b);//结果会是NULL，因为&b不是指向派生类对象，此转换不安全
    if(pd == NULL)
        cout << "unsafe dynamic_cast" << endl; //会执行
    Base*pb = &d;
    pd = dynamic_cast<Derived*>(pb); //安全的转换
    if(pd == NULL) //此处pd不会为NULL
        cout << "unsafe dynamic_cast2" << endl; //不会执行

    system("pause");
    return 0;
}
*/

