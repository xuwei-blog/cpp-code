#include <iostream>
#include <memory>
using namespace std;
int main(){
    int* p1= NULL;
    int* p2= nullptr;
    shared_ptr<double> p3 =nullptr;
    if(p1 == p2)
        cout << "equal 1" << endl;
    if(p3 == nullptr)
        cout << "equal 2" << endl;
    //if(p3 == p2); //err  指针类型不匹配
    if(p3 == NULL)
        cout << "equal 4" <<endl;
    bool b = nullptr;  //b=false  cpp11新特性
    //int i = nullptr;  //err 不能转换成整型

    system("pause");
    return 0;
}