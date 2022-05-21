#include <iostream>
#include <cstring>
using namespace std;
/*运算符重载为友元函数
1.一般情况，将运算符重载为类的成员函数
2.重载为成员函数不能满足使用要求，重载为
普通函数，不能访问私有成员，
所以需要将运算符重载为友元
c = c + 5； <==> c = c.operator(5)
c = 5 + c;  <==> c = 5.operator(c) err
*/
class Complex{
    double real,imag;
    public:
        Complex(double r,double i):real(r),imag(i){};
        Complex operator+(double r);
        friend Complex operator+(double r,const Complex & c);
};
Complex Complex::operator+(double r){
    //使得 c+5 成立
    return Complex(real + r,imag);
}
Complex operator+(double r,const Complex & c){
    //使得 5 + c 成立
    return Complex(c.real + r,c.imag);
}
