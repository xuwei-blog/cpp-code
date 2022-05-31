#include <iostream>
#include <algorithm>
using namespace std;

//max_element和min_element
class A{
    public:
        int n;
    A(int i):n(i){}
};
bool operator < (const A& a1,const A& a2){
    cout << "called" <<endl;
    if(a1.n==3 && a2.n ==7)   //3 < 7才是true，任何两个对象比大小，除非一个是3，另一个是7，才是ture
        return true;
    return false;
}
int main(){
    A a[] = {3,5,7,2,1};
    cout << min_element(a,a+5)->n << endl;  //5<3  7<3
    cout << max_element(a,a+5)->n << endl;  //3<5  3<7
    system("pause");
    return 0;

}