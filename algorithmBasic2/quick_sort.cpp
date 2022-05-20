#include <iostream>
using namespace std;
void swap(int & a ,int & b){
    int tmp = a;
    a = b;
    b = tmp;
}
void quick_sort(int a[],int s ,int e){
    if(s >= e)
        return ;
    int k = a[s]; 
    int i = s;
    int j = e;
    while(i != j){
        while(j > i && a[j] >= k)
            j--;
        swap(a[i],a[j]);
        while( i < j && a[i] <= k)
            i++;
        swap(a[i],a[j]);
    }//处理完后，a[i] = k
    quick_sort(a,s,i-1);
    quick_sort(a,i+1,e);
}
int a[] = {93,27,30,2,8,12,2,8,30,89};
int main(){
    int size = sizeof(a) / sizeof(a[0]);
    quick_sort(a,0,size-1);
    for(int i =0;i<size;i++)
        cout<<a[i] <<" ";
    cout<< endl;
    system("pause");
    return 0;
}