#include <iostream>
#include <set>
using namespace std;
/*set

template <class Key,class Pred = less<key>,class A = allocator<key>>
class set{
    ;
};
*/

int main(){
    typedef set<int>::iterator IT;
    int a[5] = {3,4,6,1,2};
    set<int> st(a,a+5);
    pair<IT,bool> result;
    result =  st.insert(5);
    if(result.second)
        cout << *result.first << " inserted" <<endl;
    if(st.insert(5).second) //再插入一个5
        cout << *result.first <<endl;
    else   
        cout << *result.first << " already exists" << endl;
        
    pair<IT,IT> bounds = st.equal_range(4);
    cout << *bounds.first << "," << *bounds.second ;

    system("pause");
    return 0;
}