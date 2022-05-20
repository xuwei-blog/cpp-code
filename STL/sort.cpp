#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct rule1
{ //从大到小排列
    bool operator()(const int &a1, const int &a2) const
    {
        return a1 > a2; //此处自定义规则
    }
};
struct rule2
{ //从小到大排列
    bool operator()(const int &a1, const int &a2) const
    {
        return a1 < a2; //此处自定义规则
    }
};
struct rule3
{ //按个位数从小到大排列
    bool operator()(const int &a1, const int &a2) const
    {
        return a1 % 10 < a2 % 10; //此处自定义规则
    }
};
struct student{
    char name[20];
    int age;
    double gpa;
};
struct studentRule1
{ //按姓名从小到大排序
    bool operator()(const student &s1, const student &s2) const
    {
        if(strcmp(s1.name,s2.name)<0)
            return true;
        return false; //此处自定义规则
    }
};
struct studentRule2
{ //按年龄从大到小排序
    bool operator()(const student &s1, const student &s2) const
    {
        return s1.age<s2.age; //此处自定义规则
    }
};
void PrintStudent(student s[],int size){
    for(int i=0;i<size;i++){
        cout<<"("<<s[i].name<<","
        <<s[i].age<<","<<s[i].gpa<<")";
    }
    cout<<endl;
}
int main()
{
    //对数组的排序
    int a[] = {15, 3, 4, 51, 32, 27, 3, 6};
    sort(a, a + 6);                 //从小到大
    sort(a, a + 6, greater<int>()); //从大到小排序
    sort(a, a + 6, rule3());        // 自定义规则排序
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << a[i] << " ";
    // }
    
    //对结构体的排序
    student students[] ={{"marry",17,3.24},
        {"bean",39,4.24},{"marry",19,3.24},
        {"kitty",15,2.57},{"Ppy",22,7.24}
    };
    int n  = sizeof(students)/sizeof(students[0]);
    sort(students,students+n,studentRule1());
    sort(students,students+n,studentRule2());
    PrintStudent(students,n);
    system("pause");
    return 0;
}