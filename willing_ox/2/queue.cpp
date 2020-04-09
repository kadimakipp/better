#include <iostream>
//循环队列
#define MAXSIZE 5
typedef struct queue{
    int *base;//数据块地址
    int front,rear;
}*Circular_Queue;

bool create_CQ(Circular_Queue &cq)
{
    cq->base = new int[MAXSIZE];
    if(!cq->base)
        return false;
    cq->front = cq->rear = 0;
    return true;
}
int length_CQ(Circular_Queue &cq)
{
    return (cq->rear-cq->front+MAXSIZE)%MAXSIZE;
}
bool is_empty(Circular_Queue &cq)
{
    return cq->rear==cq->front;
}
bool push(Circular_Queue &cq, int data)
{
    if((cq->rear+1)%MAXSIZE==cq->front)
    {
        std::cout<<"Circular Queue is full"<<std::endl;
        return false;
    }
    cq->base[cq-rear] = data;
    cq->rear = (cq->rear+1)%MAXSIZE;
    return true;
}

bool pop(Circular_Queue &cq, int &data)
{
    if(is_empty(cq))
    {
        std::cout<<"Circular Queue is empty"<<std::endl;
        return false;
    }
    data = cq->base[cq->front];
    cq->front = (cq->front+1)%MAXSIZE;
    return true;
}

int main()
{
    Circular_Queue cq;
    create_CQ(cq);
    std::cout<<"is empty -> "<<is_empty(cq)<<std::endl;
    std::cout<<"cq length -> "<<length_CQ(cq)<<std::endl;
    for(int i=0;i<MAXSIZE-3;i++)
    {
        int d;
        std::cin>>d;
        if(!push(cq,d))
        {
            std::cout<<"push fail"<<std::endl;
        }else{
            std::cout<<d<<"\t";
        }
    }
    std::cout<<std::endl;
    std::cout<<"is empty -> "<<is_empty(cq)<<std::endl;
    std::cout<<"cq length -> "<<length_CQ(cq)<<std::endl;
    for(int i=0;i<MAXSIZE-3;i++)
    {
        int d;
        std::cin>>d;
        if(!push(cq,d))
        {
            std::cout<<"push fail"<<std::endl;
        }else{
            std::cout<<d<<"\t";
        }
    }
    std::cout<<std::endl;
    std::cout<<"is empty -> "<<is_empty(cq)<<std::endl;
    std::cout<<"cq length -> "<<length_CQ(cq)<<std::endl;
    std::cout<<"****************************************"<<std::endl;
    for(int i=0;i<MAXSIZE-3;i++)
    {
        int d;
        if(!pop(cq,d))
        {
            std::cout<<"pop fail"<<std::endl
        }else{
            std::cout<<d<<"\t";
        }
    }
    std::cout<<std::endl;
    std::cout<<"is empty -> "<<is_empty(cq)<<std::endl;
    std::cout<<"cq length -> "<<length_CQ(cq)<<std::endl;
    for(int i=0;i<MAXSIZE-3;i++)
    {
        int d;
        if(!pop(cq,d))
        {
            std::cout<<"pop fail"<<std::endl
        }else{
            std::cout<<d<<"\t";
        }
    }
    std::cout<<std::endl;
    std::cout<<"is empty -> "<<is_empty(cq)<<std::endl;
    std::cout<<"cq length -> "<<length_CQ(cq)<<std::endl;
    return;
}