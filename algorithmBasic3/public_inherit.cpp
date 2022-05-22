#include <iostream>
using namespace std;
// class base
// {
// };
// class derived : public base
// {
// };
// base b;
// derived d;
/* public 继承的赋值兼容规则
1.派生类的对象可以赋值给基类对象 b = d
2.派生类的对象可以初始化基类的引用 base & br = d
3.派生类的对象的地址可以赋值给基类指针 base * pb = & d
4.概括来说 ： 大范围 = 小范围
*/

/*直接基类 间接基类
1.声明派生类时，只需要列出它的直接基类
*/
class Base
{ //爷类
public:
    int n;
    Base(int i) : n(i)
    {
        cout << "Base" << n << "constructed" << endl;
    }
    ~Base()
    {
        cout << "Base" << n << "destructed" << endl;
    }
};
class Derived : public Base
{ //父类
public:
    Derived(int i) : Base(i)
    {
        cout << " Derived" << n << "constructed" << endl;
    }
    ~Derived()
    {
        cout << "Derived" << n << "destructed" << endl;
    }
};
class morederived : public Derived
{ //子类
    morederived() : Derived(4)
    {
        cout << " morederived"
             << "constructed" << endl;
    }
    ~morederived()
    {
        cout << "morederived"
             << "destructed" << endl;
    }
};

int main()
{
    morederived Obj; //有问题 但是找不到问题在哪
    
    system("pause");
    return 0;
}