#include <iostream>
using namespace std;
/*有m个苹果，n个盘子，把苹果放到盘子里有多少种放法
题解：情况1：n大于m，盘子大于苹果
            n-m个盘子不需要考虑
            只考虑m个苹果放到m个盘子里
            f(m,n) = f(m,m)
      情况2:n小于等于m，盘子小于等于苹果
            再分两类：
            第一类：有盘子为空，至少一个盘子为空
            第二类：盘子不为空，每个盘子先放一个苹果
            f(m,n) = f(m,k-1) + f(m-k,k)
边界条件：苹果等于0，有1种方法
         盘子等于0，有0种方法
*/
int f(int m,int n){
    if(n>m)
        return f(m,m);
    if(m == 0)
        return 1;
    if(n == 0)
        return 0;
    return f(m,n-1)+f(m-n,n);//触发递归
}
int main(){
    int t,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    }

    system("pause");
    return 0;
}