#include <iostream>

using namespace std;

struct node{
    char value;
    struct node *next;
};
typedef struct node *Stack;

Stack CreateStack(void);
int IsEmpty(Stack s);
void MakeEmpty(Stack s);
void Push(char ch,Stack s);
void Pop(Stack s);
char Top(Stack s);
//void CountSymbol(Stack s,int &openCount,int &closeCount);

int main(){
    Stack s = CreateStack();
    bool error = false;
    char ch = '\0';
    char letter;

    cout << "Input: ";
    while(ch != '.'){
        ch = getchar();
        if(ch == '.'){
            break;
        }
        if(ch == '(' || ch == '{' || ch == '['){
            Push(ch,s);
            // cout << "Push : " << Top(s) << endl;  // Debug
        }else if(ch == ')' || ch == '}' || ch == ']'){
            if(!IsEmpty(s)){
                letter = Top(s);
                if((ch == ')' && letter == '(') ||
                   (ch == '}' && letter == '{') ||
                   (ch == ']' && letter == '[')){
                    // cout << "Top : " << letter << endl;  // Debug
                    Pop(s);
                }else{
                    cout << "Error! Inconsistent symbol" << endl;  // Error message for inconsistent symbols
                    error = true;
                    break;
                }
            }else{
                cout << "Error! No open symbol" << endl;  // Error message for no opening symbol
                error = true;
                break;
            }
        }
    }

    if(!error){
        if(!IsEmpty(s)){
            cout << "Error! Excess symbols" << endl;  // Error message for excess symbols
            /*
            while(!IsEmpty(s))
            {
                char c = Top(s);
                // cout << "Stack : " << c << endl;  // Debug
                Pop(s);
            }
            */
        }
    }

    /*
    while(!IsEmpty(s))
    {
        // cout << "Stack Top : " << Top(s) << endl;  // Debug
        Pop(s);
    }
    */

    return 0;
}
/*
void CountSymbol(Stack s,int &openCount,int &closeCount)
{
    openCount = 0;
    closeCount = 0;

    while(!IsEmpty(s))
    {
        char ch = Top(s);
        if(ch == '(' || ch == '{' || ch == '[')
        {
            openCount++;
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            closeCount++;
        }
        Pop(s);
    }
}
*/
Stack CreateStack(void){
    Stack s = new struct node;
    if(s == NULL){
        cout << "Out of space!!" << endl;
    }
    s -> next = NULL;
    return s;
}

void Push(char ch,Stack s){
    Stack tmpCell = new struct node;
    if(tmpCell == NULL){
        cout << "Out of space!!" << endl;
    }else{
        tmpCell -> value = ch;
        tmpCell -> next = s -> next;
        s -> next = tmpCell;
    }
}

void MakeEmpty(Stack s){
    if(s == NULL){
        cout << "Must use CreateStack first" << endl;
    }else{
        while(!IsEmpty(s)){
            Pop(s);
        }
    }
}

int IsEmpty(Stack s){
    return s -> next == NULL;
}

char Top(Stack s){
    if(!IsEmpty(s)){
        return s -> next -> value;
    }else{
        cout << "Empty Stack!!" << endl;
    }
    return 0;
}

void Pop(Stack s){
    Stack firstCell;
    if(IsEmpty(s)){
        cout << "Empty Stack!!" << endl;
    }else{
        firstCell = s -> next;
        s -> next = s -> next -> next;
        delete(firstCell);
    }
}
