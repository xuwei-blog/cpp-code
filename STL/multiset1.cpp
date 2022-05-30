#include <iostream>
#include <set>
using namespace std;
/*multiset
- Pred类型的变量决定了multiset中的元素，“一个比另一个小”是怎么定义的。
    multiset运行过程中，比较连个元素x，y的大小的做法，就是生成一个Pred类型
    的变量，假定为op，若表达式op(x,y)，返回值为true，则x比y小
    Pred的缺省类型是less<key>
template <class Key,class Pred = less<key>,
            class A = allocator<key> >
class multiset{
    ;
};

- less模板的定义 - (用来比较大小)
    template<class T>
    struct less:public binary_function<T,T,bool>{
        bool operator()(const T&x,const T&y){
            return x < y;
        }const;
    };
*/

/*multiset的成员函数
- iterator find(const T& val); 在容器中查找值为val的元素，返回其迭代器。如果找不到，返回end()
- iterator insert(const T&val); 将val插入到容器中并返回其迭代器
- void insert(iterator first,iterator last); 将区间[first,last)插入容器
- int count(const T&val); 统计有多少个元素的值回合val相等
- iterator lower_bound(const T&val); 查找一个最大的位置it,使得[begin(),it)中所有的元素都比val小
- iterator upper_bound(const T&val); 查找一个最小的位置it,使得[it,end())中所有的元素都比val大
- pair<iterator,iterator> equal_range(const T&val); 同时求得lower_bound和upper_bound
- iterator erase(iterator it); 删除it指向的元素，返回其后面的元素的迭代器（迭代器删掉后 不准再++了）

//multiset的用法
class A{};
int main(){
    multiset<A> a;
    //等价于
    //multiset<A,less<A>> a;
    a.insert(A()); //class A 不能比大小 err
}
*/
template <class T>
void Print(T first,T last){
    for(;first != last ; ++first)
        cout << *first << " ";
    cout << endl;
}
class A{
    private:
        int n;
    public:
        A(int n_){
            n = n_;
        }
    friend bool operator < (const A & a1,const A & a2){
        return a1.n < a2.n;
    }
    friend ostream & operator<<(ostream & o,const A & a2){
        o << a2.n ;
        return o;
    }
    friend class MyLess;
};
struct MyLess{
    bool operator()(const A&a1,const A&a2){
        return (a1.n%10) < (a2.n%10);
    }
};
typedef multiset<A> MSET1;
typedef multiset<A,MyLess> MSET2;
int main(){
    const int SIZE = 6;
    A a[SIZE] = {4,22,19,8,33,40};
    MSET1 m1;
    m1.insert(a,a+SIZE);
    m1.insert(22);
    cout <<"1) "<<m1.count(22)<<endl;
    cout << "2) " ;
    Print(m1.begin(),m1.end());


    //m1的元素 4 8 19 22 22 33 40
    MSET1::iterator pp =m1.find(19);
    if(pp!= m1.end())
        cout << "found" <<endl;
    
    cout <<"3) ";
    cout << *m1.lower_bound(22) <<"," //指向第一个22
         <<*m1.upper_bound(22)<<endl; //指向33
    
    pp = m1.erase(m1.lower_bound(22),m1.upper_bound(22));//删除后，pp指向被删除元素的后一个元素
    cout << "4) ";
    Print(m1.begin(),m1.end());
    cout << "5) ";
    cout << *pp <<endl;
    MSET2 m2;
    m2.insert(a,a+SIZE); //个位数小 才是小
    cout << "6) " ;
    Print(m2.begin(),m2.end());



    system("pause");
    return 0;
}