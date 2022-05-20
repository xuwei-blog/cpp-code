#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//初始化空的循环双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); //分配一个头结点
    if (L == NULL)                      //内存不足，分配失败
        return false;
    L->prior = L; //头结点的prior指向头结点
    L->next = L;  //头结点的next指向头结点
}

void testDLinkList()
{
    //初始化循环单链表
    DLinkList L;
    InitDLinkList(L);
    //...
}

//判断循环双链表是否为空
bool Empty(DLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinkList L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

//循环双链表的插入
bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//循环双链表的删除
//删除p的后继结点q
bool DeleteNextDNode(DNode *p, DNode *q)
{
    p->next = q->next;
    q->next->prior = p;
    free(q);
}
