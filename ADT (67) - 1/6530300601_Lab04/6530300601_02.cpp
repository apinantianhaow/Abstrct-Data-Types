#include <iostream>

using namespace std;

struct record{
    int value;
    int pow;
    struct record *next;
};

struct record *InsertList(struct record *head,int data,int count){
    struct record *node,*p;

    // check count เป็นเลขคี่หรือไม่
    if(count % 2 == 1){
        if(head == NULL){
            head = new struct record;
            head -> value = data;
            head -> pow = 0;
            head -> next = NULL;
        }else{
            node = new struct record;
            node -> value = data;
            node -> pow = 0;
            node -> next = NULL;
            p = head;
            while(p -> next != NULL){
                p = p -> next;
            }
            p -> next = node;
        }
    }else{
        p = head;
        while(p -> next != NULL){ // หาโหนดสุดท้าย
            p = p -> next;
        }
        p -> pow = data;
    }

    return head;
}

void printAll(struct record *head){ // check
    struct record *tmp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << endl << "List = ";
        tmp = head;
        while(tmp != NULL){
            cout << tmp -> value << " ";
            cout << tmp -> pow << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}

void printTerm(int value,int pow){
    cout << value;
    if(pow == 1){
        cout << "x^1";
    }else if(pow > 1){
        cout << "x^" << pow;
    }
}

void printDuo(struct record *headP,struct record *headPP){
    struct record *tmpP = headP;
    struct record *tmpPP = headPP;

    while(tmpP != NULL || tmpPP != NULL){
        if(tmpP == NULL){  // ถ้า   headP ว่าง
            printTerm(tmpPP -> value,tmpPP -> pow);
            tmpPP = tmpPP -> next;
        }else if(tmpPP == NULL){  // ถ้า    headPP ว่าง
            printTerm(tmpP -> value,tmpP -> pow);
            tmpP = tmpP -> next;
        }else{
            if(tmpP -> pow > tmpPP -> pow){  // เปรียบเทียบค่า  pow
                printTerm(tmpP -> value,tmpP -> pow);
                tmpP = tmpP -> next;
            }else if(tmpP -> pow < tmpPP -> pow){
                printTerm(tmpPP -> value,tmpPP -> pow);
                tmpPP = tmpPP -> next;
            }else{
                printTerm(tmpP -> value + tmpPP -> value,tmpP -> pow);
                tmpP = tmpP -> next;
                tmpPP = tmpPP -> next;
            }
        }
        if(tmpP != NULL || tmpPP != NULL){
            cout << " + ";
        }
    }
}

int main(){
    struct record *headP = NULL;
    struct record *headPP = NULL;
    int num,countP = 0,countPP = 0;

    cout << "Input P1 : ";
    do{
        cin >> num;
        if(num != -99){
            countP++;
            headP = InsertList(headP,num,countP);
        }
    }while(num != -99);

    cout << "Input P2 : ";
    do{
        cin >> num;
        if(num != -99){
            countPP++;
            headPP = InsertList(headPP,num,countPP);
        }
    }while(num != -99);

    cout << "Output : ";
    printDuo(headP,headPP);

    return 0;
}
