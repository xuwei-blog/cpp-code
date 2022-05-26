#include <iostream>
using namespace std;

/*类模板与static成员
- 类模板中可以定义静态成员，那么从该类模板实例化得到的所有类，都包含同样的静态成员
*/
template <class T>
class A{
    private:
        static int count;
    public:
        A(){count++;}
        ~A(){count--;}
        A(A&){count++;}
        static void PrintCount(){cout<<count<<endl;}
};
//使用静态成员时都要再声明一次
template<> int A<int>::count = 0;
template<> int A<double>::count = 0;
int main(){
    A<int> ia;
    A<double> da;
    ia.PrintCount();
    da.PrintCount();
    system("pause");
    return 0;
}
