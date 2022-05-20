#include <iostream>
using namespace std;
//在排好序的数组里，查找比p小的最大数的下标
int lower_bound(int a[], int size, int p)
{
    int L = 0;
    int R = size - 1;
    int lastPos = -1;
    while (L <= R)
    {
        //int mid = (L + R) / 2;
        int mid = L + (R - L) / 2 ; //防止L+R溢出
        if (a[mid] >= p)
            R = mid - 1;
        else
        {
            lastPos = mid;
            L = mid + 1;
        }
    }
    return lastPos;
}
int main()
{
    int a[] = {4, 5, 9, 33, 56, 89, 333, 357, 1256};
    int size = sizeof(a) / sizeof(a[0]);
    int p = 9;
    cout << lower_bound(a, size, p) << endl;

    system("pause");
    return 0;
}
