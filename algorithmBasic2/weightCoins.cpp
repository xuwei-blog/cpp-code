#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
typedef int ElemType;
/*  称硬币：有12枚硬币。其中11枚真币和1枚假币。
加币和真币重量不同,但不知道假币比真币轻还是重。
现在，用一架天平秤了这些币三次，告诉你称的结果，
请你找出假币并且确定假币是轻还是重（数据保证一定能找出来）
*/
/*  题解思路：枚举。硬币A到L，假设A是假币而且是轻的，
再假设A是假币而且是重的，都不符合A就不是假币，以此类推。
*/
    bool isFake(char c,bool light);
    //light为真表示假设假币为轻，否则表示假设假币为重
    //返回值为假设是否成立
    char Left[3][7];//天平左边硬币
    char Right[3][7];//天平右边硬币
    char Result[3][7];//结果
int main(){
    int t;
    cin >>t;
    while(t--){
        for(int i = 0; i < 3; i++){
            cin>> Left[i] >>Right[i]>>Result[i];
        }
        for(char c ='A' ; c <='L' ; c++){
            if(isFake(c,true)){
                cout<<c<<" is the counterfeit coin and it is light.\n";
                break;
            }
            else if(isFake(c,false)){
                cout<<c<<" is the counterfeit coin and it is light.\n";
                break;
            }
        }
    }
    system("pause");
    return 0;
}
bool isFake(char c,bool light){
    for(int i = 0 ; i < 3; i++){
        char* pLeft,*pRight;//指向天平两边的字符串
        if(light){
            pLeft = Left[i];
            pRight = Right[i];
        }
        else{
            pLeft = Right[i];
            pRight = Left[i];
        }
        switch(Result[i][0]){//第一次进入 假设假币是轻的
            case 'u':
                if(strchr(pRight,c) == NULL)//c在右边
                    return false;
                break;
            case 'e':
                if(strchr(pLeft,c) || strchr(pRight,c))//c不在左边，也不在右边
                    return false;
                break;
            case 'd':
                if(strchr(pLeft,c) == NULL)//c在左边
                    return false;
                break;
        }
    }
    return true;
}