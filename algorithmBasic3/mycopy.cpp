#include <iostream>
#include <fstream>
using namespace std;
/*文件拷贝程序mycopy实例
用法：
    mycopy src.dat dest.dat
    即将src.dat拷贝到dest.dat 如果dest.dat原来就有，则原来的文件会被覆盖

//vscode下执行不了
int main(int argc,char *argv[]){//agrc：命令的个数   argv[]：存放命令
    if(argc != 3){
        cout << "file name missing!" << endl;
        system("pause");
        return 0;
    }
    ifstream inFile(argv[1],ios::binary|ios::in);  //打开文件用于读
    if(!inFile){
        cout <<"source file open err" << endl;
        system("pause");
        return 0;
    }
    ofstream outFile(argv[2],ios::binary|ios::out);  //打开文件用于写
    if(!outFile){
        cout << "new file open err" <<endl;
        inFile.close();  //打开的文件一定要关闭
        system("pause");  
        return 0;
    }
    char c;
    while(inFile.get(c)) //每次读取一个字符
        outFile.put(c);  //每次写入一个字符
    outFile.close();
    inFile.close();
    system("pause");
    return 0;
}
*/

/*二进制文件 和 文本文件 的区别

Linux,Unix下的换行符：‘\n’（ASCII码：0x0a）
Windows下的换行符：‘\r\n’（ASCII码：0x0d0a） endl就是‘\n’
Mac OS下的换行符：‘\r’（ASCII码：0x0d）


如果跨平台 粘贴文件 就会有问题

Linux,Unix,Mac OS  ios::binary就是默认方式
Windows不用ios::binary  导致读取文件时：所有的'\r\n' 会被当作一个字符'\n'处理
                        导致写入文件时：所有的'\n' 会被当作二个字符'\r\n'处理
*/


