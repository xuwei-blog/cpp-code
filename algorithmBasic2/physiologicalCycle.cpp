#include <iostream>
#include <cstdio>
using namespace std;
//体力高峰23天一次，情商高峰28天一次，智力高峰33天一次
//求3个高峰在同一天的日子
//枚举解法1：(k-p)%23==0 && (k-e)%28==0 && (k-i)%33==0
//枚举解法2：先找出第一个体力高峰，按照体力高峰周期找
int main(){
    int p,e,i,d,caseNo=0;
     while(cin >>p>>e>>i>>d&&p!=-1){
        caseNo++;
        int k ;
        for(k=d+1;(k-p)%23;k++);
        for(;(k-e)%28;k+=23);//++体力高峰
        for(;(k-i)%33;k+=23*28);//++体力情商双高峰
        cout<<"Case "<<caseNo<<
        ":the next triple peak occurs in "<<
        k-d<<"day"<<endl;
    }
    system("pause");
    return 0;
}