#include <iostream>
using namespace std;
class A{
        int i;
    public:
        void Hello(){
            cout <<"hello"<<endl;
        }//好似cpp先编译成c
        //void Hello(A* this){cout<<"hello"<<endl;}

        void HHello(){
            cout << i <<"hello"<<endl;
        }//好似cpp先编译成c
        //void HHello(A* this){cout << this->i << "hello" <<endl;}
                                     //问题在上面
};
int main(){
    A*p = NULL;
    p->Hello();//输出hello

    A*q = NULL;
    p->HHello(); //等同于 Hello(p);  报错

    system("pause");
    return 0;
}