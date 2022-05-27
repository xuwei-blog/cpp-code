#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*list容器
- 在任何位置插入删除都是常数时间，不支持随机存取
- 除了具有所有顺序容器都有的成员函数以外，还支持8个成员函数
    - push_front 在前面插入
    - pop_front 删除前面的元素
    - sort 排序(list不支持STL的算法sort)
    - remove 删除和指定值相等的所有元素
    - unique 删除所有和前一个元素相同的元素(要做到元素不重复，则unique之前还需要sort)
    - merge 合并两个链表，并清空被合并的那个
    - reverse 颠倒链表
    - splice 在指定位置前面插入另一链表中的一个或多个元素，并在另一链表中删除被插入的元素
*/

class A{
    private:
        int n ;
    public:
        A(int n_){n = n_;}
        friend bool operator<(const A & a1,const A & a2);
        friend bool operator==(const A & a1,const A & a2);
        friend ostream & operator << (ostream & o,const A & a);
};
bool operator<(const A & a1,const A & a2){
    return a1.n < a2.n;
}
bool operator==(const A & a1,const A & a2){
    return a1.n == a2.n;
}
ostream & operator << (ostream & o,const A & a){
    o << a.n;
    return o;
}
template <class T>
void PrintList(const list<T> & lst){ //在模板里定义类型不确定的迭代器
    typename list<T>::const_iterator i; //typename用来说明list<t>::const_iterator时个类型 在dec中要写
    i = lst.begin();
    for(i = lst.begin(); i != lst.end() ; ++i)
        cout << *i << " ,"; 
}
int main(){
    list<A> lst1,lst2;
    lst1.push_back(1);
    lst1.push_back(3);
    lst1.push_back(2);
    lst1.push_back(4);
    lst1.push_back(2);
    lst2.push_back(10);
    lst2.push_front(20);
    lst2.push_back(30);
    lst2.push_back(30);
    lst2.push_back(30);
    lst2.push_front(40);
    lst2.push_back(40);
    cout << "1) ";
    PrintList(lst1);
    cout << endl;
    cout << "2) ";
    PrintList(lst2);
    cout << endl;

    lst2.sort();
    cout << "3) " ;
    PrintList(lst2);
    cout << endl;

    lst2.pop_front();
    cout << "4) " ;
    PrintList(lst2);
    cout << endl;

    lst1.remove(2); //删除所有等于2的元素
    cout << "5) " ;
    PrintList(lst1);
    cout << endl;

    lst2.unique(); //删除所有和前一个元素相等的元素
    cout << "6) " ;
    PrintList(lst2);
    cout << endl;

    lst1.merge(lst2); //合并lst2到lst1 清空lst2
    cout << "7) " ;
    PrintList(lst1);
    cout << endl;

    cout << "8) " ;
    PrintList(lst2);
    cout << endl;

    lst1.reverse();
    cout << "9) " ;
    PrintList(lst1);
    cout << endl;

    lst2.push_back(100);
    lst2.push_back(200);
    lst2.push_back(300);
    lst2.push_back(400);

    list<A>::iterator p1,p2,p3;
    p1 = find(lst1.begin(),lst1.end(),3);
    p2 = find(lst2.begin(),lst2.end(),200);
    p3 = find(lst2.begin(),lst2.end(),400);
    lst1.splice(p1,lst2,p2,p3);

    cout << "10) " ;
    PrintList(lst1);
    cout << endl;

    cout << "11) " ;
    PrintList(lst2);
    cout << endl;

    system("pause");
}