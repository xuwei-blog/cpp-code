#include <iostream>
using namespace std;
/*流插入运算符的重载<<


//为了实现 cout << 5 << "this";
//等同于 cout.operator<<(5).operator<<("this");
//返回值为ostream &
//ostream是类  cout是实例化的对象
ostream & ostream::operator<<(int n){
    ;;;
    return * this;
}
ostream & ostream::operator<<(const char *s){
    ;;;
    return * this;
}
*/
class CStudent{
    public:
        int nAge;
};
ostream & operator<<(ostream & o,const CStudent & s){
    o << s.nAge;
    return o;
}
int main(){
    CStudent s;
    s.nAge = 5;
    cout << s << "hello";
    system("pause");
    return 0;
}