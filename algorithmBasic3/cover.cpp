#include <iostream>
using namespace std;
/*覆盖和保护成员
1.不要定义重名的成员变量
*/
class base
{
    int j;

public:
    int i;
    void func();
};
class derived : public base
{
public:
    int i; //覆盖
    void access();
    void func(); //覆盖
};
void derived::access()
{
    // j =5;  //err
    i = 5;        //派生类的i
    base::i = 5;  //基类的i
    func();       //派生类的func
    base::func(); //基类的func
}

/*保护成员
1.protected 只能在派生类(或基类、友元)的成员函数中访问
*/
class Father
{
private:
    int nPrivate;

public:
    int nPublic;

protected:
    int nProtected;
};
class Son : public Father
{
    void AccessFather()
    {
        nPublic = 1; // ok
        // nPrivate =1;  err
        nProtected = 1; // 可以访问从基类继承的protected成员
        Son f;
        f.nProtected = 1; // err f不是当前对象
    }
};
int main()
{
    Father f;
    Son s;
    f.nPublic = 1; // ok
    s.nPublic = 1; // ok
    // f.nProtected = 1;  err
    // f.nPrivate = 1;    err
    // s.nProtected = 1   err
    // s.nPrivate = 1     err
}