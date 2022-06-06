#include <iostream>
#include <string>
using namespace std;
/*异常处理
- 程序运行中难免发生错误
    - 数组元素的下标超界、访问NULL指针
    - 除数为0
    - 动态内存分配new需要的存储空间太大
    ...
- 引起这些异常的情况
    - 代码质量不高，存在BUG
    - 输入数据不符合要求
    - 程序的算法设计时考虑不周到
    ...
- 我们总是希望在发生异常情况时
    - 不只是简单地终止程序运行
    - 能够反馈异常情况地信息：哪一行代码发生的、什么异常
    - 能够对程序运行中已发生的事情做些处理：取消对输入文件的改动、释放已经申请的系统资源
- 通常的做法（不合理）
    - 在可能发生异常的地方进行if判断
    - 由函数本身处理异常
- 正确的手段
    - 把异常和函数的接口分开，并且能够区分不同的异常
    - 在函数体外捕获所发生的异常，并提供更多的异常信息

//基本用法
int main(){
    double m,n;
    cin >> m  >> n;
    try{
        cout << "before dividing" <<endl;
        if(n == 0)
            throw -1; //抛出int类型异常
        else if(m == 0){
            throw -1.0; //抛出double类型异常
        }
        else 
            cout << m / n << endl;
        cout << "after dividing" << endl;
    }
    catch(double d){
        cout << "catch(double)" << d << endl;
    }
    catch(int e){
        cout << "catch(int)" << e << endl;
    }
    catch(...){ //可以处理任何类型的异常
        cout << "catch(...)" << endl;
    }
    cout << "finished" <<endl;
    system("pause");
    return 0;
}

//进阶用法
class CException{
    public:
        string msg;
        CException(string s):msg(s){}
};
double Devide(double x,double y){
    if(y == 0)
        throw CException("devided by zero");
    cout << "in devide" << endl;
    return x / y;
}
int CountTax(int salary){
    try{
        if(salary < 0)
            throw -1;
        cout << "counting tax" << endl;
    }
    catch(int){
        cout << "salary < 0 " << endl;
    }
    cout << "tax counted" << endl;
    return salary*0.15;
}

int main(){
    double f = 1.2;
    try{
        CountTax(-1); // 异常处理掉了 程序继续执行
        f = Devide(3,0);  //出现异常 没有处理 跳出try 
        cout << "end of try block" << endl; //不执行
    }
    catch(CException e){
        cout << e.msg << endl;
    }

    cout << "f=" << f << endl;  //f还是1.2
    cout << "finished" << endl;

    system("pause");
    return 0;
}

*/


/*cpp标准异常类

- 头文件 <stdexcept>

- cpp标准库中有一些类代表异常，这些类都是从exception类派生而来。常用的几个异常类如下：
    - bad_typeid
    - bad_cast
        - 在用dynamic_cast进行从多态基类对象(或引用),到派生类的引用的强制类型转换时，
            如果转换是不安全的，则会抛出此异常

    - bad_alloc
        - 不能分配空间时抛出
    - ios_base::failure
    - logic_error  =>  out_of_range  
        - 用vector或string的at成员函数根据下标访问元素时，如果下标越界，就会抛出此异常

*/


/*bad_cast
class Base{
    virtual void func(){}
};
class Derived:public Base{
    public:
        void Print(){}
};
void PrintObj(Base & b){
    try{
        Derived & rd = dynamic_cast<Derived&>(b); //转换不安全，则抛出bad_cast异常
        rd.Print();
    }
    catch(bad_cast& e){
        cerr << e.what() << endl; //what成员函数 返回字符串 说明发生什么事
    }
}
int main(){
    Base b;
    PrintObj(b);
    system("pause");
    return 0;
}
*/

/*bad_alloc
int main(){
    try{
        char* p = new char[0x7fffffffffff]; //无法分配那么多空间，会抛出异常
    }
    catch(bad_alloc&e){
        cerr << e.what() << endl;
    }
    system("pause");
    return 0;
}
*/

/*out_of_range

*/
#include <vector>
int main(){
    vector<int> v(10);
    try{ //at会检查下标越界 []不检查
        v.at(100) = 100;  //抛出out_of_range异常
    }
    catch(out_of_range&e){
        cerr<< e.what() << endl;
    }
    string s = "hello";
    try{
        char c = s.at(100); //抛出out_of_range异常
    }
    catch(out_of_range&e){
        cerr << e.what() << endl;
    }
    system("pause");
    return 0;

}