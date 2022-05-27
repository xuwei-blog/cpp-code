#include <iostream>
#include <vector>
using namespace std;
//二维数组
int main(){
    //v有3个元素，每个元素都是vector<int>容器
    vector<vector<int> > v(3);  //避免编译器理解成右移运算符 所以分开写
    for(int i =0;i<v.size();++i){
        for(int j =0;j<4;++j)
            v[i].push_back(j);
    }
    for(int i =0;i<v.size();++i){
        for(int j =0;j<v[i].size();++j)
            cout << v[i][j] <<" ";
        cout << endl;
    }
    system("pause");
    return 0;
}