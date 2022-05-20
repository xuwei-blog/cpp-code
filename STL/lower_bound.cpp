#include <iostream>
#include <algorithm>
#include <cstring>
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
    //常规用法
    // int a[] = {12,45,6,29,5};
    // sort(a,a+5);//5,6,12,29,45
    // int *p=lower_bound(a,a+5,5); //大于等于,下界
    // cout<< *p <<","<< p-a <<endl;
    // p=upper_bound(a,a+5,5); //大于,上界
    // cout<< *p <<","<< p-a <<endl;
    // cout<< *upper_bound(a,a+5,5)<<endl;

    //按规则查找
    int a[] = {12, 45, 6, 27, 5, 53, 24, 8};
    sort(a, a + 8, rule1()); // 12,53,24,5,45,6,27,8
    // for(int i =0;i<8;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int *p = lower_bound(a, a + 8, 27, rule1()); //大于等于,下界
    cout << *p << "," << p - a << endl;
    p = upper_bound(a, a + 8, 29, rule1()); //大于,上界
    cout << *p << "," << p - a << endl;
    cout << *upper_bound(a, a + 8, 16, rule1()) << endl;
    system("pause");
    return 0;
}