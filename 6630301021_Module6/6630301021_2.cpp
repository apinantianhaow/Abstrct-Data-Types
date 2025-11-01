// 6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct Node;
typedef struct Node* Stack;

int IsEmpty (Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(int x, Stack S);
void Pop(Stack S);
int Top(Stack S);

struct Node {
    int value;
    struct Node *next;
};


int IsEmpty (Stack S) {
    return S->next == NULL;
}

Stack CreateStack (void) {
    Stack S;
    S = new struct Node;
    if (S == NULL) {
        cout << "Out of space!!!" << endl;
    } 
    S->next = NULL;
    return S;
}

void MakeEmpty (Stack S) {
    if (S == NULL) {
        cout << "Must use CreateStack First" << endl;
    } else {
        while (!IsEmpty(S)){
            Pop(S);
        }
        cout << "Stack Empty" << endl;
    }
}

void Push (int x, Stack S) {
    Stack TmpCell;
    TmpCell = new struct Node;
    if (TmpCell == NULL) {
        cout << "Out of Space!!!" << endl;
    } else {
        TmpCell->value = x;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

void Pop (Stack S) {
    Stack FirstCell;
    if (!IsEmpty(S)) {
        FirstCell = S->next;
        S->next = S->next->next;
        delete(FirstCell);
    } else {
        cout << "Stack Overflow!!!" << endl;
    }
}

int Top (Stack S) {
    if(!IsEmpty(S)) {
        return S->next->value;
    } else {
        cout << "Empty Stack!!!" << endl;
        return -1;
    }
}

int main() {
    Stack S = CreateStack();
    string n;
    string word = "";
    cout << "Input : ";
    getline(cin, n);
    for (int i = 0 ; i < n.size() ; i++) {
    if (n[i] != '.') {
        char s = n[i];
        if (isdigit(s)) {
            word += s;
        } else if (s == ' ' && word != "") {
            int x = stoi(word);
            Push(x, S);
            word = "";
        } else if (s == '+' || s == '-' || s == '*' || s == '/') {
            int a, b, sum;
            if(s == '+'){
                 a = Top(S); Pop(S);
                 b = Top(S); Pop(S);
                 sum = b + a;
                 Push(sum, S);
                }
            if(s == '-'){
                 a = Top(S); Pop(S);
                 b = Top(S); Pop(S);
                 sum = b - a;
                 Push(sum, S);
                }
            if(s == '*'){
                 a = Top(S); Pop(S);
                 b = Top(S); Pop(S);
                 sum = b * a;
                 Push(sum, S);
                }
            if(s == '/'){
                 a = Top(S); Pop(S);
                 b = Top(S); Pop(S);
                 sum = b / a;
                 Push(sum, S);
                }
            }
        }
    }
    cout << Top(S) << endl;

    return 0;
} 

// ===========================================================

// #include <iostream>
// #include <string>
// #include <sstream>
// using namespace std;

// struct Node;
// typedef struct Node* Stack;

// int IsEmpty (Stack S);
// Stack CreateStack(void);
// void MakeEmpty(Stack S);
// void Push(int x, Stack S);
// void Pop(Stack S);
// int Top(Stack S);

// struct Node {
//    int value;
//    struct Node *next;
// };

// int IsEmpty(Stack S){
//    return S->next == NULL;
// }

// Stack CreateStack(void){
//    Stack S;
//    S = new struct Node;
//    if(S == NULL){
//        cout << "Out of space!!!" << endl;
//    }
//    S->next = NULL;
//    return S;
// }

// void MakeEmpty(Stack S){
//    if(S == NULL){
//        cout << "Must use CreateStack First" << endl;
//    }else{
//        while(!IsEmpty(S)){
//            Pop(S);
//        }
//        cout << "Stack Empty" << endl;
//    }
// }

// void Push(int x, Stack S){
//    Stack TmpCell;
//    TmpCell = new struct Node;
//    if(TmpCell == NULL){
//        cout << "Out of Space!!!" << endl;
//    }else{
//        TmpCell->value = x;
//        TmpCell->next = S->next;
//        S->next = TmpCell;
//    }
// }

// void Pop(Stack S){
//    Stack FirstCell;
//    if(!IsEmpty(S)){
//        FirstCell = S->next;
//        S->next = S->next->next;
//        delete(FirstCell);
//    }else{
//        cout << "Stack Overflow!!!" << endl;
//    }
// }

// int Top(Stack S){
//    if(!IsEmpty(S)){
//        return S->next->value;
//    }else{
//        cout << "Empty Stack!!!" << endl;
//        return -1;
//    }
// }

// int main(){
//    Stack S = CreateStack();
//    string n;
//    string word = "";
//    cout << "Input : ";
//    getline(cin, n);

//    for(int i = 0 ; i < n.size() ; i++){
//        if(n[i] != '.'){
//            char s = n[i];
//            if(isdigit(s)){
//                word += s;
//            }else if(s == ' ' && word != ""){
//                int x;
//                stringstream ss(word);
//                ss >> x;
//                Push(x, S);
//                word = "";
//            }else if(s == '+' || s == '-' || s == '*' || s == '/'){
//                int a, b, sum;
//                if(s == '+'){
//                    a = Top(S); Pop(S);
//                    b = Top(S); Pop(S);
//                    sum = b + a;
//                    Push(sum, S);
//                }
//                if(s == '-'){
//                    a = Top(S); Pop(S);
//                    b = Top(S); Pop(S);
//                    sum = b - a;
//                    Push(sum, S);
//                }
//                if(s == '*'){
//                    a = Top(S); Pop(S);
//                    b = Top(S); Pop(S);
//                    sum = b * a;
//                    Push(sum, S);
//                }
//                if(s == '/'){
//                    a = Top(S); Pop(S);
//                    b = Top(S); Pop(S);
//                    sum = b / a;
//                    Push(sum, S);
//                }
//            }
//        }
//    }

//    if(word != ""){
//        int x;
//        stringstream ss(word);
//        ss >> x;
//        Push(x, S);
//    }

//    cout << "Output : " << Top(S) << endl;
//    return 0;
// }
