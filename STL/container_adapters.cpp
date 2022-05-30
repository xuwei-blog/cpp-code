#include <deque>
#include <queue>
#include <iostream>
using namespace std;
/*容器适配器
- 容器适配器没有迭代器

//stack
- stack是后进先出的数据结构，只能插入，删除，访问栈顶的元素
- 可用vector,list,deque来实现，缺省情况下，用deque实现。用vector和deque实现，比用list实现性能好

//原理
template <class T,class Cont = deque<T> >
class stack{
    ...
};

- stack上的操作：
    - push 插入元素
    - pop 弹出元素
    - top 返回栈顶元素的引用

//queue
- 和stack基本类似，可以用list和deque实现。缺省情况下用deque实现。
template <class T,class Cont = deque<T> >
class queue{
    ...
};

- queue上的操作
    - 同意也有push，pop，top函数，但是push发生在队尾，pop，top发生在队头。先进先出
    - 有back成员函数可以返回队尾元素的引用

//priority_queue
- 原理
template <class T,class Container = vector<T>,class Compare = less<T> >
class priority_queue;
- 和queue类似，可以用vector和deque实现。缺省的情况下用vector实现。
- priority_queue通常用堆排序技术实现，保证最大的元素总是在最前面。即执行pop操作时，删除的是最大的元素；
    执行top操作时，返回的是最大元素的引用。默认的元素比较器是less<T>

- push,pop复杂度logn
- top复杂度1
*/

int main(){
    priority_queue<double> pq1;
    pq1.push(3.2);
    pq1.push(9.8);
    pq1.push(9.8);
    pq1.push(5.4);
    while(!pq1.empty()){
        cout << pq1.top()<<" ";
        pq1.pop();
    }
    cout << endl;
    priority_queue<double,vector<double>,greater<double> > pq2;  //规则是第三个参数，不能跳着写，所以要补全缺省
    pq2.push(3.2);
    pq2.push(9.8);
    pq2.push(9.8);
    pq2.push(5.4);
    while(!pq2.empty()){
        cout << pq2.top()<<" ";
        pq2.pop();
    }
    cout << endl;

    system("pause");
    return 0;
}

/*容器适配器的元素个数
stack,queue,priority_queue都有
    - empty() 成员函数 用于判断适配器是否为空
    - size() 成员函数 返回适配器中元素个数
*/