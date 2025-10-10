#include <iostream>
#include <string>
#include <sstream> // this will allow you to use stringstream

using namespace std;

struct node{
    int value;
    struct node *next;
};
typedef struct node *Stack;

Stack CreateStack(void);
int IsEmpty(Stack s);
void MakeEmpty(Stack s);
void Push(int data,Stack s);
void Pop(Stack s);
int Top(Stack s);
int PostfixCal(string str,Stack s);

int main(){
    Stack s = CreateStack();
    string input,str;
    int result = 0;


    cout << "Input : ";
    while(true){
        cin >> input;
        if(input == "."){
            break;
        }
        str += input + " ";
    }

    result = PostfixCal(str,s);
    cout << "Output : " << result << endl;

    MakeEmpty(s);
    delete(s);

    return 0;
}

int PostfixCal(string str, Stack s){
    stringstream ss(str);
    string letter = "";
    int num = 0;

    while(ss >> letter){
        if(isdigit(letter[0]) || (letter[0] == '-' && letter.length() > 1)){ // negative number
            num = stoi(letter);
            Push(num,s);
        }else{
            int val1 = Top(s);
            Pop(s);
            int val2 = Top(s);
            Pop(s);
            switch(letter[0]){
            case '+':
                Push(val2 + val1, s);
                break;
            case '-':
                Push(val2 - val1, s);
                break;
            case '*':
                Push(val2 * val1, s);
                break;
            }
        }
    }
    return Top(s);
}

Stack CreateStack(void){
    Stack s = new struct node;
    if(s == NULL){
        cout << "Out of space!!" << endl;
    }
    s -> next = NULL;
    return s;
}

int IsEmpty(Stack s){
    return s -> next == NULL;
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

void Push(int data,Stack s){
    Stack tmpCell = new struct node;
    if(tmpCell == NULL){
        cout << "Out of space!!" << endl;
    }else{
        tmpCell -> value = data;
        tmpCell -> next = s -> next;
        s -> next = tmpCell;
    }
}

void Pop(Stack s){
    if(IsEmpty(s)){
        cout << "Empty Stack!!" << endl;
    }else{
        Stack firstCell = s -> next;
        s -> next = s -> next -> next;
        delete(firstCell);
    }
}

int Top(Stack s){
    if(!IsEmpty(s)){
        return s -> next -> value;
    }else{
        cout << "Empty Stack!!" << endl;
    }
    return 0;
}
