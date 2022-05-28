#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <list>
using namespace std;
/*函数对象
- 一个类重载了运算符“()”，则该类的对象就成为函数对象

//函数对象示例：
class CMyAverage{//函数对象类
    public:
        double operator()(int a1,int a2,int a3){
            return (double)(a1+a2+a3)/3;
        }
};
int main(){

    CMyAverage average; //函数对象
    cout << average(3,2,3);   //average.operator()(3,2,3);
                              //输出2.66667
    system("pause");
    return 0;
}

//求n次方和
int sumSquares(int total,int value){
    return total + value*value;
}
template<class T>
void PrintInterval(T first,T last){
    //输出区间[first,last)中的元素
    for(; first != last; ++first)
        cout << *first << " ";
    cout << endl;
}
template <class T>
class SumPowers{
    private:
        int power;
    public:
        SumPowers(int p):power(p){}
        const T operator()(const T & total,const & value){
            T v = value;
            for(int i =0; i<power - 1;++i)
                v = v* value;
            return total + v;
        }
};


int main(){
    const int SIZE = 10;
    int a1[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a1,a1+SIZE);
    cout << "1) " ;
    PrintInterval(v.begin(),v.end());

    int result = accumulate(v.begin(),v.end(),0,sumSquares);
    cout << "2) 平方和" << result << endl;

    result = accumulate(v.begin(),v.end(),0,SumPowers<int>(3));
    cout << "3) 立方和" << result << endl;

    result = accumulate(v.begin(),v.end(),0,SumPowers<int>(4));
    cout << "4) 4次方和" << result << endl;

    system("pause");
    return 0;
}
*/

/*
第一条accumulate的调用    
int result = accumulate(v.begin(),v.end(),0,sumSquares); 
实例化出
int accumulate<vector<int>::iterator first,vector<int>::iterator last,int init,int(*op)(int,int){
    for(;first!=last;++first)
        init = op(init,*first);
    return init;
}

第二条accumulate的调用
result = accumulate(v.begin(),v.end(),0,SumPowers<int>(3));
实例化出
int accumulate<vector<int>::iterator first,vector<int>::iterator last,int init,SumPowers<int> op{
    for(;first!=last;++first)
        init = op(init,*first);    //为啥叫函数对象 和上一条对照已经可以看出来了
    return init;
}
*/

/*STL中的函数对象类模板
- 以下模板可以用来生成函数对象
    - equal_to
    - greater
    - less
    ...
- 头文件 <functional>
- greater函数对象类模板

template<class T>
struct greater:public binary_function<T,T,bool>{
    bool operator()(const T& x.const T& y) const{
        return x > y ;
    }
};
//greater的应用
//list有两个sort成员函数
void sort();//将list中的元素按‘<’规定的比较方法升序排列
template<class Compare>
void sort(Compare op);//将list中的元素按op规定的比较方法升序排列。即要比较x，y大小时，看op(x,y)的返回值，为true则认为x小于y

//greater的应用
class MyLess{
    public:
        bool operator()(const int & c1,const int & c2){
            return (c1 % 10) < (c2 % 10);
        }
};
template<class T>
void Print(T first ,T last){
    for(;first!=last;++first)
        cout << *first << ",";
}
int main(){
    const int SIZE = 5;
    int a[SIZE] ={5,21,14,2,3};
    list<int> lst(a,a+SIZE);
    lst.sort(MyLess());           //类
    Print(lst.begin(),lst.end());
    cout << endl;

    lst.sort(greater<int>());     //函数对象 （x大于y，说明x是小的）（排序都是从小到大排，但是‘小’的含义各不同）
    Print(lst.begin(),lst.end());
    cout << endl;

    system("pause");
    return 0;
}

//案例：写出MyMax模板
class MyLess{//比大小的成员函数
    public:
        bool operator()(int a1,int a2){
            if((a1%10)<(a2%10))
                return true;
            else  
                return false;
        }
};
//比大小的全局函数
bool MyCompare(int a1,int a2){
    if((a1%10) < (a2%10))
        return false;
    else    
        return true;
}
//核心函数模板
template <class T,class Pred>
T MyMax(T first,T last,Pred myless){
    T tmpMax = first;
    for(; first!=last ; ++first){
        if(myless(*tmpMax,*first))
            tmpMax = first;
    }
    return tmpMax;
}
int main(){
    int a[] = {35,7,13,19,12};
    cout << *MyMax(a,a+5,MyLess()) <<endl;
    cout << *MyMax(a,a+5,MyCompare) <<endl;
    system("pause");
    return 0;
}
*/


