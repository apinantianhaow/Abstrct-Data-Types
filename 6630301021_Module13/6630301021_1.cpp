//6630301021 Aphinan Thianhao

#include <iostream> 
#include <array>  //use array
#include <utility>  //can use exchange and swap
using namespace std;

int left(int i){
    return i * 2;
}

int right(int i){
    return i * 2 + 1;
}

int sizeofheap(array<int,30> &A){
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

int main(){
    array<int,30> A = {-1, 10, 15, 2, 11, 9, 4, 3, 6, 18, 7};
    int heapsize = sizeofheap(A);
    for(int i = heapsize / 2 ; i >= 1 ; i--){
        Heapify(A, i, heapsize);
        cout << "#" << i << " :  ";
        for(int j = 1 ; j <= heapsize ; j++){
            if(j == heapsize){

                cout << A[j];
            }else{
                cout << A[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}