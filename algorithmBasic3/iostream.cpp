#include <iostream>
using namespace std;
/*输入输出流

继承关系图：

              ios 
           /       \  
     istream       ostream
    /       \      /     \
ifstream    iostream    ofstream
                |             
             fstream

简介：
istream是用于输入的流类，cin就是该类的对象
ostream是用于输出的流类，cout就是该类的对象
ifstream是用于从文件读取数据的类
ofstream是用于向文件写入数据的类
iostream是既能用于输入，又能用于输出的类
fstream是既能从文件读取数据，又能向文件写入数据的类

标准流对象：
输入流对象：
    cin与标准输入设备相连
输出流对象：
    cout与标准输出设备相连
    cerr与标准错误输出设备相连
    clog与标准错误输出设备相连
缺省的情况下：
    cerr << "hello" <<endl;
    clog << "hello" <<endl;
和
    cout << "hello" <<end;   效果一样

标准流对象
cin对应于标准输入流，用于从键盘读取数据，也可以被重定向为从文件中读取数据
cout对应于标准输出流，用于向屏幕输出数据，也可以被重定向为向文件写入数据
cerr对应于标准错误输出流，用于向屏幕输出出错信息
clog对应于标准错误输出流，用于向屏幕输出出错信息
cerr和clog的区别在于cerr不适用缓存区，直接向显示器输出信息；
而输出到clog中的信息先会被存放在缓冲区，缓冲区满或者刷新时才输出到屏幕
*/

/*输出重定向
int main(){
    int x,y;
    cin >> x >> y;
    freopen("test.txt","w",stdout); //将stdout输出重定向到.txt文件
    if( y == 0)
        cerr <<"err" <<endl;   //错误信息显示在终端
    else   
        cout << x /y ;    //输出结果存到文件里
    
    system("pause");
    return 0;
}
*/

/*输入重定向
int main(){
    double f;
    int n;
    freopen("t.txt","r",stdin);
    cin >> f >> n; //直接从文件内读取数据 不会等用户输入数据
    cout << f  << "," << n << endl;

    system("pause");
    return 0;
}
*/


/*istream类的成员函数
istream & getline(char * buf,int bufSize);
    从输入流中读取bufize-1个字符到缓冲区buf，或读到碰到‘\0’为止
istream & getline(char * buf,int buffSize,char delim);
    从输入流中读取bufSize-1个字符到缓冲区buf，或读到碰到delim字符为止

两个函数都会自动在buf中读入数据的结尾添加'\0'
'\0'或者delim都不会被读入buf，但会被从输入流中取走
如果输入流中在‘\0’之前或delim之前的字符数个数达到bufSize，就导致读入出错：
虽然本次读入已经完成，但是之后的读入就都会失败。
可以用if(!cin.getline(...))判断输入是否结束

bool eof();
    判断输入流是否结束
int peek();
    返回下一个字符，但不会从流中去掉
istream & putback(char c);
    将字符ch放回输入流
istream & ignore(int nCount = 1, int delim = EOF);
    从流中删除最多nCount个字符，遇到EOF结束

举例：

*/
int main(){
    int x;
    char buf[100];    //输入12 abcd回车
    cin >> x;     //拿掉12    
    cin.getline(buf,90); //输出：空格abcd
    cout << buf << endl; 
    system("pause");
    return 0;
}