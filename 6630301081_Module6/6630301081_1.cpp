#include<iostream>
#include<string>
using namespace std;
struct node{
    char value;
    struct node *next;
};
typedef struct node *Stack;
Stack createstack(){
    Stack s;
    s=new struct node;
    if(s==NULL){
        cout<<"Out of space";
    }
    else{
        s->next=NULL;
    }
    return s;

}
Stack push(int data,Stack s){
    Stack Tmpcell;
    Tmpcell=new struct node;
    if(Tmpcell==NULL){
        cout<<"Out of space";
    }
    else{
        Tmpcell->value=data;
        Tmpcell->next=s->next;
        s->next=Tmpcell;
    }
    return s;
}
int Isempty(Stack s){
    return s->next==NULL;
}
char top(Stack s){
    if(!Isempty(s)){
        return s->next->value;
    }
    return '.';
}
void pop(Stack s){
    Stack firstcell;
    if(Isempty(s)){
        cout<<"Empty Stack!!!"<<endl;
    }
    else{
        firstcell=s->next;
        s->next=s->next->next;
        delete(firstcell);
    }
}
int main(){
    Stack s=createstack();
    cout<<"Input : ";
    string a="";cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='('||a[i]=='{'||a[i]=='['){
            push(a[i],s);
        }
        else{
            if(a[i]==')'&&top(s)=='('||a[i]=='}'&&top(s)=='{'||a[i]==']'&&top(s)=='['){
                pop(s);
            }
            else{
                if(Isempty(s)){
                cout<<"No open symbol"<<endl;
                return 0;
                }
                else{
                cout<<"Error : Not match"<<endl;
                return 0;
                } 
            }
            }

        }
         if(Isempty(s)){
                cout<<"Success"<<endl;
                return 0;
                }
                else{
                cout<<"stack is not empty"<<endl;
                return 0;
                } 
    }

