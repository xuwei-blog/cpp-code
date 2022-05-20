#include <iostream>
#include <algorithm>
#include <cstring>
#include <set> //使用multiset  和  set  需要引用
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
    // //multiset作用 插入、删除、查找 logN复杂度
    // int a[8] = {12, 45, 6, 27, 5, 53, 24, 8};
    // multiset<int> st; //排序容器
    // for(int i =0;i<8;i++){
    //     st.insert(a[i]);
    // }
    // //5,6,8,12,13,24,27,45,53
    // multiset<int>::iterator i; //iterator是迭代器
    // // for(i = st.begin() ; i != st.end(); i++){
    // //     cout<<*i<<" ";
    // // }
    // // cout<<endl;
    // i = st.find(13);
    // if(i == st.end())
    //     cout<<"not found"<<endl;
    // st.insert(13);  //容器里插入13
    // i = st.find(13); //容器函数的返回值 就是 一个迭代器
    // if(i == st.end())
    //     cout<<"not found"<<endl;
    // else{
    //     cout<<"found:"<< *i <<endl;
    // }
    // //查找
    // i = st.lower_bound(13); //容器的函数
    // cout<<*i<<endl;
    // i = st.upper_bound(8);
    // cout<<*i<<endl;

    // //删除
    // //5,6,8,12,13,24,27,45,53
    // st.erase(i); //删除12

    //自定义排序 （以上代码注释掉 再使用）
    multiset<int, greater<int>> st; //从大到小排序
    int a[10] = {12, 45, 6, 3, 2, 88, 27, 5, 53, 24};
    for (int i = 0; i < 10; i++)
    {
        st.insert(a[i]);
    }
    // 5,6,8,12,13,24,27,45,53
    multiset<int,greater<int> >::iterator i; // iterator是迭代器
    for(i = st.begin() ; i != st.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    i = st.find(111);   //find不是查找相等的元素
                        //而是查找排前面或者后面都可以的元素
                        //比如student结构体变量 在rule比较成绩的规则下
                        //成绩相同，其他不同的人有3个 
                        //那么这3个就是同一个
    cout<<*i<<endl;
    system("pause");
    return 0;
}