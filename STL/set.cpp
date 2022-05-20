#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
struct rule1
{ //按个位数从小到大排列
    bool operator()(const int &a1, const int &a2) const
    {
        return a1 % 10 < a2 % 10; //此处自定义规则
    }
};
int main()
{
    //set和multiset区别 ：容器里不能有重复元素
    //a和b重复   <==>   a排在b前面 和 b排在a前面   都不成立
    //set插入元素可能不成功
    //常规用法 
    set<int> st;//排序规则没说 就是 从小到大
    int a[10] = {12,45,6,29,2,4,12,12,5,6};
    for(int i =0;i<10;i++){
        st.insert(a[i]);
    }
    cout<< st.size()<<endl;  //7
    set<int> :: iterator i ;
    for(i = st.begin();i!=st.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    //插入元素 需要判断是否成功
    /*   pair<T1,T2>  a等价于 匿名结构体
    struct{
        T1 first;
        T2 second;
    }a;
    */
    pair<set<int>::iterator,bool> result = st.insert(2); 
    if(! result.second){
        cout<<*result.first<<" already exists"<<endl;
    }
    else{
        cout<<*result.first<<" inserted"<<endl;
    }

    system("pause");
    return 0;
}