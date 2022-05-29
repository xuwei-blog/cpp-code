
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
*/