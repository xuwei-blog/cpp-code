#include <iostream>
#include <regex>
using namespace std;
//正则表达式 cpp11
int main(){
    regex reg("b.?p.*k");  //.任意字符 ？出现0次或1次 *出现0次或多次
    cout << regex_match("bopggk",reg) << endl; //输出1 表示匹配成功
    cout << regex_match("boopgggk",reg) << endl; //输出0 表示匹配失败
    cout << regex_match("b pk",reg) << endl; //输出1 表示匹配成功
    regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
    // \d:0~9 {x}出现x次 [a-zA-Z]字母项 +出现1次或多次 \s空格 \1第一项
    string correct = "123Hello N/A Hello"; 
    string incorrect = "123Hello 12 hello";// 第一项不匹配
    cout << regex_match(correct,reg2) << endl;   //输出1 表示匹配成功
    cout << regex_match(incorrect,reg2) << endl; //输出0 表示匹配失败

    system("pause");
    return 0;
    
}