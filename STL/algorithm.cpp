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


