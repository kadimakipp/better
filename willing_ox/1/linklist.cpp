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
遍历链表到链表尾部的的前一个节点，然后创建一个新node,新node的next指针指向空，
再把链表尾部node的next指针指向新node
note: 这里是尾部的前一个节点，因为尾部最后的节点为NULL。所以这个节点是无效的。
*/
bool tail_add(LinkList &L, int data)
{
    Lnode *n = L;
    while(n->next)//从表头节点开始
    {
        n = n->next;
    }
    Lnode *new_n = new Lnode(data,NULL);
    n->next = new_n;
    return true;
}
/*查，查找一个节点.
遍历链表，判断每个节点的值是否为要查找的值，直到找到该值或遍历到结尾，返回结果。
*/
Lnode* find_node(LinkList &L, int data)
{
    Lnode *n = L->next;
    while(n)
    {
        if(n->data == data)
            break;
        n=n->next;
    }
    return n;
}

/*增，指定位置之后,
先找到该节点，然后使新建节点，让新节点的next指向找到节点指向的内容，
再让找到节点指向新建节点
*/
bool add_data(LinkList &L, int find, int data)
{
    Lnode *n=find_node(L, find);
    if(!n)
    {
        std::cout<<"don't find "<<find<<std::endl;
        return false;
    }else{
        std::cout<<"find success"<<std::endl;
    }
    Lnode *p = new Lnode(data,NULL);
    p->next=n->next;
    n->next=p;
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
下面实现的方法比较麻烦，一个前指针一个前-1指针。为的是找到要删除的前一个节点。(被注释掉)
简化版参考尾插法。
*/
bool delete_node(LinkList &L, int data)
{
#if(0)
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
#else
    Lnode *n = L;
    while(n->next)
    {
        if(n->next->data == data)
        {
            break;
        }
        n = n->next;
    }
    if(!n->next)//指定节点位置为空,n是指定节点的前一个节点
        std::cout<<"don't find"<<std::endl;
    else
    {
        Lnode *d = n->next;
        n->next = d->next;
        delete d;
    }
    return true;
#endif
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
    show_list(L);

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
    std::cout<<"insert b in after a"<<std::endl;
    for(int i=0;i<3;i++)
    {
        int a,b;
        std::cin>>a>>b;
        if(!add_data(L, a, b))
        {
            std::cout<<"inster "<<b<<" in after "<<a<<" failed"<<std::endl;
        }
        show_list(L);
    }



    return 0;
}