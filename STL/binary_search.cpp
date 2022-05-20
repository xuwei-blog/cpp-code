#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int a[] = {12,45,6,29,5};
    sort(a,a+5);
    for(int i =0 ;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"result:"<<binary_search(a,a+5,45)<<endl;
    cout<<"result:"<<binary_search(a,a+5,24)<<endl;
    system("pause");
    return 0;
}