#include <iostream>
using namespace std;
/*类之间的两种关系
1.继承：‘是’ 的关系
基类A ， B是基类A的派生类
逻辑上要求： 一个B对象也是一个A对象
例：A是学生 ，B是大学生

2.复合：‘有’ 的关系
类C中 有 成员变量k ，k是类D的对象，则C和D是复合关系
逻辑上要求：D对象是C对象的固有属性或组成部分
例：C是汽车，D是轮胎
*/
/*点类 和 圆类
错误示例
class CPoint{
    double x,y;
}
class CCircle:public CPoint{
    double r;
}
正确做法
class CPoint{
    double x,y;
    friend class CCircle;//方便操作圆心
}
class CCircle{
    double r;
    CPoint center;
}
*/