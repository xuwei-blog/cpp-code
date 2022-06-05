#include <iostream>
#include <vector>
using namespace std;
struct A{
    int n;
    A(int i):n(i){}
};
int main(){
    int ary[] = {1,2,3,4,5};
    for(int & e:ary) //e是元素 ary是范围
        e *= 10;
    for(int e:ary)
        cout << e << ",";
    cout <<endl;

    vector<A> st(ary,ary+5);
    for(auto & it:st)//it是元素 st是范围
        it.n *= 10 ;
    for(A it:st)
        cout << it.n << ",";

    system("pause");
    return 0;
}
