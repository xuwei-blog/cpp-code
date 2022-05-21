#include <iostream>
using namespace std;
class CArray{
        int size;
        int *ptr;
    public:
        CArray(int s =0);
        CArray(CArray & a);
        ~CArray();
        void push_back(int v);
        CArray & operator=(const CArray & a);
        int length(){return size;}

        //int & 使得 a[i] = n 成立，引用类型才能写在等号左边
        int & operator[](int i){
            //使得 n = a[i] , a[i] = n 成立
            return ptr[i];
        }
};

CArray::CArray(int s):size(s){
    if(s == 0)
        ptr = NULL;
    else  
        ptr = new int[s];
}
CArray::CArray(CArray & a){
    if(!a.ptr){
        ptr = NULL;
        size = 0;
        return ;
    }
    ptr = new int[a.size];
    memcpy(ptr,a.ptr,sizeof(int) * a.size);
    size = a.size;
}
CArray::~CArray(){
    if(ptr){
        delete [] ptr;
        ptr = NULL;
    }

}
CArray & CArray::operator=(const CArray & a){
//赋值号的作用是 使左边对象的 size和ptr 与=右边对象相等
    if(ptr == a.ptr)//避免 a = a 的错误
        return * this;
    if(a.ptr == NULL){//右边数组为空
        if(ptr)
            delete [] ptr;
        ptr = NULL;
        size = 0;
        return * this;
    }
    if(size < a.size){//原有空间不够用，才开辟新空间
        if(ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr,a.ptr,sizeof(int)* a.size);//空间够用，直接拷贝过来
    size = a.size;
    return * this;
}
void CArray::push_back(int v){
    //尾插
    if(ptr){
        int * tmpPtr = new int[size + 1];
        memcpy(tmpPtr,ptr,sizeof(int)*size);
        delete [] ptr;
        ptr = tmpPtr;
    }
    else//数组本来是空的
        ptr = new int[1];
    ptr[size++] = v;
}

int main(){
    CArray a;
    for(int i =0;i<5;i++)
        a.push_back(i); //动态分配
    CArray a2,a3;
    a2 = a; //重载=
    for(int i =0;i<a.length();i++)
        cout<<a2[i]<<" "; //重载[]
    cout<<endl;
    a2 = a3;
    for(int i =0;i<a2.length();i++)
        cout << a2[i] <<" ";
    cout << endl;
    a[3] = 100;
    CArray a4(a); //自己写复制构造
    for(int i =0;i<a4.length();i++)
        cout<<a4[i] <<" ";
    cout<<endl;
    system("pause");
    return 0;
}