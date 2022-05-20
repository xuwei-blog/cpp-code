#include <iostream>
using namespace std;
//归并排序
int a[] = {13, 27, 19, 2, 8, 30, 89};
int b[10];
void merge(int a[], int s, int m, int e, int tmp[])
{
    int pb = 0;     //指向存放结果的指针
    int p1 = s;     //指向前一半的指针
    int p2 = m + 1; //指向后一半的指针
    while (p1 <= m && p2 <= e)
    {
        if (a[p1] < a[p2])
            tmp[pb++] = a[p1++];
        else
            tmp[pb++] = a[p2++];
    }
    while (p1 <= m)
        tmp[pb++] = a[p1++];
    while (p2 <= e)
        tmp[pb++] = a[p2++];
    for (int i = 0; i < e - s + 1; i++)
        a[s + i] = tmp[i];
}
void merge_sort(int a[], int s, int e, int tmp[])
{
    if (s < e)
    {                            //若s == e ，等同于只排序一个元素
        int m = s + (e - s) / 2; //分成两部分
        merge_sort(a, s, m, tmp);
        merge_sort(a, m + 1, e, tmp);
        merge(a, s, m, e, tmp); //整合两部分
    }
}
int main()
{
    int size = sizeof(a) / sizeof(a[0]);
    merge_sort(a, 0, size - 1, b);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}