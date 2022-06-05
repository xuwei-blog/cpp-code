#include <iostream>
#include <memory>
using namespace std;
//要点：一个常规指针被0个智能指针托管，该常规指针就会被delete
struct A{
    int n;
    A(int v =0):n(v){}
    ~A(){
        cout << n << "destructor" << endl;
    }
};
int main(){
    shared_ptr<A> sp1(new A(2)); //sp1托管了A(2)
    shared_ptr<A> sp2(sp1);  //sp2托管了A(2)
    cout << "1) "<<sp1->n<<","<<sp2->n<<endl;
    shared_ptr<A> sp3;
    A*p = sp1.get();  //p指向A(2)
    cout << "2) " << p->n << endl;

    sp3 = sp1; //sp3托管A(2)
    cout <<"3) " << (*sp3).n <<endl;

    sp1.reset();   //sp1放弃托管A(2)
    if(!sp1){
        cout << "4) sp1 is null" << endl;
    }

    A*q = new A(3);
    sp1.reset(q);  //sp1托管q

    cout << "5) " << sp1->n << endl;

    shared_ptr<A> sp4(sp1); //sp4托管A(3)
    shared_ptr<A> sp5;
    sp5.reset(q); //err 
    sp1.reset();
    cout << "before end main" <<endl;

    system("pause");
    return 0;  //程序结束会delete A(2)
}

/*
struct B{
    ~B(){cout <<"~A"<<endl};
};
int main(){
    A*p = new A();
    shared_ptr<A> ptr(p);
    shared_ptr<A> ptr2;
    ptr2.reset(p);//不增加pte中对p的托管计数 避免p被delete两次
    cout << "end" << endl;
    system("pause");
    return 0;
}
*/
