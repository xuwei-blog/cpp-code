#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/*二进制读文件
ifstream 和 fstream的成员函数：
    istream& read(char* s,long n);
将文件读指针指向的地方的n个字节内容，读入到内存地址s，
然后将文件读指针向后移动n字节(ios::in方式打开，文件指向文件开头)
*/

/*二进制写文件
ofstream 和 fstream的成员函数：
    istream& write(const char * s,long n);
将内存地址s处的n个字节内容，写入到文件中写指针指向的位置，然后将文件写指针
向后移动n字节(以ios::out方式打开文件时，文件写指针开始指向文件开头，
以ios::app方式打开文件时，文件写指针开始指向文件尾部)

//在文件中写入和读取一个整数
int main(){
    //二进制方式写入整型x
    ofstream fout("some.dat",ios::out|ios::binary);
    int x = 120;
    fout.write((const char*)(&x),sizeof(int));
    fout.close();
    //二进制方式读出整型y
    ifstream fin("some.dat",ios::in|ios::binary);
    int y ;
    fin.read((char *)& y ,sizeof(int));
    fin.close();
    cout << y << endl;

    system("pause");
    return 0;
}
*/

/*****文件二进制读写实例******/
/*文件二进制形式的好处
1.存储空间小
2.读写双方统一数据格式后，方便查找、排序数据
*/

/*二进制文件读写 - 从键盘输入几个学生的成绩，并以二进制文件的形式保存 (3个实例)

struct Student{
    char name[20];
    int score;
};

//写入文件
int main(){
    Student s;
    ofstream OutFile("student.dat",ios::out|ios::binary);
    while(cin >> s.name >> s.score){
        OutFile.write((char*)&s,sizeof(s));
    }
    OutFile.close();

    system("pause");
    return 0;
}

//读出文件
int main(){
    Student s;
    ifstream inFile("student.dat",ios::in|ios::binary);
    if(!inFile){
        cout <<"err" <<endl;
        system("pause");
        return 0;
    }
    while(inFile.read((char*)&s,sizeof(s))){
        int readedBytes = inFile.gcount();  //判断刚才读了多少字节
        cout << s.name << " " << s.score <<endl;
    }
    inFile.close();
    system("pause");
    return 0;
}

//将student.dat文件的Jane的名字改成Mike
int main(){
    Student s;
    fstream iofile("student.dat",ios::in|ios::out|ios::binary);
    if(!iofile){
        cout << "err";
        system("pause");
        return 0;
    }
    iofile.seekp(2 * sizeof(s),ios::beg);    //定位写指针到Jane的位置  Jane的地址就是2个结构体大小
    iofile.write("Mike",strlen("Mike"+1)); //写入Mike 顺便加上\0 其实\0不是必须的 因为Mike和Jane长度一样
    iofile.seekg(0,ios::beg);              //定位读指针到文件开头
    while(iofile.read((char*)&s,sizeof(s)))
        cout << s.name <<" " <<s.score <<endl;
    iofile.close();

    system("pause");
    return 0;
}
*/



