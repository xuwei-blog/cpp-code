#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*string类
- string类时模板类：
    typedef basic_string<char> string;
- 使用string类要包含头文件<string>
- string对象的初始化
    - string s1("hello");
    - string month = "March";
    - string s2(8,'x');
-  错误的初始化方式：
    - string err1 = 'c';
    - string err2('u);
    - string err3 = 22;
    - string err4(8);
- 可以将字符赋值给string对象
    string s;
    s = 'n';

//string类示例
int main(int argc,char* argv[]){
    string s1("hello");
    cout << s1 << endl;
    string s2(8,'x');
    cout << s2 << endl;
    string month = "March";
    cout << month << endl;
    string s;
    s = 'n';
    cout << s << endl;
    system("pause");
    return 0;
}
*/

/*string类的常用操作
- string对象的长度用成员函数length()读取
    string s("hello");
    cout << s.length() << endl;
- string支持流读取运算符
    string stringObject;
    cin >> stringObject;
- string支持getline函数
    string s;
    getline(cin,s);
- 用 = 赋值
    string s1("cat"),s2;
    s2 = s1;
- 用assign成员函数赋值
    string s1("cat"),s3;
    s3.assign(s1);
- 用assign成员函数部分复制
    string s1("catpig"),s3;
    s3.assign(s1,1,3);
- 单个字符的复制
    s2[5] = s1[3] ='a';
- 逐个访问string对象中的字符
    string s1("hello");
    for(int i =0 ;s1.length();++i)
        cout << s1.at(i) << endl;
- 成员函数at会做 范围检查 ，如果超出范围，会抛出out_of_range异常，而下标运算符[]不做范围检查
*/

/*string的赋值和连接
- 用+运算符连接字符串
    string s1("good"),s2("morning");
    s1 = s1 + s2 ;
    cout << s1;
- 用成员函数append连接字符串
    string s1("good"),s2("morning");
    s1.append(s2);
    cout << s1;
    s2.append(s1,3,s1.size());
    cout << s2;
*/

/*比较string
- 用关系运算符比较string的大小
    - ==,>,<,>=,<=,!=
    - 返回值都是bool类型，成立返回true，否则返回false
    - 例如:
        string s1("hello"),s2("hello"),s3("hell");
        bool b = (s1 == s2);
        cout << b << endl;
        b = (s1 == s3 );
        cout << b << endl;
        b = (s1 > s3);
        cout << b << endl;

- 用成员函数compare比较string的大小
    string s1("hello"),s2("hello"),s3("hell");
    int f1 = s1.compare(s2);    
    int f2 = s1.compare(s3);    
    int f3 = s3.compare(s1);    
    int f4 = s1.compare(1,2,s3,0,3);    
    int f5 = s1.compare(0,s1.size(),s3);
    cout << f1 << endl << f2 << endl << f3 << endl ;
    cout << f4 << endl << f5 << endl;

*/


/*字串
- 成员函数substr
    string s1("hello world"),s2;
    s2 = s1.substr(4,5);    //下标4开始 5个字符
    cout << s2 << endl;
*/

/*交换string
- 成员函数swap
    string s1("hello world"),s2("really");
    s1.swap(s2);
    cout << s1 << endl;
    cout << s2 << endl;

*/

/*寻找string中的字符
- 成员函数find()
    string s1("hello world");
    s1.find("lo");
    在s1中从前向后找第一次出现的lo，如果找到返回l的下标，如果找不到，返回string::npos（string中定义的静态常量）
- 成员函数rfind()
    string s1("hello world");
    s1.rfind("lo");
    在s1中从后向前找第一次出现的lo，如果找到返回l的下标，如果找不到，返回string::npos（string中定义的静态常量） 
- 指定位置找
    string s1("hello worlld");
    cout << s1.find("ll",1) << endl;
    cout << s1.find("ll",2) << endl;
    cout << s1.find("ll",3) << endl;
- 成员函数find_first_of()
    string s1("hello worlld");
    s1.find_first_of("abcd");
    在s1中从前向后查找“abcd”中任意一个字符第一次出现的位置，如果找到则返回下标，否则返回string::npos
- 成员函数find_last_of()
    string s1("hello worlld");
    s1.find_last_of("abcd");
    在s1中从前向后查找“abcd”中任意一个字符最后一次出现的位置，如果找到则返回下标，否则返回string::npos
- 成员函数find_first_not_of()
    string s1("hello worlld");
    s1.find_first_not_of("abcd");
    在s1中从前向后查找 不在 “abcd”中任意一个字符 第一次出现的位置，如果找到则返回下标，否则返回string::npos
- 成员函数find_last_not_of()
    string s1("hello worlld");
    s1.find_last_of("abcd");
    在s1中从前向后查找 不在 “abcd”中任意一个字符 第一次出现的位置，如果找到则返回下标，否则返回string::npos
*/

/*删除string中的字符
- 成员函数erase()
    string s1("hello world");
    s1.erase(5);  //删除下标为5及其之后的子串
    cout << s1;
    cout << s1.length();
    cout << s1.size();
*/

/*替换string中的字符
- 成员函数replace()
    string s1("hellow world");
    s1.replace(2,3,"haha");  //下标从2开始 一共3个字符
    string s2("hellow world");
    s2.replace(2,3,"haha",1,2);//下标从2开始 一共3个字符 替换成“haha”下标1开始 一共2个字符
    cout << s2;
    cout << s1;
*/

/*在string中插入字符
-  成员函数insert()
    string s1("hello world");
    string s2("show insert");
    s1.insert(5,s2);   //将s2插入下标为5
    cout << s1 << endl;
    s1.insert(2,s2,5,3); //将s2下标为5开始的3个元素 插入下标为2的位置  
    cout << s1 << endl;
*/

/*转换成C语言的char*字符串（返回动态分配空间的指针）
- 成员函数c_str()
    string s1("hello world");
    printf("%s\n",s1.c_str());   //s1.str()返回传统的const char * 类型字符串，以'\0'结尾
- 成员函数data()
    string s1("hello world");
    const char * p1 = s1.data();   //返回的是char*
    for(int i =0;i<s1.length();++i)
        printf("%c",*(p1+i));       
*/

/*字符串流处理
- 类似C语言的scanf和sprintf
- 除了标准流和文件流输入输出外，还可以从string进行输入输出
- 类似istream和ostream进行标准流输入输出，我们用istringstream和ostringstream进行字符串的输入输出，也称为内存输入输出
- 需要头文件<string> 和 <sstream>

//字符串流处理-字符串输入流istringstream
int main(){
    string input("Input test 123 4.7 A");
    istringstream inputString(input);
    string string1,string2;
    int i ;
    double d;
    char c;
    inputString >> string1 >> string2 >> i >> d >> c;
    cout << string1 << endl << string2 << endl;
    cout << i  << endl << d << endl << c << endl;
    long L;
    if(inputString >> L)
        cout << "long\n";
    else    
        cout  << "empty\n";
    system("pause");
    return 0;
}

//字符串流处理-字符串输出流ostringstream
int main(){
    ostringstream outputString;
    int a = 10;
    outputString << "this" << a << "ok" <<endl;
    cout << outputString.str(); //outputString.str()返回值是string对象
    system("pause");
    return 0;
}
*/



