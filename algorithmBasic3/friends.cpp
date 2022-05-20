#include <iostream>
using namespace std;
/*友元函数：一个类的友元函数可以访问该类的私有成员
友元函数包括：类中的成员函数(包括构造、析构) 和 普通全局函数
*/
/*友元类：类A是类B的友元类，类A的成员函数可以访问类B的私有成员
友元类之间的关系不能传递，不能继承
*/
class CCar;
class CDriver{
    public:
        void ModifyCar(CCar * pCar);//改装汽车
};
class CCar{
    private:
        int price;
    //友元函数
    friend int MostExpensiveCar(CCar cars[],int total);//声明友元函数
    friend void CDriver::ModifyCar(CCar * pCar);//声明友元函数

    //友元类
    friend class CDriver;//声明友元类
};
void CDriver::ModifyCar(CCar * pCar){
    pCar->price += 1000;//改装后汽车价值增加
}
int MostExpensiveCar(CCar cars[],int total){//求最贵汽车的价格
    int tmpMax = -1;
    for(int i=0;i<total;i++){
        if(cars[i].price > tmpMax)
            tmpMax = cars[i].price;
    }
    return tmpMax;
}

int main(){
    
    system("pause");
    return 0;
}