#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
    string sym;
    struct Node *next;
};

typedef Node *Stack;

Stack CreateStack(){
    Stack S=new Node{"",nullptr};
    return S;
}

bool IsEmpty(Stack S){
    return S->next==nullptr;
}

void Push(string s,Stack S){
    Stack tmp=new Node{s,S->next};
    S->next=tmp;
}

void Pop(Stack S){
    Stack p=S->next;
    S->next=S->next->next;
    delete(p);
}

string Top(Stack S){
    if(IsEmpty(S)) return "\0";
    return S->next->sym;
}

bool IsOperator(string s){
    return (s=="-"||s=="+"||s=="*"||s=="/");
}

int main(){
    string s="";
    string ss="";
    Stack S=CreateStack();
    cout << "Input : ";
    while(cin >> s){
        if(s=="."){
            break;
        }else if(IsOperator(s)){
            if(Top(S)=="\0"){
                Push(s,S);
                continue;
            }
            if(s=="-"){
                ss=ss+Top(S)+" ";
                Pop(S);
                Push(s,S);
            }else if(s=="+"){
                ss=ss+Top(S)+" ";
                Pop(S);
                Push(s,S);
            }else if(s=="*"){
                if(Top(S)=="+"||Top(S)=="-"){
                    Push(s,S);
                    continue;
                }else{
                    ss=ss+Top(S)+" ";
                    Pop(S);
                    Push(s,S);
                }
            }else if(s=="/"){
                if(Top(S)=="+"||Top(S)=="-"){
                    Push(s,S);
                    continue;
                }else{
                    ss=ss+Top(S)+" ";
                    Pop(S);
                    Push(s,S);
                }
            }
        }else{
            ss=ss+s+" ";
        }
    }
    while(Top(S)!="\0"){
        ss=ss+Top(S)+" ";
        Pop(S);
    }
    cout << "Output : ";
    cout << ss;
    cout << ".";
}