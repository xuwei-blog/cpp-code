#include <iostream>
#include <cmath>
using namespace std;
/*题目描述：给出4个小于10的正整数，用加减乘除4种运算以及括号
把这4个数连接起来得到一个表达式。判断是否存在一种方式
使得得到的表达式结果为24
例：5，5，5，1  ===》  5 *（ 5 - 1 / 5 ） = 24
题解：枚举第一步 取两个数运算
            运算结果和剩下的n-2个数运算，求24
            运算结果再和剩下的n-3个数运算，求24

边界条件:一个数算24
浮点数不能用==
*/
double a[5];
#define EPS 0.000001 //定义一个极小数
bool isZero(double x)
{
    return fabs(x) <= EPS;
}
bool count24(double a[], int n)
{
    if (n == 1)
    {
        if (isZero(a[0] - 24))
            return true;
        else
            return false;
    }
    double b[5]; //存放中间结果
    for (int i = 0; i < n - 1; i++)
    { //先取出2个数运算，结果再和n-2个数求24
        for (int j = i + 1; j < n; j++)
        {              //双重循环取两个数a[i]和a[j]
            int m = 0; //还剩下m个数，m = n-2
            for (int k = 0; k < n; k++)
            { //把没有选出来的2个数放到b[]
                if (k != i && k != j)
                    b[m++] = a[k];
            }
            b[m] = a[i] + a[j];
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] - a[j]; //减法有两种形式
            if (count24(b, m + 1))
                return true;
            b[m] = a[j] - a[i]; //减法有两种形式
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] * a[j];
            if (count24(b, m + 1))
                return true;
            if (!isZero(a[j]))
            {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1))
                    return true;
            }
            if (!isZero(a[i]))
            {
                b[m] = a[j] / a[i];
                if (count24(b, m + 1))
                    return true;
            }
        }
        return false;
    }
}

int main()
{
    int i = 0;
    do
    {
        cin >> a[i];
    } while (i++ < 3);
    if (count24(a, 4))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    system("pause");
    return 0;
}