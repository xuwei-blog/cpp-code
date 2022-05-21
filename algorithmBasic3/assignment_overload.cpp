#include <iostream>
#include <cstring>
using namespace std;
/*赋值运算符重载
1.赋值运算符‘=’只能重载为成员函数

*/
class String{
    private:
        char * str; //动态分配
    public:
        String ():str(new char[1]){str[0] = 0;}
        const char * c_str(){return str;}
        String & operator = (const char * s);
        ~String (){delete [] str;}
        String(String & s){//同时也要重载复制构造 避免缺省的复制构造让str重复指向
            str = new char[strlen(s.str)+1];
            strcpy(str,s.str);
        }
};
/*返回值为String & 可以保留运算符原本的特性
a = b = c
等价于 a.operator=(b.operator=(c))
(a=b)=c
等价于 (a.operator=(b)).operator=(c)
*/
String & String::operator = (const char * s){//形参是常量类型
    //重载‘=’，使得obj = “hello” 成立
    delete [] str;
    str = new char[strlen(s) + 1];//+1为了放\0
    strcpy(str , s);
    return * this;
}
int main(){
    String s;
    s = "good luck"; //等价于 s.operator=("good luck");
    cout << s.c_str() << endl;
    //String s2 = "hello"; err 没有写构造函数
    s = "nihao";//等价于 s.operator=("nihao");
    cout << s.c_str() << endl;
    
    system("pause");
    return 0;
}