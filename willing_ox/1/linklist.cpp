#include <iostream>
#include <string>

using namespace std;
typedef struct Lnode
{
    int data;
    struct Lnode *next;

    Lnode(int d,Lnode *n):data(d), next(n){};
    Lnode(){};

}Lnode, *LinkList;

/*
链表的创建，初始化一个空节点，节点的next指针指向空。
可以动态分配，但是要注意在删除的时候要释放内存。

*/
bool create_list(LinkList &list)
{
    list = new Lnode(0,NULL);
    if(!list)
        return false;
    return true;
}
/*增，头插法
创建一个node，并将其指针指向头node的next指针，
再把头结点的next指针指向新建的node。
*/
bool head_add(LinkList &L, int data)
{
    Lnode* n = new Lnode(data, L->next);
    if(!n)
        return false;
    L->next = n;
    return true;
}
/*增，尾插法,
遍历链表到链表尾部的节点，然后创建一个新node,新node的next指针指向空，
再把链表尾部node的next指针指向新node*/
bool tail_add(LinkList &L, int data)
{
    Lnode *n = L->next;
    while(n->next)
    {
        n = n->next;
    }
    Lnode *new_n = new Lnode(data,NULL);
    n->next = new_n;
    return true;
}

/*
链表的遍历，
*/
bool show_list(LinkList &L)
{
    if(!L->next)
    {
        std::cout<<"list is empty"<<std::endl;
        return false;
    }
    Lnode* n = L->next;
    while(n)
    {
        std::cout<<n->data<<"\t";
        n = n->next;
    }
    std::cout<<std::endl;
    return true;
}

/*
删除,找到要删除的前一个节点，然后将其指针指向要删除的节点的指针。
下面实现的方法比较麻烦，一个前指针一个前-1指针。为的是找到要删除的前一个节点。
*/
bool delete_node(LinkList &L, int data)
{
    if(!L->next)return false;
    Lnode *n = L->next;
    Lnode *p = L;
    while(n)
    {
        if(n->data==data)
        {
            break;
        }
        p = p->next;
        n = n->next;
    }
    if(!p)
        std::cout<<"don't find"<<std::endl;
    else{
        Lnode *d =p->next;
        p->next=p->next->next;
        delete d;
    }
    return true;
}

int main()
{
    std::cout<<"create list"<<std::endl;
    LinkList L;
    if(!create_list(L))
    {
        std::cout<<"list create fail"<<std::endl;
        return 0;
    }
    std::cout<<"head insert, 3 element"<<std::endl;
    for(int i=0;i<3;i++)
    {
        int d;
        std::cin>>d;
        if(!head_add(L,d))
        {
            std::cout<<"insert "<<d<<" fail"<<std::endl;
        }
    }
    show_list(L);
    std::cout<<"tail instert, 3 element"<<std::endl;
    for(int i=0;i<3;i++)
    {
        int d;
        std::cin>>d;
        if(!tail_add(L,d))
        {
            std::cout<<"insert "<<d<<" fail"<<std::endl;
        }
    }
    std::cout<<"show this list"<<std::endl;
    show_list(L);
    std::cout<<"will be delete node"<<std::endl;
    for(int i=0;i<3;i++)
    {
        int d;
        std::cin>>d;
        if(!delete_node(L,d))
        {
            std::cout<<"delete "<<d<<" fail."<<std::endl;
        }
        show_list(L);
    }

    return 0;
}