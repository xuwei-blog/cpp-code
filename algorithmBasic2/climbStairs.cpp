#include <iostream>
using namespace std;
/*爬楼梯题解：
n级台阶的走法 = 先走一级后，n-1级台阶的走法 +
               先走两级后，n-2级台阶的走法
               f(n) = f(n-1) + f(n-2)
边界条件： n < 0 有0种走法
          n = 0 有1种走法
*/
int N;
int stairs(int n){
    if( n < 0 ){//没有走法
        return 0;
    }
    if( n == 0 ){//呆在原地
        return 1;
    }
    return stairs(n-1) + stairs(n-2);
}

int main(){
    while(cin>>N){
        cout<<stairs(N)<<endl;
    }
    system("pause");
    return 0;
}