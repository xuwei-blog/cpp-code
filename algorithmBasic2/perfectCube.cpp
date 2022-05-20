#include <iostream>
#include <cstdio>
using namespace std;

//完美立方a^3 = b^3 + c^3 + d^3
int main(){
    int N;
    scanf("%d",&N);
    for(int a = 2;a<=N;a++){
        for(int b = 2;b<a;b++){
            for(int c = b;c<a;c++){
                for(int d = c;d<a;d++){
                    if(a*a*a==b*b*b+c*c*c+d*d*d)
                    printf("Cube = %d,Triple = (%d,%d,%d)\n",a,b,c,d);
                }
            }
        }
    }
    system("pause");
    return 0;
}