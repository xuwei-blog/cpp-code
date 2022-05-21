#include <iostream>
using namespace std;
/*运算符重载
1.运算符重载的实质是函数重载
2.可以重载为普通函数，也可以重载为成员函数
3.把含运算符的表达式转换成对运算符函数的调用
4.运算符的操作数转换成运算符函数的参数
5.运算符被多次重载时，根据实参类型决定调用哪个运算符函数
6.重载为成员函数时，参数个数为运算符目数减一
7.重载为普通函数时，参数个数为运算符目数
8.语法：
返回值类型 operator 运算符(形参表){
    ……
}
*/
class Complex{
    public:
        double real,imag;
        Complex(double r =0.0,double i = 0.0):real(r),imag(i){}
        Complex operator- (const Complex & c);
};
Complex operator+(const Complex & a , const Complex & b){
    return Complex(a.real + b.real,a.imag +b.imag);
}
Complex Complex::operator-(const Complex & c){
    return Complex(real -  c.real,imag - c.imag);
}
int main(){
    Complex a(4,4),b(1,1),c;
    c = a + b; //等价于 c = operator+(a,b);
    cout << c.real << "," <<c.imag<<endl;
    cout << (a-b).real << "," <<(a-b).imag<<endl;
    //等价于 a.operator-(b)
    system("pause");
    return 0;
}