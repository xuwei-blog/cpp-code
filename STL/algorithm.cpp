#include <iostream>
using namespace std;

/*stl算法分类

- 大致可以分为以下7类
    - 不变序列算法
    - 变值算法
    - 删除算法
    - 变序算法
    - 排序算法
    - 有序区间算法
    - 数值算法

- 大多重载的算法都是有两个版本的
    - 用‘==’判断元素是否相等，或用‘<’来比较大小
    - 多出一个类型参数‘Pred’和函数形参‘Pred op’：
        通过表达式‘op(x,y)’的返回值：true/false
        来判断x是否‘等于’y，或者x是否‘小于’y

- 如下面有两个版本的min_element:
    iterator min_element(iterator first =,iterator last);
    iterator min_element(iterator first =,iterator last,Pred op);

*/

/*不变序列算法
- 该类算法不会修改算法所作用的容器或对象
- 适用于顺序容器和关联容器
- 时间复杂度都是o（n）
- 此类常见算法
    - min 求两个对象重较小的（可定义比较器）
    - max 求两个对象重较大的（可定义比较器）
    - min_element 求区间中的最小值（可定义比较器）
        template<class FwdIt>
        FwdIt min_element(FwdIt first,FwdIt last);
        返回[first,last)中最小元素的迭代器，以'<'作比较器
        最小指没有元素比他小，而不是他比别的不同元素都小
        因为即便a!=b,a<b和a>b有可能都不成立
    - max_element 求区间中的最大值（可定义比较器）
        template<class FwdIt>
        FwdIt max_element(FwdIt first,FwdIt last);
        返回[first,last)中最大元素（不小于任何其他元素）的迭代器
        以‘<’作比较器
    - for_each 对区间中的每个元素都做某种操作
        template<class InIt,class Fun>
        Fun for_each(InIt first,InIt last ,Fun f);
        对[first,last)中的每个元素e，执行f(e)，要求f(e)不能改变e

    - count 计算区间中等于某值的元素个数
        template<class InIt,class T>
        size_t count(InIt first,InIt last,const T& val);
        计算[first,last)中等于val的元素个数(x==y为true算等于)
    - count_if 计算区间中复合某种条件的元素个数
        template<class InIt,class Pred>
        size_t count_if(InIt first,InIt last,Pred pr);
        计算[first,last)中符合pr(e)==true的元素e的个数
    - find 在区间中查找等于某值的元素
        template<class InIt,class T>
        InIt find(InIt first,InIt last,const T& val);
        返回区间[first,last)中的迭代器i,使得*i == val
    - find_if 在区间中查找符合某条件的元素
        template<class InIt,class Pred>
        InIt find_if(InIt first,InIt last,Pred pr);
        返回区间[first,last)中的迭代器i，使得pr(*i) == true
    - find_end 在区间中查找另一个区间最后一次出现的位置（可定义比较器）
    - find_first_of 在区间中查找第一个出现在另一个区间中的元素（可定义比较器）
    - adjacent_find 在区间中寻找第一次出现连续两个相等元素的位置（可定义比较器）

    - search 在区间中查找另一个区间第一次出现的位置（可定义比较器）
    - search_n 在区间中查找第一次出现等于某值的连续n个元素（可定义比较器）
    - equal 判断两区间是否相等（可定义比较器）
    - mismatch 逐个比较两个区间的元素，返回第一次发生不相等的两个元素的位置（可定义比较器）
    - lexicographical_compare 按字典序比较两个区间的大小（可定义比较器）

//max_element和min_element示例
    algTest01.cpp
*/

/*变值算法
- 此类算法会修改源区间或目标区间元素的值
- 值被修改的那个区间，不可以是属与关联容器的
- 此类常见算法
    - for_each 对区间中的每个元素都做某种操作
    - copy 复制一个区间到别处
    - copy_backward 复制一个区间到别处，但目标区间是从前往后被修改的
    - transform 将一个区间的元素变形后拷贝到另一个区间
        template<class InIt,class OutIt,class Unop>
        OutIt transform(InIt first,InIt last,OutIt x,Unop uop);
        对[first,last)中的每个迭代器I,
            执行uop(*I);并将结果依次放入从x开始的地方
            要求uop(*I);不得改变*I的值
        本模板返回值时个迭代器，即x+(last-first)
            x可以和first相等
        
    - swap_ranges 交换两个区间内容
    - fill 用某个值填充区域
    - fill_n 用某个值替换区间中的n个元素
    - generate 用某个操作的结果填充区间
    - generate_n 用某个操作的结果替换区间中的n个元素
    - replace 将区间中的某个值替换为另一个值
    - replace_if 将区间中符合某种条件的值替换成另一个值
    - replace_copy 将一个区间拷贝到另一个区间，拷贝时某个值要换成新值拷贝过去
    - replace_copy_if 将一个区间拷贝到另一个区间，拷贝时符合某条件的值要换成新值拷贝过去

//示例
algTest02.cpp
*/

/*删除算法
- 删除一个容器里的某些元素
- 删除不会使容器里的元素减少
    - 将所有应该被删除的元素看作空位子
    - 用留下的元素从后往前移，依次去填空位子
    - 元素往前移后，他原来的位置也就算是空位子
    - 也应由后面的留下的元素来填上
    - 最后，没有被填上的空位子，维持其原来的值不变
- 删除算法不应作用于关联容器
- 常见删除算法
    - remove 删除区间中等于某个值得元素
    - remove_if 删除区间中满足某种条件的元素
    - remove_copy 拷贝区间到另一个区间 等于某个值的元素不拷贝
    - remove_copy_if 拷贝区间到另一个区间 符合某种条件的元素不拷贝
    - unique 删除区间中连续相等的元素 只留下一个(可自定义比较器)
        tempalte<class FwdIt>
        FwdIt unique(FwdIt first,FwdIt last);
        用 == 比较是否相等（自定义）
        tempalte<class FwdIt,class Pred>
        FwdIt unique(FwdIt first,FwdIt last,Pred pr);
        用pr(x,y)为true说明x和y相等
        对[first,last)这个序列中连续相等的元素，只留下第一个
        返回值是迭代器，指向元素删除后的区间的最后一个元素的后面
    - unique_copy 拷贝区间到另一个区间 连续相等的元素 只拷贝第一个到目标区间(可自定义比较器)
- 算法复杂度o(n)

//remove例子
remove.cpp
*/

/*变序算法
- 变序算法改变容器中元素的顺序
- 但是不改变元素的值
- 变序算法不适用于关联容器
- 算法复杂度都是o（n）
- 常见变序算法
    - reverse 颠倒区间的前后次序
        template<class BidIt>
        void reverse(BidIt first,BidIt last);
        颠倒区间[first,last)顺序
    - reverse_copy 把一个区间颠倒后的结果拷贝到另一个区间
    - rotate 将区间进行循环左移
    - rotate_copy 将区间以首尾相接的形式进行旋转后的结果拷贝到另一个区间，源区间不变
    - next_permutation 将区间改为下一个排序
        template<class InIt>
        bool next_permulation (Init first,Init last);
        求下一个排列
    - prev_permutation 将区间改为上一个排序
    - random_shuffle 随机打乱区间内元素的顺序
        template<class RanIt>
        void random_shuffle(RanIt first,RanIt last);
        随机打乱[first,last)中的元素，适用于能随机访问的容器
    - partition 把区间内满足某个条件的元素移到全面，不满足该条件移到后面
        - stable_patiton
            - 把区间内满足某个条件的元素移到前面
            - 不满足该条件的移到后面
            - 而对这两部分元素，分别保持他们原来的先后次序不变
    
//next_permutation案例
next_permutation1.cpp
next_permutation2.cpp
*/

/*排序算法
- 比前面的变序算法复杂度更高，一般是nlogn
- 排序算法需要随机访问迭代器的支持
- 不适用于关联容器和list
- 常用排序算法
    - sort 将区间从小到大排序(可自定义比较器)
        - 原理：2套函数模板
            template<class RanIt>
            void sort(RanIt first,RanIt last);
            按升序排序
            判断x是否应比y靠前，就看x<y是否为true
            template<class RanIt,class Pred>
            void sort(RanIt first,RanIt last,Pred pr);
            按升序排序
            判断x是否应比y靠前，就看pr(x,y)是否为true
        - sort实际上是快速排序 复杂度nlogn
            - 平均性能最优
            - 但是最坏的情况下，性能可能非常差
        - 如果要保证‘最坏情况下’的性能，那么可以使用
            - stable_sort
            - stable_sort实际上是归并排序，特点是能保持相等元素之间的先后次序
            - 在有足够存储空间的情况下，复杂度为nlogn，否则复杂度为nlognlogn
            - stable_sort用法和sort相同
        - 排序算法要求随机存取迭代器的支持，所以list不能使用排序算法，要使用list::sort

    - stable_sort 将区间从小到大排序 并保持相等元素间的相对次序(可自定义比较器)
    - partial_sort 对区间部分排序 直到最小的n个元素就位(可自定义比较器)
    - partial_sort_copy 将区间前n个元素的排序结果拷贝到别处 源区间不变(可自定义比较器)
    - nth_element 对区间部分排序 使得第n小的元素(n从0开始算)就位 而且比它小的都在它前面
                    比它大的都在它后面(可自定义比较器)
    - make_heap 使区间成为一个‘堆’(可自定义比较器)
    - push_heap 将元素加入一个是‘堆’区间(可自定义比较器)
    - pop_heap 从‘堆’区间删除堆顶元素(可自定义比较器)
    - sor_heap 将一个‘堆’区间进行排序，排序结束后，该区间就是普通的有序区间，
                不再是‘堆’了(可自定义比较器)
*/

/*有序区间算法
- 要求所操作的区间是已经从小到大排好序的
- 需要随机访问迭代器的支持
- 有序区间算法不能用于关联容器和list
- 此类常见算法
    - binary_search 判断区间种是否包含某个元素
        - 折半查找
        - 要求容器已经有序且支持随机访问迭代器，返回是否找到
        template<class FwdIt,class T>
        bool binary_search(FwdIt first,FwdIt last,const T & val);
        - 上面这个版本，比较两个元素x,y大小时，看x<y
        template<class FwdIt,class T,class Pred>
        bool binary_search(FwdIt first,FwdIt last,const T & val,Pred pr);
        - 上面这个版本，比较两个元素x,y大小时，若pr(x,y)为true，则认为x小于y

    - includes 判断是否一个区间种的每个元素，都在另一个区间中
        template<class InIt1,class InIt2>
        bool includes(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2);
        template<class InIt1,class InIt2,class Pred>
        bool includes(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,Pred pr);
        - 判断[first2,last2)中的每个元素，是否都在[first1,last1)中
            - 第一个用<作比较器
            - 第二个用pr作比较器，pr(x,y) == true说明x，y相等
    - lower_bound 查找最后一个不小于某值的元素的位置
        template<class FwdIt,class T>
        FwdIt lower_bound(FwdIt first,FwdIt last,const T&val);
        - 要求[first,last)是有序的
        - 查找[first,last)中的，最大的位置FwdIt,使得[first,FwdIt)中所有元素都比val小
    - upper_bound 查找第一个大于某值的元素的位置
        template<class FwdIt,class T>
        FwdIt upper_bound(FwdIt first,FwdIt last,const T&val);
        - 要求[first,last)是有序的
        - 查找[first,last)中的，最小的位置FwdIt,使得[first,FwdIt)中所有元素都比val大
    - equal_range 同时获取lower_bound和upper_bound
        template<class FwdIt,class T>
        pair<FwdIt,FwdIt>equal_range(FwdIt first,FwdIt last,const T&val);
        - 要求[first,last)是有序的
        - 返回值是一个pair，假设为p，则：
            - [first,p.first)中的元素都比val小
            - [p.second,last)中的元素都比val大
            - p.first就是lower_bound的结果
            - p.last就是upper_bound的结果
    - merge 合并两个有序区间到第三个区间
        template<class InIt1,class InIt2,class OutIt>
        OutIt merge(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x);
        - 用<作比较器
        template<class InIt1,class InIt2,class OutIt，class Pred>
        OutIt merge(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x,Pred pr);
        - 用pr作比较器
            - 把[first1,last1),[first2,last2)两个升序序列合并，
              形成第3个升序序列，第3个升序序列以x开头
    - set_union 将两个有序区间的并拷贝到第三个区间
        template<class InIt1,class InIt2,class OutIt>
        OutIt set_union(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x);
        - 用<比较器
        template<class InIt1,class InIt2,class OutIt,class Pred>
        OutIt set_union(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x,Pred pr);  
        - 用pr(x,y)比较
        -求两个区间的并，放到以x开始的位置
        - 若某个元素e在[first1,last1)里出现n1次，在[first2,last2)里出现n2次，则该元素在目标区间里出现max(n1,n2)次
    - set_intersection 将两个有序区间的交拷贝到第三个区间
        template<class InIt1,class InIt2,class OutIt>
        OutIt set_intersection(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x);
        template<class InIt1,class InIt2,class OutIt,class Pred>
        OutIt set_intersection(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x,Pred pr);
        - 求出[first1,last1)和[first2,last2)中共有的元素，放到从x开始的地方
        - 若某个元素e在[first1,last1)里出现n1次，在[first2,last2)里出现n2次，则该元素在目标区间里出现min(n1,n2)次
    - set_difference 将两个有序区间的差拷贝到第三个区间
        template<class InIt1,class InIt2,class OutIt>
        OutIt set_difference(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x);
        template<class InIt1,class InIt2,class OutIt,class Pred>
        OutIt set_difference(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x,Pred pr);
        - 求出[first1,last1)中，不在[first2,last2)中的元素，放到从x开始的地方
        - 如果[first1,last1)里有多个相等元素不在[first2,last2)中，则这多个元素也都会被放入x代表的目标区间里
    - set_symmetric_difference 将两个有序区间的对称差拷贝到第三个区间
        template<class InIt1,class InIt2,class OutIt>
        OutIt set_symmetric_difference(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x);
        template<class InIt1,class InIt2,class OutIt,class Pred>
        OutIt set_symmetric_difference(InIt1 first1,InIt1 last1,InIt2 first2,InIt2 last2,OutIt x,Pred pr);
        - 把两个区间里相互不在另一区间里的元素放入x开始的地方
    - inplace_merge  将两个连续的有序区间原地合并为一个有序区间

*/


/*bitset类模板
template <size_t N>
class bitset{
    ...
};
- 实际使用的时候，N是个整型常数
- 如：
    - bitset<40> bst;
    - bst是一个由40位组成的对象
    - 用bitset的函数可以方便地访问任何一位
- bitset的成员函数
    - bitset<N>&operator&=(const bitset<N>& rhs);
    - bitset<N>&operator|=(const bitset<N>& rhs);
    - bitset<N>&operator^=(const bitset<N>& rhs);
    - bitset<N>&operator<<=(size_t num);
    - bitset<N>&operator>>=(size_t num);
    - bitset<N>&set();//全部设成1
    - bitset<N>&set(size_t pos,bool val =true);//设置某位
    - bitset<N>&reset();//全部设成0
    - bitset<N>&reset(size_t pos);//某位设成0
    - bitset<N>&flip();//全部翻转
    - bitset<N>&flip(size_t pos);//翻转某位

    - reference operator[](size_t pos);//返回对某位的引用
    - bool operator[](size_t pos)const;//判断某位是否为1
    - reference at(size_t pos);
    - bool at(size_t pos)const;
    - unsigned long to_ulong()const;//转换成整数
    - string to_string()const;//转换成字符串
    - size_t count()const;//计算1的个数
    - size_t size()const;
    - bool operator==(const bitset<N>&rhs)const;
    - bool operator!=(const bitset<N>&rhs)const;

    - bool test(size_t pos) const;//测试某位是否为1
    - bool any() const;//是否由某位为1
    - bool none() const;//是否全部为0
    - bitset<N> operator<<(size_t pos) const;
    - bitset<N> operator>>(size_t pos) const;
    - bitset<N> operator~();
    - static const size_t bitset_size = N;
    //注意第0位在最右边
*/