#include <iostream>
#include <cmath>
using namespace std;
int N;//有N个皇后
int queenPos[100];//皇后数量不超过100
//queenPos[i]表示第i行的皇后应该放在哪一列
void NQueen(int k);//假设0到k-1行都已经摆好
                   //要从第k行开始往后摆
int main(){
    cin>>N;
    NQueen(0);//从第0行开始摆放皇后
    system("pause");
    return 0;
}

void NQueen(int k){//在0到k-1行皇后已经摆好的情况下
                   //摆第k行以及其后的皇后
    int i;
    if(k == N){//N个皇后已经摆好
        for(i = 0;i<N;i++){
            cout<< queenPos[i]+1 <<" ";
        }
        cout<<endl;
        return ;
        
    }
    for(i = 0;i<N;i++){//逐个尝试第k个皇后的位置
        int j ;
        for(j=0;j<k;j++){
            //和已经摆好的k个皇后的位置比较
            //看是否冲突
            if(queenPos[j] == i || //竖的
                abs(queenPos[j] - i) ==abs(k-j)){//斜的
                break;//冲突，则尝试第i+1个位置
            }
            
        }
        if( j == k ){//当前选的位置i不冲突
            queenPos[k] = i;//将第k个皇后摆放在位置i
            NQueen(k+1);//0到k行摆放妥当，对k+1行进行操作
        } 
    }
}