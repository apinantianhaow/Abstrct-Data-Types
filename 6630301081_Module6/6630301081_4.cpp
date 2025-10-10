#include<iostream>
using namespace std;

struct record
{
    int value ;
    struct record *next ;
    struct record *prev ;

};

struct record *rear=NULL;

struct record *insert(struct record *head,int data)
{
    struct record *p, *node;
    if(head==NULL){
        head = new struct record;
        head->value=data;
        head->next=head;
        head->prev=head;
        rear=head;
        return head;
    }
    else{
        node=new struct record ;
        node->value=data;
        p=rear;
        p->next=node;
        node->next=head;
        node->prev=p;
        rear=node;
        head->prev=rear;
        return head;   
    }
    return head;
}
struct record *del(struct record *head,int data){
    struct record *p = head;
    struct record *tmp;

    while(head != rear){
        for(int i=1; i < data; i++){
            p = p->next;
        }
        tmp = p->next;
        cout << tmp->value << " ";
        if(tmp == head){
            head = head->next;
        }
        if(tmp == rear){
            rear = rear->prev;
        }

        p->next = tmp->next;
        tmp->next->prev = p;
        delete tmp;
        p = p->next;
    }
    cout<<endl;
    cout << "Winner: " << head->value << endl;
    return head;
}

int main (){
    struct record *head=NULL;
    int N ;cout<<"Input N = ";
    cin>>N;
    int M;cout<<"Input M = ";
    cin>>M;
    for(int i=1;i<=N;i++){
        head = insert(head,i);
    }
    cout<<"Eliminate : ";
    head = del(head,M);
}