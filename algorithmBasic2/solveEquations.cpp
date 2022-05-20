#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
/* 求f(x) = x^3 - 4x^2 + 10x -80 的根
只能求出近似值 |f(a)| <= 10^-6
方程必须单调
已知  f(0)<0  f(100)>0
*/
double EPS = 0.000001;
double f(double x){
    return x*x*x - 5*x*x + 10*x -80;
}
int main(){
    double root, x1 = 0, x2 = 100 , y;
    root = x1 + (x2-x1) / 2; //中间值
    int triedTimes = 1; 
    y = f(root); //记录算了几次
    while(fabs(y) >EPS){
        if(y>0)
            x2 = root;
        else
            x1 = root ;
        root = x1 + (x2-x1)/2;
        y = f(root);
        triedTimes ++ ;
    }
    printf("%.8f\n",root);
    printf("%d",triedTimes);


    system("pause");
    return 0;
}
