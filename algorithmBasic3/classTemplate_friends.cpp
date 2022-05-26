#include <iostream>
#include <string>
using namespace std;

/*类模板与友元
- 函数、类、类的成员函数作为类模板的友元
- 函数模板作为类模板的友元
- 函数模板作为类的友元
- 类模板作为类模板的友元
*/

/*函数、类、类的成员函数作为类模板的友元
void Func1(){}
class A {};
class B {
    public:
        void Func(){}
};
template <class T>
class Tmp1{
    friend void Func1();
    friend class A;
    friend void B::Func();
};//任何从Tmp1实例化来的类，都有以上三个友元
*/

/*函数模板作为类模板的友元
template <class T1,class T2>
class Pair{
    private:
        T1 key; //关键字
        T2 value; //值
    public:
        Pair(T1 k,T2 v):key(k),value(v){};
        bool operator < (const Pair<T1,T2>&p) const;
        template<class T3,class T4> //函数模板
        friend ostream & operator<<(ostream & o,const Pair<T3,T4>&p);
};
template <class T1,class T2>
bool Pair<T1,T2>::operator < (const Pair<T1,T2>&p) const{
    return key < p.key; //比较关键字的大小
}
template <class T1,class T2>
ostream & operator<<(ostream & o,const Pair<T1,T2>& p){
    o<< "(" << p.key << "," <<p.value << ")";
    system("pause");
    return o;
}

int main(){
    Pair<string,int> student("Tom",29);
    Pair<int,double> obj(12,3.14);
    cout << student <<" " << obj ;

    system("pause");
    return 0;
}
*/

/*函数模板作为类的友元
class A{
    int v;
    public:
        A(int n):v(n){}
        template <class T>
        friend void Print(const T & p);
};

template <class T>
void Print(const T & p){
    cout << p.v;
}

int main(){ 
    A a(4);
    Print(a);
    system("pause");
    return 0;
}
*/

/*类模板作为类模板的友元
template <class T>
class B{
    T v;
    public:
        B(T n):v(n){}
        template <class T2>
        friend class A;
};
template <class T>
class A{
    public:
        void Func(){
            B<int> o(10);
            cout << o.v << endl;
        }
};
int main(){
    A<double> a;
    a.Func ();
    system("pause");
    return 0;
}
*/
