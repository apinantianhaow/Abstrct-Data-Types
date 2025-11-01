//6630301021 Aphinan Thianhao

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
const int NUM_ELEMENTS = 3000000;
int data[NUM_ELEMENTS];
int tempArray[NUM_ELEMENTS];

void readfile() {
    ifstream readfile;
    readfile.open("randomfile.text");

    if (!readfile.is_open()) {
        cout << "Error: Cannot open 'randomfile.text'." << endl;
        cout << "Please use Option 1 to create the file first." << endl;
        return;
    }

    cout << endl << "Reading data from file..." << endl;
    for(int i = 0 ; i < NUM_ELEMENTS ; i++)
    {
        if (!(readfile >> data[i])) {
            break;
        }
    }

    cout << "Data read successfully." << endl;
    readfile.close();
}

void createfile() {
    ofstream writefile;
    writefile.open("randomfile.text");
    cout << "create file" << endl;
    for(int i = 0 ; i < NUM_ELEMENTS ; i++)
    {
        writefile << rand()%100000 << " ";
    }
    cout << "success" << endl;
    writefile.close();

    readfile();
}

void selectionsort(int a[],int n) {
    int i, j, minindex, tmp;
    for(i = 0 ; i < n ; i++)
    {
        minindex = i;
        for(j = i + 1 ; j < n ; j++)
        {
            if (a[j] < a[minindex])
        {
            minindex = j;
        }
        }
        if(minindex != i)
        {
            tmp = a[minindex];
            a[minindex] = a[i];
            a[i] = tmp;
        }
    }
}

void bubblesort(int a[],int n) {
    int i, j, tmp;
    bool change;
    for(i = 0 ; i < n-1 ; i++)
    {
        change = false;
        for(j = 0 ; j < n-i-1 ; j++)
        {
            if(a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                change = true ;
            }
        }
       if(change == false)
       {
           break;
       }
    }
}

void insertionsort(int a[],int N) {
    int p, j, tmp;
    for(p = 1; p < N ; p++)
    {
        for(j = p ; j > 0 ; j--)
        {
            if(a[j] < a[j-1])
            {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
            else{
                    break;
            }
        }
    }
}

void merge(int a[],int tmparr[],int lpos, int rpos,int rightend) {
    int i,leftend,numelements,tmppos;
    leftend = rpos - 1 ;
    tmppos = lpos;
    numelements = rightend - lpos + 1;
    while(lpos <= leftend && rpos <= rightend)
    {
        if(a[lpos] <= a[rpos])
        {
            tmparr[tmppos++] = a[lpos++];
        }
        else{
            tmparr[tmppos++] = a[rpos++];
        }
    }
    while(lpos <= leftend)
    {
        tmparr[tmppos++] = a[lpos++];
    }
    while(rpos <= rightend)
    {
        tmparr[tmppos++] = a[rpos++];
    }
    for(i = 0 ; i < numelements ; i++,rightend--)
    {
        a[rightend] = tmparr[rightend];
    }
}

void mergesort(int a[],int tmparr[],int left,int right) {
    int center;
    if(left < right)
    {
        center = (left + right) / 2;
        mergesort(a, tmparr, left, center);
        mergesort(a, tmparr, center + 1, right);
        merge(a, tmparr, left, center + 1, right);
    }
}

int group(int a[],int low ,int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(a[pivotIndex], a[high]);
    int pivot = a[high];
    int tmp;
    int i = (low - 1);
    for(int j = low ; j <= high - 1 ; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[high];
    a[high] = tmp;
    
    return(i+1);
}

void quicksort(int a[],int low,int high) {
    if(low < high)
    {
        int b = group(a, low, high);
        quicksort(a, low, b - 1);
        quicksort(a, b + 1, high);
    }
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }

}

void bucketsort(int a[], int n) {
    if (n <= 0) return;
    const int BUCKET_RANGE = 10000;
    int max_val = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > max_val) {
            max_val = a[i];
        }
    }
    int numBuckets = (max_val / BUCKET_RANGE) + 1;
    vector<vector<int>> buckets(numBuckets);
    for (int i = 0; i < n; i++) {
        int bucket_index = a[i] / BUCKET_RANGE;
        buckets[bucket_index].push_back(a[i]);
    }
    for (int i = 0; i < numBuckets; i++) {
        if (!buckets[i].empty()) {
            insertionsort(&buckets[i][0], buckets[i].size());
        }
    }
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            a[index++] = buckets[i][j];
        }
    }
}

int getMax(int a[], int n) {
    int max_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }
    return max_val;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixsort(int a[],int n) {
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(a, n, exp);
    }

}

int main()
{
    srand(time(0));
    bool check = true;
    while(check){
        cout << "      MENU          " << endl;
        cout << "1)Create random file" << endl;
        cout << "2)Selection sort " << endl;
        cout << "3)Bubble sort " << endl;
        cout << "4)Insertion sort " << endl;
        cout << "5)Merge sort" << endl;
        cout << "6)Quick sort" << endl;
        cout << "7)Heap sort" << endl;
        cout << "8)Bucket sort" << endl;
        cout << "9)Radix sort" << endl;
        cout << "10)Exit" << endl;
        cout << "Please choose > ";
        int choose;
        cin >> choose;
        ofstream outfile;

        switch(choose) {
        case 1:
            createfile();
            break;
        case 2:
            readfile();
            selectionsort(data, NUM_ELEMENTS);
            cout << "Selection Sort success" << endl;
            outfile.open("selection.txt");
            for(int i=0; i < NUM_ELEMENTS; i++)
            {
                outfile << data[i] << " ";
            }
            outfile.close();
            break;
        case 3:
            readfile();
            bubblesort(data, NUM_ELEMENTS);
            cout << "Bubble Sort success" << endl;
            outfile.open("bubble.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;
        case 4 :
            readfile();
            insertionsort(data, NUM_ELEMENTS);
            cout << "Insertion Sort success" << endl;
            outfile.open("insertion.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;
        case 5 :
            readfile();
            mergesort(data, tempArray, 0, NUM_ELEMENTS - 1);
            cout << "Merge Sort success" << endl;
            outfile.open("merge.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;
        case 6 :
            readfile();
            quicksort(data, 0, NUM_ELEMENTS - 1);
            cout << "Quick Sort success" << endl;
            outfile.open("quick.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;

        case 7 :
            readfile();
            heapsort(data, NUM_ELEMENTS);
            cout << "Heap Sort success" << endl;
            outfile.open("heap.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;
        case 8 :
            readfile();
            bucketsort(data, NUM_ELEMENTS);
            cout << "Bucket Sort success" << endl;
            outfile.open("bucket.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;
        case 9 :
            readfile();
            radixsort(data, NUM_ELEMENTS);
            cout << "Radix Sort success" << endl;
            outfile.open("radix.txt");
            for(int i=0; i < NUM_ELEMENTS; i++) { outfile << data[i] << " "; }
            outfile.close();
            break;
	    case 10 :
	    	exit(0);
	    	break;
        }
    }
}
