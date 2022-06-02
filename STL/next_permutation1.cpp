#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string str = "213";
    char szStr[] = "321";
    /*123的6种排列
    - 排列组合根据less-than操作符做字典顺序的排序
    123 132 213 231 312 321
    */

    //213的前一个排列组合 132 123
    //213的后一个排列组合 231 312 321
    while(prev_permutation(str.begin(),str.end())){
        cout << str << endl;
    }
    cout << "****" << endl;

    while(next_permutation(str.begin(),str.end())){
        cout << str << endl;
    }
    cout << "****" << endl;



    while(next_permutation(szStr,szStr+3)){
        cout << szStr << endl;
    }

    sort(str.begin(),str.end());
    cout << "****" << endl;
    while(next_permutation(str.begin(),str.end())){
        cout << str << endl;
    }
    system("pause");
    return 0;
}