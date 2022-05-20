#include <iostream>
using namespace std;
int Binaey_search(int a[],int size,int p){
    int L = 0;
    int R = size - 1;
    while(L<=R){
        //int mid = (L + R) / 2;
        int mid = L + (R - L) / 2 ; //防止L+R溢出
        if( p == a[mid] )
            return mid;
        else if( p > a[mid])
            L = mid + 1;
        else 
            R = mid - 1;
    }
    return -1;
}

int main(){
    int a[] ={4,5,9,33,56,89,333,357,1256};
    int size = sizeof(a) / sizeof(a[0]);
    int p =9;
    cout << Binaey_search(a,size,p);
    
    system("pause");
    return 0;
}
