//cpp11新特性

/*统一的初始化方法
int arr[3]{1,2,3};
vector<int> iv{1,2,3};
map<int,string> mp{{1,"a"},{2,"b"}};
string str{"hello world"};
int *p = new int[20]{1,2,3};

struct A{
    int i,j;
    A(int m,int n):i(m),j(n){}
};
A func(int m,int n){return {m,n};}
int main(){A* pa = new A{3,7};}
int main(){A* pa = new A(3,7);}
*/

/*成员变量默认初始值
class B{
    public:
        int m = 1234;
        int n;
};
int main(){
    B b;
    cout << b.m << endl;
    return 0;
}
*/

/*auto关键字
- 用于定义变量，编译器可以自动判断变量的类型
auto i = 100; //i是int
auto p = new A(); //p是A*
auto k = 34343LL; //k是long long
map<string,int,greater<string> > mp;
for(auto i = mp.begin();i!=mp.end();++i){
    cout << i->first << "," << i->second ;
}
//i的类型是map<string,int,greater<string> >::iterator

//更吊的用法
class A{};
A operator+(int n,const A& a){
    return a;
}
template <class T1,class T2>
auto add(T1 x,T2 y)->decltype(x,y){
    return x+y;
}
auto d = add(100,1.5); //d是double d =101.5
auto k = add(100,A()); //d是A类型
*/

/*decltype关键字
- 求表达式的类型
int i ;
double t;
struct A{double x};
const A*a = new A();

decltype(a) x1;   //x1 is A*
decltype(i) x2;   //x2 is int
decltype(a->) x3; //x3 is double
decltype((a->x)) x4; //x4 is double&

*/

/*智能指针
- 头文件<memory>
- 通过shared_ptr的构造函数，可以让shared_ptr对象托管一个new运算符返回的指针
- shared_ptr<T> ptr(new T); //T可以是各种类型
    此后ptr就可以像T*类型的指针一样来使用，即*ptr就是用new动态分配的那个对象，
    而且不必操心释放内存的事
- 多个shared_ptr对象可以同时托管一个指针，系统会维护一个托管计数。当无shared_ptr
    托管该指针时，delete该指针
- shared_ptr对象不能托管指向动态分配的数组的指针，否则程序运行会出错

案例shared_ptr.cpp
*/

/*nullptr
- 和null完全一样
案例nullptr.cpp
*/

/*基于范围的for循环

案例fori.cpp
*/

/*右值引用和move语义
- 右值：一般来说，不能去地址的表达式，就是右值，能取地址的，就是左值
class A{};
A & r =A();   //err A()是无名变量，是右值
A && r = A(); //ok  r是右值引用
- 主要目的是提高程序运行的效率，减少需要进行深拷贝的对象进行深拷贝的次数
案例rvalue_reference.cpp
*/

/*无序容器(哈希表)
案例 unordered_map.cpp
*/

/*正则表达式
案例 regular_expression.cpp
*/

/*Lambda表达式
- 为啥需要？
    只使用依次的函数对象，能否不要专门为其编写一个类？
    只调用依次的简单函数，能否在调用时才写出其函数体？
形式：
[外部变量访问方式说明符](参数表)->返回值类型{
    语句组
}

[=]         以传值的形式使用所有外部变量
[]          不使用任何外部变量
[&]         以引用的形式使用所有外部变量
[x,&y]      x以传值形式使用，y以引用形式使用
[=,&x,&y]   x，y以引用形式使用，其余变量以传值形式使用
[&,x,y]     x，y以传值形式使用，其余变量以引用形式使用

- ->返回值类型 可以没有，没有的话则编译器自动判断返回值类型

案例Lambda.cpp
*/