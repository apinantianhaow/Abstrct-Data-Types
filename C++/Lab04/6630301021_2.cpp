//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
    int con;
    int pow;
    struct record *next;
};

struct record *insert(struct record *phead) {
    int data;
    struct record *node, *pp;
    while (true) {
        cin >> data;
        if (data == -99)
            break;
        if (phead == NULL) {
            phead = new struct record;
            phead->con = data;
            cin >> data;
            phead->pow = data;
            phead->next = NULL;
            pp = phead;
        } else {
            node = new struct record;
            node->con = data;
            cin >> data;
            node->pow = data;
            node->next = NULL;
            pp->next = node;
            pp = node;
        }
    }
    return phead;
}

void printPolynomial(struct record *head) {
    struct record *p = head;
    while (p != NULL) {
        if (p->next != NULL) {
            if (p->pow != 0) {
                cout << p->con << "x^" << p->pow << " + ";
            } else {
                cout << p->con << " + ";
            }
        } else {
            if (p->pow != 0) {
                cout << p->con << "x^" << p->pow;
            } else {
                cout << p->con;
            }
        }
        p = p->next;
    }
    cout << endl;
}

struct record *addPolynomials(struct record *p1, struct record *p2) {
    struct record *result = NULL, *last = NULL;

    while (p1 != NULL && p2 != NULL) {
        struct record *node = new struct record;
        if (p1->pow > p2->pow) {
            node->con = p1->con;
            node->pow = p1->pow;
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            node->con = p2->con;
            node->pow = p2->pow;
            p2 = p2->next;
        } else {
            node->con = p1->con + p2->con;
            node->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        }
        node->next = NULL;
        if (result == NULL) {
            result = node;
            last = result;
        } else {
            last->next = node;
            last = node;
        }
    }
    while (p1 != NULL) {
        struct record *node = new struct record;
        node->con = p1->con;
        node->pow = p1->pow;
        node->next = NULL;
        if (last != NULL) {
            last->next = node;
        } else {
            result = node;
        }
        last = node;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        struct record *node = new struct record;
        node->con = p2->con;
        node->pow = p2->pow;
        node->next = NULL;
        if (last != NULL) {
            last->next = node;
        } else {
            result = node;
        }
        last = node;
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct record *p1 = NULL, *p2 = NULL, *result = NULL;

    cout << "Input P1 : ";
    p1 = insert(p1);

    cout << "Input P2 : ";
    p2 = insert(p2);

    result = addPolynomials(p1, p2);

    cout << "Output : ";
    printPolynomial(result);

    return 0;
}
