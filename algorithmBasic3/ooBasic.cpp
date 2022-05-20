#include <iostream>
using namespace std;

class Complex
{
private: //缺省默认private
    int real;
    int imag;

public: //可以先类内声明，类外实现
    // Complex();
    Complex(int r, int i); //可以设置默认缺省值
    Complex(int r);
    Complex()//默认调用 无参构造，只要重载构造函数就不会再调用
    {
        real = 200;
        imag = 200;
    }
    int getReal()
    {
        return this->real;
    }
    int getImag()
    {
        return (*this).imag;
    }

protected:
    //暂时不知道可以放啥
};
//类外实现
Complex::Complex(int r, int i)
{
    real = r;
    imag = i;
}
Complex::Complex(int r)
{
    real = r;
    imag = 100;
}

void 创建对象()
{
    //基础
    Complex c1;
    Complex c2(2);
    Complex c3(2, 4);
    Complex *pc1 = new Complex;
    Complex *pc2 = new Complex(2);
    Complex *pc3 = new Complex(3, 4);
    delete pc1;
    delete pc2;
    delete pc3;
    //进阶
    Complex arr1[2];         //两个对象都无参构造
    Complex arr2[2] = {1, 2}; // arr2 arr3 arr4 等价
    Complex arr3[2] = {{1}, {2}};
    Complex arr4[3] = {Complex(1), Complex(2)};
    Complex arr5[2] = {{1, 2}};         //给第一个对象2个参数，第二个无参构造
    Complex arr6[2] = {{1, 2}, {3, 4}}; //两个有参构造
    Complex arr7[3] = {Complex(2, 3), Complex(2), 3};
    Complex arr8[4] = {Complex(2, 3), 3, Complex(2)};//2 3 3 100 2 100 200 200
    //高端
    Complex *arr11 = new Complex[2];//两个无参 类似数组 感觉有点问题
    Complex *arr12 = new Complex; 
    Complex *arr13[3] = {new Complex(2), new Complex(2, 3)}; //就创建了两个对象
    delete[] arr11;
    delete[] arr12;
    delete[] arr13;

    //测试代码
    cout << arr1[0].getReal() << endl;
    cout << arr1[0].getImag() << endl;
    cout << arr1[1].getReal() << endl;
    cout << arr1[1].getImag() << endl;
    cout << arr1[2].getReal() << endl;
    cout << arr1[2].getImag() << endl;
    cout << arr1[3].getReal() << endl;
    cout << arr1[3].getImag() << endl;

    cout << arr11->getReal() << endl;
    cout << arr11->getImag() << endl;
    cout << (arr11+1)->getReal() << endl;
    cout << (arr11+1)->getImag() << endl;
}

class A{
    
    public:
        double a,b;

        A(){}
        A(const A & copy){//复制构造 参数必须是引用
            a = copy.a;   
            b = copy.b;
        }

};
void 复制构造(){
    A a1;     //无参构造
    A a2(a1); //缺省的复制构造 a2变成a1的复制品
              //复制构造肯定存在
    A a3 = a1;//初始化语句 非赋值语句 与上面等价
    A a4;
    a4 = a1;  //没有调用复制构造 只是赋值
}

void Func1(A a1){}
void 用复制构造初始化(){
    A a2;
    Func1(a2); //形参a1被初始化 此时用到了 复制构造
}

A Func2(){
    A b;
    return b;//b是复制构造的参数
}
void 复制构造的返回值(){
    cout<<Func2().a;
}
//总结：复制构造的开销大，建议使用引用传参，最好可以加上const

//类型转换构造函数
class Complex{
    public:
        double real,imag;
        Complex (int i){//类型转换构造函数
            real = i;
            imag = 0;
        }
        Complex (double r,double i){
            real = r;
            imag = i;
        }
};   
void 类型转换构造函数(){
    Complex c1(7,8);//双参数构造函数
    Complex c2 = 12;//单参数构造函数
    c1 = 9; //9被自动转换成一个临时Complex对象
}

//析构函数
//只能有一个析构函数
//对象的生命周期结束才会调用
class String {
    private:
        char * p;
    public:
        String (){
            p = new char[10];
        }
        ~String (); //析构函数
};
String :: ~String (){
    delete [] p;
}
void 析构函数的调用(){
    String * s;
    s = new String;//构造函数调用
    delete s;//析构函数调用
    s = new String[3];//构造函数调用3次
    delete [] s;//析构函数调用3次
}
//形参对象，等号右值临时对象，对象的消亡
class CMyclass{
    public:
    ~CMyclass(){
        cout<<"destructor"<<endl;
    }
};
CMyclass fun(CMyclass sobj){
    return sobj;//形参消亡一次
}
void 析构函数调用几次？(){
    CMyclass obj;
    obj = fun(obj);//右值消亡一次
    return;
} //return结束一次

//析构函数一共调用3次






int main()
{
    system("pause");
    return 0;
}