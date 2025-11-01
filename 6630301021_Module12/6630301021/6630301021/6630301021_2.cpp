//6630301021 Aphinan Thianhao

#include <iostream> 
#include <array> 
#include <utility> 
using namespace std;

int left(int i){
    return i * 2;
}

int right(int i){
    return i * 2 + 1;
}

int SizeOfHeap(array<int,30> &A){
    int n = 0;
    for(int L : A){
        if(L > 0){
            n++;
        }
    }
    return n;
}

void Heapify(array<int,30> &A, int i, int heapsize){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= heapsize && A[l] > A[i]){
        largest = l;
    }
    if(r <= heapsize && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        swap(A[i], A[largest]); 
        Heapify(A, largest, heapsize); 
    }
}

void ArrayToHeap(array<int,30> &A, int &heapsize){
    cout << endl;
    cout << "Array : ";
    for(int i = 1 ; i <= SizeOfHeap(A) ; i++){
        cout << A[i] << (i == SizeOfHeap(A) ? "" : " ");
    }
    cout << endl;
    cout << "Heap  : ";
    for(int i = heapsize / 2 ; i >= 1 ; i--){
        Heapify(A, i, heapsize);
    }
    for(int i = 1 ; i <= SizeOfHeap(A) ; i++){
        cout << A[i] << (i == SizeOfHeap(A) ? "" : " ");
    }
    cout << endl << endl;
}

void Build_heap(array<int,30> &A, int &heapsize){
    for(int i = heapsize / 2 ; i >= 1 ; i--){
        Heapify(A, i, heapsize);
    }
}

void Heapsort(array<int,30> &A, int &heapsize){
    Build_heap(A, heapsize);
    cout << endl;
    cout << "Heap : ";
    for(int i = 1 ; i <= heapsize ; i++){
        if(i == heapsize){
            cout << A[i];
        }else{
            cout << A[i] << " ";
        }
    }
    cout << endl;
    for(int i = heapsize ; i >= 1 ; i--){
        swap(A[1], A[i]);
        Heapify(A, 1, i - 1);
        cout << "#" << i << (i > 9 ? " : " : " : ");
        for(int j = 1 ; j <= SizeOfHeap(A) ; j++){
            cout << A[j] << (j == SizeOfHeap(A) ? "" : " ");
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    array<int,30> A = {-1, 10, 15, 2, 11, 9, 4, 3, 6, 18, 7};
    int heapsize = SizeOfHeap(A);
    int choose;

    while(true){
        cout << "===================" << endl;
        cout << "     MENU          " << endl;
        cout << "===================" << endl;
        cout << "1) Show array and change to Heap" << endl;
        cout << "2) Heap sort" << endl;
        cout << "3) Exit" << endl;
        cout << "   Please choose > ";
        cin >> choose;

        switch (choose){
            case 1:{
                ArrayToHeap(A, heapsize);
                break;
            }
            case 2:{
                Heapsort(A, heapsize);
                break;
            }
            case 3:{
                cout << endl;
                exit(0);
                break;
            }
        }
    }
    return 0;
}