#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a[5] = {1,2,3,2,5};
    int b[6] = {1,2,3,2,5,6};
    ostream_iterator<int> oit(cout,",");
    int *p = remove(a,a+5,2);
    cout << "1) ";
    copy(a,a+5,oit);
    //1 空 3 空 5
    //1 3 空 空 5
    //1 3 5 空 空
    //1 3 5 2 5
    //*p指向2
    cout <<endl;

    cout << "2) " << p-a << endl; //p和a之间有3个元素
    vector<int> v(b,b+6);
    remove(v.begin(),v.end(),2);
    cout << "3) ";//1 3 5 6 5 6
    copy(v.begin(),v.end(),oit);
    cout << endl;

    cout << "4) ";
    cout << v.size() <<endl;
    //remove之后 个数没有少
    system("pause");
    return 0;

}