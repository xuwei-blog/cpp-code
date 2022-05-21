#include <iostream>
using namespace std;
//类型转换运算符的重载
class Complex{
    double real,imag;
    public:
        Complex(double r =0,double i =0):real(r),imag(i){};
        operator double(){return real;}
        //重载强制类型转换运算符double
        //类型运算符重载 返回值不写 使得类型就是()前的类型
        //double本来是单目运算符 重载之后没形式参数
};
int main(){
    Complex c(1.2,3.4);
    cout << (double)c << endl;//输出 1.2
    double n =2 + c; //等价于 double n = 2+c.operator double()
    cout << n;   //输出  3.2
    system("pause");
    return 0;
}