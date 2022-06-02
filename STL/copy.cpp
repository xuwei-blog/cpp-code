#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

/*copy函数模板
//原理
template<class InIt,class OutIt>
OutIt copy(InIt first,InIt last,OutIt x);
- 本函数对每个在区间[0,last-first)中的M执行一次
    *(x+N) = *(first+N)，返回x+N
- 对于copy(v.begin(),v.end(),output);
    - first和last类型是vector<int>::const_iterator
    - output的类型是ostream_iterator<int>

//源码
template<class _II,class _OI>
inline _OI copy(_II_IF,_II_L,_OI_X){
    for(;_F!=_L;++_X,++_F)
        *_X = *_F;
    return (_X);
}
*/
//自己写my_copy
//调用copy(a,a+4,oit);实例化得到的copy如下
/*
My_osteram_iterator<int> copy(int*_F,int*_L,My_ostream_iterator<int> _X){
    for(;_F!=_L;++_X,++_F)
        *_X = *_F;
    return (_X);
}
分析：有3个运算符被重载 ++对象     *     =用来输出
*/
//重载++和*
template<class T>
class My_ostream_iterator:public iterator<output_iterator_tag,T>{
    private:
        string sep;//分隔符
        ostream & os; //ofstream无参构造是私有的 所以用引用
    public:
        My_ostream_iterator(ostream & o,string s):sep(s),os(o){}
        void operator ++(){}; //++只需要有定义，不需要做事
        My_ostream_iterator & operator * (){return *this;}
        My_ostream_iterator & operator = (const T & val){
            os << val << sep;
            return *this;
        }
};
int main(){
    int a[4] = {1,2,3,4};
    My_ostream_iterator<int> oit(cout,"*");
    copy(a,a+4,oit);//打印到桌面
    ofstream oFile("text.txt",ios::out);
    My_ostream_iterator<int> oitf(oFile,"*");
    copy(a,a+4,oitf);//打印到文件
    oFile.close();
    system("pause");
    return 0;
}