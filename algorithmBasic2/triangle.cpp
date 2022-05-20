#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
/*题目描述：从三角形顶部到三角形底部的最长路径
例      7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
三角形行数大于1 小于等于100
思路：用二维数组存放数字三角形
D(r,j) : 第r行第j个数字(r,j=1,2,3...)
MaxSum(r,j):从D(r,j)到底边各条路径种，最长路径之和
题解：方法一：递归(超时)
    D(r,j)从(1,1)出发，下一步只能走D(r+1,j)或者D(r+1,j+1)
    if(r == N)
        MaxSum(r,j) = D(r,j)
    else
        MaxSum(r,j) = Max{MaxSum(r+1,j) ,MaxSum(r+1,j+1)} + D(r,j)
代码：
int D[MAX][MAX];
int n;
int MaxSum(int i,int j){
    if( i == n)
        return D[i][j];
    int x = MaxSum(i+1,j);
    int y = MaxSum(i+1,j+1);
    return max(x,y)+D[i][j];
}
int main(){
    int i,j;
    cin>>n;
    for(i = 1;i<=n;i++){
        for(j=1;j<=i;j++){
            cin>>D[i][j];
        }
    }
    cout << MaxSum(1,1)<<endl;
}
*/
/*解法二：动态规划
避免重复计算
代码：
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int MaxSum(int i, int j)
{
    if (maxSum[i][j] != -1)//不是-1，说明已经算过
        return maxSum[j][j];
    if (i == n)
        maxSum[i][j] = D[i][j];
    else
    {
        int x = MaxSum(i + 1, j);
        int y = MaxSum(i + 1, j + 1);
        maxSum[i][j] = max(x, y) + D[i][j];
    }
    return maxSum[i][j];
}
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cin >> D[i][j];
            maxSum[i][j] = -1;//初始化为-1
        }
    }
    cout << MaxSum(1, 1) << endl;
    system("pause");
    return 0;
}
*/
/*解法三：递推(从下至上)
注意：此解法还可以空间优化，用一维数组代替二维数组
    甚至maxSum都可以不要，直接存在D[n]
代码：
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int main(){
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++)
            cin >> D[i][j];
    }
    for(i=1;i<=n;i++)
        maxSum[n][i] = D[n][i];
    for(i=n-1;i>=1;i--)
        for(int j =1;j<=i;j++){
            maxSum[i][j] = 
                max(maxSum[i+1][j],maxSum[i+1][j+1]) +D[i][j];
        }
    cout << maxSum[1][1] <<endl;//递推到顶尖，就是路径最大的和
    system("pause");
    return 0;
}
*/