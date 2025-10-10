#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

struct node{
    char value;
    struct node *next;
};
typedef struct node *Stack;

Stack CreateStack(void);
int IsEmpty(Stack s);
void MakeEmpty(Stack s);
void Push(char data,Stack s);
void Pop(Stack s);
char Top(Stack s);
int Precedence(char c);
void InfixToPostfix(string str,Stack s);

int main(){
    Stack s = CreateStack();
    string str,input;

    cout << "Input: ";
    while(true){
        cin >> input;
        if(input == "."){
            break;
        }
        str += input + " ";
    }

    InfixToPostfix(str,s);

    MakeEmpty(s);
    delete(s);

    return 0;
}

void InfixToPostfix(string str,Stack s){
    string result = "";
    stringstream ss(str);
    string letter;

    while(ss >> letter){
        if(isdigit(letter[0])){
            result += letter + " ";
        }else if(letter == "("){
            Push('(',s);
        }else if(letter == ")"){
            while(!IsEmpty(s) && Top(s) != '('){
                result += Top(s);
                result += " ";
                Pop(s);
            }
            if(!IsEmpty(s) && Top(s) == '('){
                Pop(s);
            }
        }else{
            while(!IsEmpty(s) && Precedence(letter[0]) <= Precedence(Top(s))){
                result += Top(s);
                result += " ";
                Pop(s);
            }
            Push(letter[0],s);
        }
    }

    while(!IsEmpty(s)){
        result += Top(s);
        result += " ";
        Pop(s);
    }

    cout << "Output: " << result << endl;
}

int Precedence(char c){
    if(c == '*' || c == '/'){
        return 2;
    }else if(c == '+' || c == '-'){
        return 1;
    }else{
        return 0;
    }
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

void Push(char data,Stack s){
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

char Top(Stack s){
    if(!IsEmpty(s)){
        return s -> next -> value;
    }else{
        cout << "Empty Stack!!" << endl;
    }
    return '\0';
}
