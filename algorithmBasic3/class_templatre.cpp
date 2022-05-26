#include <iostream>
using namespace std;

/*类模板
- 为了多快好省地定义出一批相似的类，可以定义类模板，然后由类模板生成不同的类
- 变长数组是一种常见的数据类型，元素可以是：整数、学生、字符串
- 考虑一个数组类，需要提供的基本操作
    len() 查看数组的长度
    getElement(int index) 获取其中一个元素
    setElement(int index) 对其中的一个元素进行赋值
    ...

//类模板格式：
template <class 类型参数1,class 类型参数2,...>
class 类模板名{
    成员函数和成员变量
}；

类模板里成员函数的写法：
template <class 类型参数1,class 类型参数2,...>
返回值类型 类模板名 <类型参数名列表>::成员函数名{
    ...
}

用类模板定义对象的写法：
类模板名<真实类型参数表> 对象名(构造函数实参表)

//类模板示例：Pair类模板
template <class T1,class T2>
class Pair{
    public:
        T1 key;
        T2 value;
        Pair(T1 k,T2 v):key(k),value(v){};
        bool operator<(const Pair<T1,T2> & p) const;
};
template<class T1,class T2>
bool Pair<T1,T2>::operator < (const Pair<T1,T2> & p) const{
    //Pair的成员函数 operator<
    return key<p.key;
}

int main(){
    Pair<string,int> student("Tom",19); //实例化一个类 Pair<strubg,int>
    cout << student.key << " " <<student.value;

    system("pause");
    return 0;
}
*/



/*用类模板定义对象
- 编译器由类模板生成类的过程叫做类模板的实例化。
- 由类模板实例化得到的类，叫模板类
- 同一个类模板的两个模板类是不兼容的（实例化的两个模板类 是两个类）
    Pair<string,int> *p;
    Pair<string,double> a;
    p = &a; //err
*/

/*函数模板作为类模板的成员
template <class T>
class A{
    public:
        template<class T2>
        void Func(T2 t){cout << t <<endl;} //成员函数模板        
};
int main(){
    A<int> a;     //模板类A
    a.Func('K');      //成员函数模板 Func被实例化 T2是char
    a.Func("hello");  //成员函数模板 Func被实例化 T2是char*

    system("pause");
    return 0;
}
*/


/*类模板与非类型参数
- 类模板的<类型参数表>中可以出现非类型参数
template <class T,int size>
class CArray{
        T array[size];
    public:
        void Print(){
            for(int i =0;i<size;++i)
                cout << array[i] << endl;
        }

};
//实例化对象
CArray<double,40> a1;    double array[40]
CArray<int,50> a2;       int array[50]
*/

