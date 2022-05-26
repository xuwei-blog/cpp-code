#include <iostream>
using namespace std;


//使用模板的程序设计 就是 泛型编程

/*函数模板类模板
编译器通过模板生成函数的过程 称为 模板的实例化

函数模板：
template <class 类型参数1，class 类型参数2, ...>
返回值类型 模板名(形参表){
    函数体
};

//模板用法示例
template <class T>
void Swap(T & x,T & y){
    T tmp = x;
    x = y;
    y = tmp;
}
int main(){
    int n = 1;
    int m = 2;
    Swap(n,m);    //编译器自动生成void Swap(int &,int &)
    double f = 1.2 , g = 2.3;
    Swap(f,g);    //编译器自动生成void Swap(double &,double &)

    system("pause");
    return 0;
}

//求数组最大元素的MaxElement函数模板
template <class T>
T MaxElement(T a[],int size){
    T tmpMax = a[0];
    for(int i = 1;i<size;++i){
        if(tmpMax <  a[i])
            tmpMax = a[i];
    }
    return tmpMax;
}
int main(){
    int a[] = {1,2,3,5,73,737,24,24};
    cout << MaxElement(a,8) << endl;
    double b[] = {1.4,1.4,3,5,737.4,737.45,24,42};
    cout << MaxElement(b,8) << endl;
    system("pause");
    return 0;
}
*/

/*不通过参数实例化函数模板
template <class T>
T Inc(T n ){
    return 1 + n;
}
int main(){
    cout << Inc<double>(4)/2; //输出2.5  直接把double带入T
    system("pause");
    return 0;
}
*/

/*函数模板的重载
函数模板的重载条件：
    1.形参表不同
    2.类型参数表不同

函数模板和函数的次序：
    在有多个函数和函数模板名字相同的情况下，编译器如下处理一条函数调用语句
    1.先找参数完全匹配的 普通函数 (由非模板实例化而得到的函数)
    2.再找参数完全匹配的 函数模板
    3.再找实参数经过自动类型转换后能够匹配的 普通函数
    4.上面的都找不到，则报错

//函数模板重载
template <class T>
T Max(T a , T b){
    cout << "templateMax" <<endl;
    system("pause");
    return ;
}

template <class T,class T2>
T Max(T a,T2 b){
    cout << "templateMax2" << endl;
    system("pause");
    return a;
}

double Max(double a,double b){
    cout << "myMax" <<endl;
    system("pause");
    return ;
}

int main(){
    int i = 4;
    int j = 5;
    Max(1.2,3.4);
    Max(i,j);
    cout << Max(3,1.2);//注意两条语句的区别 会影响返回值的类型
    cout << Max(1.2,3);
    system("pause");
    return 0;
}

//函数模板示例：Map
template <class T,class Pred>
void Map(T s,T e, T x, Pred op){ //s起点指针 e终点指针 x目标区间起点指针 op函数指针
    for(; s != e;++s,++x){
        *x = op(*s);
    }
}
int Cube(int x){
    return x*x*x;
}
double Square(double x){
    return x*x;
}
int a[5] ={1,2,3,4,5},b[5];
double d[5] = {1.1,2.1,3.1,4.1,5.1},c[5];
int main(){
    Map(a,a+5,b,Square);    //模板实例化为 void Map(int*s,int*e,int*x,double(*op)(double));
    for(int i =0;i<5;++i)
        cout << b[i] << ",";
    cout <<endl;
    
    Map(a,a+5,b,Cube);
    for(int i =0;i<5;++i)
        cout << b[i] << ",";
    cout <<endl;

    Map(d,d+5,c,Square);
    for(int i =0;i<5;++i)
        cout << c[i] << ",";
    cout <<endl;

    system("pause");
    return 0;
}

*/
