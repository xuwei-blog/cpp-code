#include <iostream>
using namespace std;

/*类模板与继承（4种情况）
- 类模板从类模板派生
- 类模板从模板类派生
- 类模板从普通类派生
- 普通类从类模板派生
*/

/*类模板从类模板派生
template <class T1,class T2>
class A{
    T1 v1;
    T2 v2;
};

template <class T1,class T2>
class B:public A<T2,T1>{
    T1 v3;
    T2 v4;
};

template <class T>
class C:public B<T,T>{
    T v5;
};

int main(){
    //实例化模板类的过程
    1.class B<int,double>:pulibc A<double,int>{
        int v3;
        double v4;
    }
    class A<double,int>{
        double v1;
        int v2;
    }
    *=
    B<int,double> obj1; 

    //全是int
    C<int> obj2;
    system("pause");
    return 0;
}
*/

/*类模板从模板类派生
template <class T1,class T2>
class A {
    T1 v1;
    T2 v2;
};
template <class T>
class B:public A<int,double>{//基类是一个具体的类
    T v;
};
int main(){
    B<char> obj1;  //自动生成两个模板类：A<int,double> 和 B<char>  类模板B从模板类A派生
    system("pause");
    return 0;
}
*/

/*类模板从普通类派生
class A{
    int v1;
};
template <class T> 
class B:public A{  //所有从B实例化得到的类，都以A为基类
    T v;
};
int main(){
    B<char> obj1;
    system("pause");
    return 0;
}
*/

/*普通类从模板类派生
template <class T>
class A{
    T v1;
    int n ;
};
class B:public A<int>{
    double v;
};
int main(){
    B obj1;
    system("pause");
    return 0;
}
*/


