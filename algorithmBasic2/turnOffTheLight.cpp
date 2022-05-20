#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <memory>
using namespace std;
typedef int ElemType;
 /*题目描述：有一个由按钮组成的矩阵，其中每行有6个按钮，共5行
 每个按钮的位置上有一盏灯
 当按下一个按钮后，该按钮以及周围位置（上边，下边，左边，右边）的灯
 都会改变状态
*/
/*分析：①每个开关两个状态（开或关）
②一共有30个开关，状态数是2^30,数量过大，会超时
基本思路：如果存在某个局部，一旦这个局部状态被确定，那么剩余其他部分
的状态只能是确定的一种，或者不多的n中，那么就只需枚举这个局部的状态即可
*/
char oriLights[5];//5行一维数组 替代二维数组
char lights[5];//存放灯变化中的矩阵
char result[5];//存放开关的方案
int GetBit(char c,int i){//取字符C的第i个bit
    return (c>>i) & 1;  //与运算后得到 字符c的每一位bit
}
void SetBit(char &c,int i,int v){//设置字符C 引用传参
    if(v){
        c |= (1<<i); //c的第i位变成了1 其他位不变
    }
    else
        c &= ~(1<<i);//c的第i位变成了0 其他位不变
} 
void FlipBit(char & c,int i){//字符c的第i位进行翻转 
    c ^= (1<<i);//翻转c的第i位，其他位不变
}
void OutputResult(int t,char result[]){//表示第几个test
    cout<<"PUZZLE #"<<t<<endl;
    for(int i = 0 ; i < 5; i++){//开关矩阵的一行 对应 result的一行
        for(int j = 0;j<6;j++){
            cout<<GetBit(result[i],j);
            if(j<5)
                cout<<" ";
        }
        cout<<endl; //输出完一行
    }
}
int main(){
    //1.读入状态
    int T;
    cin>>T;
    for(int t =  1; t <= T; t++){//t是测试数据的第几组
        for(int i = 0;i<5;i++){//读入每组灯的原始矩阵
            for(int j =0;j<6;j++){
                int s;//s是第i行第j列灯的状态
                cin>>s;
                SetBit(oriLights[i],j,s);//把状态s读入字符c的第j个元素
                                         //每次读入6个状态 一共5次
            }
            //枚举第一行可能的状态
            for(int n = 0;n<64;n++){
                int switchs = n;//当前行的状态
                memcpy(lights,oriLights,sizeof(oriLights));
                for(int i = 0;i<5;i++){//依次处理每一行的状态
                    result[i] = switchs;//switchs代表第i行开关的状态
                    for(int j =0;j<6;j++){
                        if(GetBit(switchs,j)){// j列影响j-1列和j+1列
                            if(j>0)
                                FlipBit(lights[i],j);
                            FlipBit(lights[i],j);
                            if(j<5)
                                FlipBit(lights[i],j+1);
                        }
                    }
                    if(i<5)
                        lights[i+1] ^= switchs;//翻转i+1行第j个bit
                    switchs = lights[i];  //本题精髓    看晕了
                }
                //判断有没有成功 就看最后一行有没有成功
                if(lights[4] == 0){
                    OutputResult(t,result);
                    break;
                }
            }
        }
    }
    system("pause");
    return 0;
}