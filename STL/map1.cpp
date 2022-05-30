#include <iostream>
#include <map>
using namespace std;
/*map
- map中的元素都是pair模板类对象。
- 关键字（first成员变量）各不相同
- 元素按照关键字从小到大排列，缺省情况下用less<Key>,即‘<’定义‘小于’

template <class Key,class T,class Pred = less<Key>,class A = allocator<T>>
class map{
    ...
    typedef pair<const Key,T> value_type;
    ...
};

//map的[]成员函数
- 若pairs为map模板类的对象
    pair[key]
- 返回对关键字等于key的元素的值(second成员变量)的引用。若没有关键字为key的元素，则会往pairs里插入一个关键字为key的元素
    其值用无参构造函数初始化，并返回其值的引用。
- 如：
    map<int,double> pairs;
    则：pairs[50] = 5;会修改pairs中关键字为50的元素，使其值变为5。
    若不存在关键字等于50，则插入此元素，并使其值变为5。
*/

//map示例
template<class Key,class Value>
ostream & operator <<(ostream&o,const pair<Key,Value>&p){
    o <<"(" <<p.first<<","<<p.second<<")";
    return o;
}
int main(){
    typedef map<int,double,less<int> > mmid;//>> 要写成 > >
    mmid pairs;
    cout <<"1) " <<pairs.count(15)<<endl;
    pairs.insert(mmid::value_type(15,2.7));
    pairs.insert(make_pair(15,99.3)); //插入失败 因为map不允许first相同
    cout << "2) " <<pairs.count(15) <<endl;
    pairs.insert(mmid::value_type(20,9.3));
    mmid::iterator i;
    cout << "3) ";
    for(i=pairs.begin();i!=pairs.end();++i)
        cout << *i << ",";
    cout << endl;

    cout << "4) " ;
    int n = pairs[40];
    for(i=pairs.begin();i!=pairs.end();++i)
        cout << *i << ",";
    cout << endl;
    
    cout << "5) ";
    pairs[15] = 6.28;
    for(i=pairs.begin();i!=pairs.end();++i)
        cout << *i << ",";
    cout << endl;
    
    system("pause");
    return 0;
}