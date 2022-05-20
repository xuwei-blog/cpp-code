#include <iostream>
using namespace std;
/*输出n个数中前m大的数
解法1：排序再输出nlogn
解法2：分治n+mlogm
    思路：
    把前m大的都放到数组最右边，
    再对最右边m个数排序，再输出
arrangeRight(k):把数组（或数组一部分）
前k大的都放到最右边
1.key=a[0]，key左边比key小
            key右边比key大
2.选择key前，或key后再次arrangeRight
分3种情况 一、key及其右边 = k
         二、key及其右边 > k , 数多了，则一个个减少
         对key及其右边的个数 - 1 
         再进行arrageRight(k)
         三、key及其右边 < k ，数少了，则左边的数放过来
         arrageRight( k - key及其右边个数 )
*/
//有时间再补代码