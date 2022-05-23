#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class CShape{
    public:
        virtual double Area() = 0;  //纯虚函数 ：没有函数体的虚函数
        virtual void PrintInfo() = 0; //没有CShape这样的图形，基类不需要这个函数
};
//矩形类
class CRectangle:public CShape{
    public:
        int w,h;
        virtual double Area();
        virtual void PrintInfo();
};
double CRectangle::Area(){
    return w*h;
}
void CRectangle::PrintInfo(){
    cout << "rectangle:" <<Area() <<endl;
}
//圆类
class CCircle:public CShape{
    public:
        int r;
        virtual double Area();
        virtual void PrintInfo();
};
double CCircle::Area(){
    return 3.14*r*r;
}
void CCircle::PrintInfo(){
    cout <<"circle:"<<Area()<<endl;
}
//三角形类
class CTriangle:public CShape{
    public:
        int a,b,c;
        virtual double Area();
        virtual void PrintInfo();
};
double CTriangle::Area(){
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void CTriangle::PrintInfo(){
    cout <<"triangle"<<Area()<<endl;
}

CShape* pShapes[100];
int MyCompare(const void *s1,const void * s2);

int main(){
    int i ;
    int n;
    CRectangle * pr;
    CCircle * pc;
    CTriangle * pt;
    cin >> n;
    for(i = 0;i<n;++i){
        char c ;
        cin >> c;
        switch(c){
            case 'R':
                pr = new CRectangle();
                cin >> pr->w >> pr->h;
                pShapes[i] = pr;
                break;
            case 'C':
                pc = new CCircle();
                cin >> pc->r;
                pShapes[i] = pc;
                break;
            case 'T':
                pt = new CTriangle();
                cin >>pt->a >> pt->b >> pt->c;
                pShapes[i] = pt;
                break;
        }
    }
    qsort(pShapes,n,sizeof(CShape*),MyCompare);
    for(i =0 ;i<n;++i){
        pShapes[i] -> PrintInfo();
    }

    system("pause");
    return 0;
}