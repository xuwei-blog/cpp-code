#include <iostream>
using namespace std;
class Demo{
        int id;
    public:
        Demo(int i){
            id = i;
            cout<<"id"<<id<<" constructor"<<endl;
        }
        ~Demo(){
            cout<<"id"<<id<<" destructor"<<endl;
        }
};
Demo d1(1);
void Func(){
    static Demo d2(2);
    Demo d3(3);
    cout<<"func"<<endl;
}
int main(){
    Demo d4(4);
    d4 = 6;
    cout<<"main"<<endl;
    {
        Demo d5(5);
    }
    Func();
    cout<<"main ends"<<endl;
    system("pause");
    return 0;
}


/*调试结果 （可能是vscode设置问题  显示的有问题）
id1 constructor
id4 constructor
id6 constructor
id6 destructor
main
id5 constructor
id5 destructor
id2 constructor
id3 constructor
func
id3 destructor
main ends
//后续应该还要有
id6 destructor
id2 destructor
id1 destructor
*/