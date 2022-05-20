#include <iostream>
#include <cmath>
using namespace std;
//波兰表达式，又称前缀表达式
double polishNotation(){
    char str[20]; //自己的理解：每次进入函数，都只会读一个字符，不需要数组
    cin >> str;
    switch(str[0]){
        case '+':
            return polishNotation() + polishNotation();
            break;
        case '-':
            return polishNotation() - polishNotation();
            break;
        case '*':
            return polishNotation() * polishNotation();
            break;
        case '/':
            return polishNotation() / polishNotation();
            break;
        default:
            return atof(str);//字符串转换成浮点数
    }
}
int main(){
    printf("%lf",polishNotation());
    system("pause");
    return 0;
}