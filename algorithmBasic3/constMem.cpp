//常量成员函数
//常量对象
/*知识点：
1.常量成员函数不能修改对象的属性
2.常量成员函数不能调用非常量的成员函数，
因为非常量的成员函数在调用过程中可能修改对象属性
3.常量对象的属性不能被修改
4.常量对象不能执行非常量成员函数
5.常量对象可以执行常量成员函数
6.const也能作为重载条件
*/
class Sample{
    public:
        int value;
        void GetValue() const ;
        void func(){};
        Sample(){}
};

void Sample::GetValue() const{
    //value = 0; err
    //func();    err
}