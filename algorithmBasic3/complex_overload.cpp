#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//重载流插入、流提取
class Complex{
    double real,imag;
    public:
        Complex(double r =0,double i =0):real(r),imag(i){};
        friend ostream & operator<<(ostream & os,
                            const Complex & c);
        friend istream & operator>>(istream & is,Complex & c);
};
ostream & operator<<(ostream & os,const Complex & c){
    os << c.real <<"+"<<c.imag<<"i";//以a+bi的形式输出
    return os;
}
istream & operator>>(istream & is,Complex & c){
    //以a+bi的形式读入
    string s;
    is >> s;
    int pos = s.find("+",pos);
    string sTmp = s.substr(0,pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos+1,s.length()-pos-2);
    c.imag = atof(sTmp.c_str());
    return is;
}
int main(){
    Complex c1;
    cin >> c1;
    cout << c1 << "hello";

    system("pause");
    return 0;
}
