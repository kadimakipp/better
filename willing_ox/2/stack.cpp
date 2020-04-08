#include <iostream>

typedef struct node{
    int data;
    struct node* next;
    node(int data, node *next):data(data),next(next){}
    node(){data=-1;next=NULL;}
}*Node,*top;

bool create_stack(top &t)
{
    t = NULL;
    return true;
}

bool show_stack(top &t)
{
    Node n = t;
    if(!n)
        std::cout<<"stack is empty"<<std::endl;
    while(n)
    {
        std::cout<<n->data<<"\t";
        n = n->next;
    }
    std::cout<<std::endl;
    return true;
}

bool push(top &t,int data)
{

    if(!t)//empty
    {
        t = new node(data, NULL);
        
    }else
    {
        t = new node(data, t);
    }
    if(!t)
        return false;
    return true;
}

int pop(top &t)
{
    if(!t)//empty
        return -1;
    Node n = t;
    t = n->next;
    int data = n->data;
    delete n;
    return data;
}

int main()
{
    top stack;
    create_stack(stack);
    show_stack(stack);
    std::cout<<"push 5 element: "<<std::endl;
    for(int i = 0;i<5;i++)
    {
        int d;
        std::cin>>d;
        if(!push(stack,d))
        {
            std::cout<<"push "<<d<<"fail"<<std::endl;
        }
    }
    show_stack(stack);
    std::cout<<"pop 3 element: "<<std::endl;
    for(int i=0;i<3;i++)
    {
        std::cout<<"pop "<<pop(stack)<<std::endl;
    }

    std::cout<<"the list show stack"<<std::endl;
    show_stack(stack);


    return 0;
}