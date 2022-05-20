#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;     //int 类型的数据域

//不带头结点的单链表
//LNode*  和   LinkList  本质是一个东西  LNode*强调是结点  LinkList强调是单链表 

typedef struct LNode{//定义单链表结点类型
    ElemType data; //数据域
    LNode *next;//指针域
}LNode, *LinkList;

//初始化一个空的单链表
bool InitList(LinkList &L){  //注意用引用 &
    L = NULL; //空表，暂时还没有任何结点；    //头结点指向NULL    //清除以前的脏数据
    return true;
}


//判断单链表是否为空
bool Empty(LinkList L){
    if (L == NULL)
        return true;
    else
        return false;
}


//不含头结点的插入
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    
    //插入到第1个位置时的操作有所不同！
    if(i==1){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data =e;
        s->next =L;
        L=s;          //头指针指向新结点
        return true;
    }

    //i>1的情况与带头结点一样！唯一区别是j的初始值为1
    LNode *p;       //指针p指向当前扫描到的结点 
    int j=1;        //当前p指向的是第几个结点
    p = L;          //L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while(p!=NULL && j<i-1){     //如果i>lengh, p最后会等于NULL
        p = p->next;             //p指向下一个结点
        j++;
    }

    if (p==NULL)                 //i值不合法
        return false;
    
    //在第i-1个结点后插入新结点
    LNode *s = (LNode *)malloc(sizeof(LNode)); //申请一个结点
    s->data = e;
    s->next = p->next;
    p->next = s;          
    return true;

}


//给出结点p后插（不带头结点）
bool InsertNextNode(LNode *p, ElemType e){
    if(p==NULL){
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    //某些情况下分配失败，比如内存不足
    if(s==NULL)
        return false;
    s->data = e;          //用结点s保存数据元素e 
    s->next = p->next;
    p->next = s;          //将结点s连到p之后

    return true;
}                         //平均时间复杂度 = O(1)


//有了后插操作，那么在第i个位置上插入指定元素e的代码可以改成：
bool ListInsert(LinkList &L, int i, ElemType e){  
    if(i<1)
        return false;
    
    LNode *p;       //指针p指向当前扫描到的结点 
    int j=0;        //当前p指向的是第几个结点
    p = L;          //L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while(p!=NULL && j<i-1){     //如果i>lengh, p最后4鸟会等于NULL
        p = p->next;             //p指向下一个结点
        j++;
    }

    return InsertNextNode(p, e);   //调用函数 在p结点后插元素e
}


//指定结点前插 （没有头指针，无法遍历的情况）
//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p, ElemType e){
    if(p==NULL)
        return false;
    
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL) //内存分配失败
        return false;

    //重点来了！ 后插操作 再交换两个结点的数据域
    s->next = p->next;
    p->next = s;       //新结点s连到p之后
    s->data = p->data; //将p中元素复制到s
    p->data = e;       //p中元素覆盖为e

    return true;
}  //时间复杂度为O(1)



int main(){
    LinkList L;    //声明一个指向单链表的指针: 头指针   栈里开辟空间
    
    InitList(L);
}
