#include <iostream>
using namespace std;
/*常引用最主要的作用：
对象作为函数的参数时，生成该参数需要调用复制构造函数，
效率比较低。用指针作为参数，代码不简洁、美观。
此时就可以用常引用
*/
void 引用(){
    int n = 4;
    int & r = n;
    r = 5;
    cout<<n; //5
    //引用定义时必须初始化
    //相当于给n一个别名r
    //后续不能改变引用的目标变量
    //只能引用变量，不能引用常量或者表达式
    //可以引用（引用变量），再取一个别名
    //函数返回值为引用可以作为等号左值
    //定义引用时，前面加const，常引用
    int a =10;
    const int & b = a;//b为常引用
    //b = 20; error 
    //a = 20; ok
}
void 常量(){
    const int MAX =100;//整型常量
    const double Pi =3.14;//浮点型常量
    const char* ANIMAL = "dog cat";
}
void 常量指针1(){
    int n,m;
    const int* p = &n;
    //*p = 5;  error 不能通过*p修改
    n = 4;//通过其他途径修改
    p = &m;//可以指向其他变量
}
void 常量指针2(){
    const int*p1;
    int*p2;
    p1 = p2;//ok
    //p2 = p1; error 不能把 常量指针 赋值到 非常量指针
                            //反之可以
    p2 = (int*)p1;//ok   强制类型转换 也可以
}