#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/* 创建文件
方法1
ofstream outFile("testData.dat",ios::out|ios::binary);
- testData.dat 要创建的文件的名字
- ios::out 文件打开方式
    ios:out 输出到文件，删除原有内容
    ios::app 输出到文件，保留原有内容，总是在尾部添加
- ios::binary 以二进制文件格式打开文件

方法2
ofstream fout;
fout.open("test.out",ios::out|ios::binary);


实例：
int main(){
    //第一步创建文件
    ofstream fout;
    fout.open("test.out",ios::out|ios::binary); //文件名可以给出绝对路径，也可以给相对路径，没有说明就是在当前文件夹下
    //第二步判断是否打开成功
    if(!fout){
        cout << "file open error" <<endl;
    }
    system("pause");
    return 0;
}
*/

/*文件的读写指针：
ofstream fout("a1.out",ios::app); //以添加的方式打开
long location = fout.tellp();     //获取写指针的位置
lovation = 10;
fout.seekp(location);             //将写指针移动到第10个字节处
fout.seekp(location,ios::beg);    //从头数location
fout.seekp(location,ios::cur);    //从当前位置数location
fout.seekp(location,ios::end);    //从尾部数location

location可以为负值
*/

/*文件的读写指针
ifstream fin("a1.in",ios::ate);   //打开文件，定位文件指针到文件尾
long location = fin.tellg();      //取得读指针的位置
location = 10L;
fin.seekg(location);          //将读指针移动到第10个字节处
fin.seekg(location,ios::beg); //从头数location
fin.seekg(location,ios::cur); //从当前位置数location
fin.seekg(location,ios::end); //从尾部数location


*/

/*字符文件读写

例：              in.txt的内容为：1 234 9 45 6 879
执行完程序后，生成out.txt的内容为：1 6 9 45 234 879

int main(){
    vector<int> v;
    ifstream srcFile("in.txt",ios::in);
    ofstream destFile("out.txt",ios::out);
    int x;
    while(srcFile >> x )
        v.push_back(x);
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++)
        destFile << v[i] <<" ";
    destFile.close();
    srcFile.close();
    system("pause");
    return 0;
}
*/

