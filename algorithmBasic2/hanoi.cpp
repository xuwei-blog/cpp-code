#include <iostream>
using namespace std;
//递归经典问题：汉诺塔
/*手写解法
                        1 A B C
                        1 A C B
            2 A C B ==> 1 C A B                 1 B C A
            1 A B C ==> 1 A B C                 1 B A C
3 A B C ==> 2 B A C ==> 2 B A C ==> 2 B A C ==> 1 A B C
*/
void Hanoi(int n,char src,char mid,char dest){
    if( n== 1){
        cout<<src<<"->"<<dest<<endl;//把盘子从src移动到dest
        return;
    }
    Hanoi(n-1,src,dest,mid);//将n-1个盘子从src利用dest移动到mid
    cout<<src<<"->"<<dest<<endl;//n-1个盘子移动完之后，剩下的盘子移到dest
    Hanoi(n-1,mid,src,dest);//将n-1个盘子从mid利用src移动到dest
    return;
}


int main(){
    int n;
    cin >> n; //输入盘子数量
    Hanoi(n,'A','B','C');

    system("pause");
    return 0;

}