#include <iostream>
using namespace std;
/*求排列的逆序数
解法1：双重循环遍历 nn
解法2：分治nlogn
一、将数组分成两份，分别求出左、右两边的逆序数
二、再算左半边与右半边各取一个数，形成的逆序

*/