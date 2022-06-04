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