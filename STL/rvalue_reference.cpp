#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String{
    public:
        char* str;
        String():str(new char[1]){str[0]=0;}
        String(const char * s){
            str = new char[strlen(s)+1];
            strcpy(str,s);
        }
        String(const String & s){
            cout << "copy constructor called" << endl;
            str = new char[strlen(s.str)+1];
            strcpy(str,s.str);
        }

        //用于两个对象之间的赋值（深拷贝）
        String & operator=(const String & s){
            cout << "copy operator=called"<<endl;
            if(str!= s.str){
                delete[]str;
                str = new char[strlen(s.str)+1];
                strcpy(str,s.str);
            }
            return *this;
        }
        //move constructor 移动构造函数
        String(String && s):str(s.str){
            cout << "move constructor called" << endl;
            s.str = new char[1];
            s.str[0] = 0;
        }

        //move assigment
        String & operator = (String && s){
            cout << "move operator = called" << endl;
            if(str!=s.str){
                delete []str;
                str = s.str;
                s.str = new char[1];
                s.str[0] = 0;
            }
            return *this;
        }
        ~String(){delete [] str;}
};
template<class T>
void MoveSwap(T& a,T& b){//会改变a的值 ，如果a是临时变量 就 无所谓
    T tmp(move(a)); //std::move(a)为右值，这里会调用移动构造函数
    a = move(b);  //move(b)为右值,因此会调用move assigment
    b = move(tmp); //move(tmp)为右值，会调用move assigment
}
int main(){
    //String & r = String("this"); //err 左边是左值引用 右边是右值
    String s;
    s = String("ok"); //String("ok")是右值
    cout << "****" << endl;
    String && r = String("this");
    cout << r.str << endl;
    String s1 = "hello",s2 = "world";
    MoveSwap(s1,s2);
    cout << s2.str << endl;

    system("pause");
    return 0;
}