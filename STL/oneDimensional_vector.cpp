#include <iostream>
#include <vector>
using namespace std;
template <class T>
void PrintVector(T s, T e){
    for(;s != e;++s)
        cout << * s<<" ";
    cout << endl;
}
int main(){
    int a[5] = {1,2,3,4,5};
    vector<int> v(a,a+5);
    cout << "1) " << v.end() - v.begin() <<endl;
    cout << "2) " ;
    PrintVector(v.begin(),v.end());
    v.insert(v.begin()+2,13);
    cout << "3) ";
    PrintVector(v.begin(),v.end());
    v.erase(v.begin()+2);
    cout << "4) ";
    PrintVector(v.begin(),v.end());
    vector<int> v2(4,100); //v2有4个元素，都是100
    v2.insert(v2.begin(),v.begin()+1,v.begin()+3);
    cout << "5) ";
    PrintVector(v2.begin(),v2.end());
    v.erase(v.begin()+1,v.begin()+3);
    cout << "6) " ;
    PrintVector(v.begin(),v.end());

    system("pause");
    return 0;
}