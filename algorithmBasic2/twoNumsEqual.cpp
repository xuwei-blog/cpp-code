#include <iostream>
using namespace std;
/* 输入n个整数（n<=100,000)，找出其中两个数，
它们之和等于整数m
题解:解法一：双重循环会超时，不合适
     解法二：1.先将数组排序，复杂度nlogn
            2.遍历a[i]，二分查找m-a[i]，一共查n-2次
            最后一次只需判断 An-1 + An == 0
            复杂度nlogn
            总的复杂度 n logn
     解法三：1.先将数组排序
            2.设置两个变量head、tail，
            如果a[head] + a[tail]  >   m ，tail--
            如果a[head] + a[tail]  >   m , head++
            直到相等
            复杂度 n
            总的复杂度 n logn
*/
//代码很简单，有时间再补，没时间就不补了
