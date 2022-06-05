#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Lambda表达式
int main(){
    //Lambda表达式的用法
    int x =100,y=200,z=300;
    cout <<[](double a,double b){return a+b;}(1.2,2.5)<<endl;
    auto ff =[=,&y,&z](int n){
        cout << x << endl;
        y++;
        z++;
        return n*n;
    };
    cout << ff(15) << endl;
    cout << y << "," << z << endl;

    //Lambda表达式的优势
    int a[4]= {4,2,1,33};
    sort(a,a+4,[](int x,int y)->bool {return x%10 <y%10;});
    for_each(a,a+4,[](int x){cout << x << " ";});
    cout << endl;
    //再来个例子
    vector<int> arr{1,2,3,4};
    int total =0;
    for_each(arr.begin(),arr.end(),[&](int& x){total += x;x*=2;});
    cout << total << endl;
    for_each(arr.begin(),arr.end(),[](int x){cout << x << " ";});

    //lambda表达式实现递归(未实现)
    function<int(int)> fib = [&](int n){
        return n <= 2 ? 1 : fib(n-1) + fib(n-2);
    };
    cout << fib(5) <<endl;
    system("pause");
    return 0;
}