#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
/*迭代器
- 用于指向顺序容器和关联容器中的元素
- 迭代器用法和指针类似
- 有const和非const两种
- 通过迭代器可以读取它指向的元素
- 通过非const迭代器还能修改其指向的元素
*/

/*迭代器的操作
- 迭代器的定义
    容器类名::iterator 变量名;
    或
    容器类名::const_iterator 变量名;
- 访问一个迭代器指向的元素
    * 迭代器变量名
- 迭代器可以++，指向后面元素的迭代器

//迭代器案例
int main(){
    vector<int> v;   //存放int元素的数组，一开始里面没有元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::const_iterator i;  //常量迭代器
    for(i=v.begin();i != v.end();++i)
        cout << *i << " ";
    cout << endl;
    system("pause");
    return 0;
}

//反向迭代器
int main(){
    vector<int> v;   //存放int元素的数组，一开始里面没有元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::reverse_iterator i;    //反向迭代器
    for(i=v.rbegin();i != v.rend();++i) //这里++逻辑上是--，指向前面的元素
        cout << *i << " ";
    cout << endl;
    system("pause");
    return 0;
}

//非常量迭代器
int main(){
    vector<int> v;   //存放int元素的数组，一开始里面没有元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator i;      //非常量迭代器 可以通过i可以修改其指向的元素
    for(i=v.begin();i != v.end();++i)
        *i = 100;
    for(i=v.begin();i != v.end();++i)
        cout << *i << " ";
    cout << endl;

    system("pause");
    return 0;
}
*/

/*双向迭代器
- 若p和p1都是双向迭代器，则可对p、p1进行以下操作
    - ++p，p++ 使p指向容器中下一个元素
    - --p，p-- 使p指向容器中上一个元素
    - *p 取p指向的元素
    - p = p1 赋值
    - p == p1，p != p1 判断是否相等、不等
*/

/*随机访问迭代器
- 若p和p1都是随机访问迭代器，则可对p、p1进行一下操作
    - 双向迭代器所有操作
    - p += i 将p向后移动i个元素
    - p -= i 将p向前移动i个元素
    - p + i 值为：指向p后面的第i个元素的迭代器
    - p - i 值为：指向p前面的第i个元素的迭代器
    - p[i] 值为：p后面的第i个元素的引用
    - p < p1 , p <= p1 , p > p1 , p >= p1
*/

/*容器支持的迭代器
容器            容器上的迭代器类别
vector          随机访问
deque           随机访问
list            双向
set/multiset    双向
map/multimap    双向

stack           不支持迭代器
queue           不支持迭代器
priority_queue  不支持迭代器

应用：
    例如sort，binary_search需要通过随机访问迭代器来访问容器中的元素，
那么list以及关联容器就不支持该算法

//vector的迭代器是随机访问迭代器 - 遍历vector的操作
int main(){
    vector<int> v(100);
    int i ;
    for(i=0;i<v.size();++i)
        cout << v[i]; //根据下标随机访问
    vector<int>::const_iterator ii;
    for(ii=v.begin();ii!=v.end();++ii)  //可以判断ii != v.end()
        cout << *ii;
    for(ii=v.begin();ii<v.end();++ii)   //可以判断 ii < v.end()
        cout << *ii;
    ii = v.begin();
    while(ii<v.end()){//间隔一个输出
        cout << *ii;
        ii = ii + 2; //可以+i
    }
}

//list的迭代器是双向迭代器 - 遍历list的操作
int main(){
    list<int> v;
    list<int>::const_iterator ii;
    for(ii =v.begin();ii != v.end(); ++ii)  //双向迭代器不支持随机存取v[i] 和 比较 <
        cout << *ii;
}
*/

/*算法简介
- 算法就是一个个函数模板，大多数在<algorithm>中定义
- STL中提供能在各种容器中通用的算法，比如查找，排序等
- 算法通过迭代器来操纵容器中的元素。许多算法可以对容器中的一个局部区间进行操作，因此需要两个参数，
    一个是起始元素的迭代器，一个是终止元素的迭代器。比如，排序和查找
- 有的算法返回一个迭代器。比如find()，在容器中查找一个元素，并返回一个指向该元素的迭代器
- 算法可以处理容器，也可以处理普通数组

//算法示例：
template<class InIt,class T>
InIt find(InIt first,InIt second,const T& val);
- first和last这两个参数都是容器的迭代器，他们给出了容器中的查找区间起点和终点[first,last)。
    区间的起点是位于查找范围之中的，而终点不是。find在[first,last)查找等于val的元素
- 用 == 运算符判断相等
- 函数返回值是一个迭代器。如果找到，则该迭代器指向被找到的元素。如果找不到，则该迭代器等于last

//find算法实例：
int main(){
    int array[10] = {10,20,30,40};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator p;
    p = find(v.begin(),v.end(),3);
    if(p!=v.end())
        cout << *p << endl;
    int *pp = find(array,array+2,40); //数组名是迭代器
    cout << *pp <<endl;
    system("pause");
    return 0;
}
*/

/*STL中‘大’，‘小’的概念
- 关联容器内部的元素从小到大排序的
- 有些算法要求其操作的区间是从小到大排序的，称为 有序区间算法
    例如：binary_search
- 有些算法会对区间进行从小到大的排序，称为 排序算法
    例如：sort
- 还有一些其他算法会用到‘大’，‘小’的概念
    使用STL时，在缺省的情况下，以下三个说法等价：
    - x比y小
    - 表达式x<y为真
    - y比x大

- STL中相等的概念
    - x和y相等 等价于 x==y为真
        例如：在未排序的区间上进行的算法，入顺序查找find ...
    - x和y相等 等价于 x小于y和y小于x同时为假
        例如：有序区间算法，如binary_search
        关联容器自身的成员函数find ...

//STL相等的示例：
class A{
    int v;
    public:
        A(int n):v(n){}
        bool operator < (const A&a2) const{
            cout << v << "<" <<a2.v <<"?"<<endl;
            return false;
        }
        bool operator == (const A&a2)const {
            cout << v << "==" <<a2.v<<"?"<<endl;
        }
};
int main(){
    A a[] = {A(1),A(2),A(3),A(4),A(5)};
    cout << binary_search(a,a+4,A(9)) << endl; //可以得出结论：binary_search比较时，判断是否大于或者小于，间接判断相等
    system("pause");
    return 0;
}
*/

