#include <iostream>
using namespace std;
/*自增、自减运算符的重载
1.前置++作为一元运算符
2.前置++重载为成员函数，没有形式参数
3.前置++重载为全局函数，有一个形式参数
4.后置++作为二元运算符
5.后置++重载为成员函数，有一个形式参数
6.后置++重载为全局函数，有两个形式参数
7.前置运算符返回的是引用，(++a) = 1 ok
8.后置运算符返回的是临时变量，(a++) = 1 err
9.前置运算符效率高
10.运算符重载不改变运算符的优先级
11. ‘.’ ‘.*’ ‘::’ ‘?:’ ‘sizeof’ 不能重载
12.() [] -> = 只能重载为成员函数
*/
class CDemo{
    int n;
    public:
        CDemo(int i =0):n(i){}
        CDemo & operator++(); //前置
        CDemo operator++(int);//后置
        operator int(){return n;}
        friend CDemo & operator--(CDemo &); //前置
        friend CDemo operator--(CDemo &,int);//后置
};
CDemo & CDemo::operator++(){
    // 前置++
    ++n;
    return * this;
}// ++s <==> s.operator++()

CDemo CDemo::operator++(int k){
    //后置++
    CDemo tmp(*this); //记录修改前的对象
    n++;
    return tmp;//返回修改前的对象
} //s++ <==> s.operator++(0)

CDemo & operator--(CDemo & d){
    //前置--
    d.n--;
    return d;
} //--s <==> operator--(s)

CDemo operator--(CDemo & d,int){
    //后置--
    CDemo tmp(d);
    d.n--;
    return tmp;
} // s-- <==> operator--(s,0)

int main(){
    CDemo d(5);
    //++重载为成员函数，--重载为全局函数
    cout << (d++)<<" ,";//等价于 d.operator++(0);
    cout << d << " ,";  
    cout << (++d) << " ,"; //等价于 d.operator++();
    cout << d << " ,";
    cout << (d--)<<" ,";//等价于 operator--(d,0);
    cout << d << " ,";  
    cout << (--d) << " ,"; //等价于 operator++(d);
    cout << d << " ,";

    system("pause");
    return 0;
}