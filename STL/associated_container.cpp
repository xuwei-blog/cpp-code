#include <iostream>
using namespace std;

/*关联容器
- 内部元素有序排列，新元素插入的位置取决于它的值，查找速度快
- 除了各容器都有的函数外，还支持以下成员函数
 - find 查找等于某个值的元素(x小于y和y小于x同时不成立 即为找到)
 - lower_bound 查找某个下界
 - upper_bound 查找某个上届
 - equal_range 同时查找上届和下界
 - count  计算等于某个值的元素个数(x小于y和y小于x同时不成立 即为符合条件)
 - insert 用以插入一个元素或一个区间
 */

/*pair模板
- map/multimap容器里放着的都是pair模板类的对象，且按照first从小到大排序

//pair模板的实现
template <class _T1,class _T2>
struct pair{
    typedef _T1 first_type;
    typedef _T2 second_type;
    _T1 first;
    _T2 second;
    pair():first(),second(){} //fist如果是基本类型()初始化也没问题
    pair(const _T1&__a,const T&2__b):first(__a),second(__b){}
    template<class _U1,class _U2>
    pair(const pair<_U1,_U2>&__p):first(__p.first),second(__p.second){}
};
int main(){
    pair<int,int> p(pair<double,double>(5.5,4.6));  //p.first = 5 , p.second = 4
    system("pause");
    return 0;
}
*/
