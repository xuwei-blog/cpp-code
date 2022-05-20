#include <iostream>
using namespace std;
//有成员对象的类叫 封闭enclosing类
/*知识点：
1.封闭类对象生成时，先执行所有对象成员的构造函数，然后才
执行封闭类的构造函数
2.对象成员的构造函数调用次序和对象成员在类中的说明次序一致，
与他们在成员初始化列表中出现的次序无关
3.当封闭类的对象消亡时，先执行封闭类的析构函数。
次序和构造函数的调用次序相反

*/
class CTyre{
    private:
        int radius;
        int width;
    public:
        CTyre(int r,int w):radius(r),width(w){}
                        //初始化列表
};
class CEngine{

};
class CCar{
    private:
        int price;
        CTyre tyre;
        CEngine engine;
    public:
        CCar(int p,int tr,int tw);
};
CCar::CCar(int p,int tr,int w):price(p),tyre(tr,w){

};
int main(){
    CCar car(20000,17,225);
    
    system("pause");
    return 0;
}
