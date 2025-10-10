#include <iostream>
using namespace std;
int arr[10];

void DisplayMenu () {
	cout << "========Menu========" << endl;
	cout << "+    1) Insert     +" << endl;
	cout << "+    2) Delete     +" << endl;
	cout << "+    3) Print      +" << endl;
	cout << "+    4) Exit       +" << endl;
	cout << "====================" << endl;
	cout << "  Please choose > ";	
}

void PrintArr (int size) {
	int mid = (size + 1) / 2;
	
	if (size == -1) {
		cout << "No List For Print" << endl;
	} else {
			cout << endl << "Print         :";
	
			for (int i = 0;i <= size;i++){
				cout << " " << arr[i];
			}
		
		cout << endl << "Print First Half  :";
	
		if (size < 1) {
			cout << arr[0];
		} else {
			for (int i = 0;i <= mid;i++) {
				cout << " " << arr[i];
			}
		}
		
		cout << endl << "Print Second Half :";
		
		for (int i = mid;i <= size;i++) {
			cout << " " << arr[i];
		}
	}
}

void Print (int size, int choose) {
	if (choose == 3) {
		PrintArr (size);
	} 
	if (choose == 1 || choose == 2){
		cout << "Output : ";
		
		for (int i = 0;i <= size;i++){
			cout << " " << arr[i];
		}
	}
	cout << endl << endl;
}

int sort (int size) {
	int frist, next;
	
	if (size > 0) {
		for (int i = 0;i <= size - 1;i++) {
			frist = arr[i];
			next = arr[i + 1];
			
			if (frist > next) {
				arr[i] = next;
				arr[i + 1] = frist;	
			}
		}	
	}
}

int Insert (int size, int choose) {
	int Num;
	cout << "Enter : ";
	cin >> Num;
	
	if (++size <= 9) {
		for (int i = 9;i >= size;i--){
			arr[i] = arr[i - 1];
		}
		arr[0] = Num;
		sort(size);
		Print (size, choose);
	} else {
		cout << "Full List" << endl << endl;
		size = 9;
	}
	return size;
}

int Delete (int size,int choose) {
    int Num,Found = 0;

    if (size == -1) {
        cout << "No List For Delete" << endl << endl;
    } else {
        cout << "Delete : ";
        cin >> Num;

        for (int i = 0;i <= size;i++){
            if (arr[i] == Num) {
                for (int j = i; j <= size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                ++Found;
            }
        }
        if (Found == 0) {
            cout << "Not Found" << endl << endl;
        } else {
            size = size - Found;
            Print(size, choose);
        }
    }
    return size;
}

int main () {
	int size = -1, choose;
	while (1) {
		DisplayMenu ();
		cin >> choose;
			switch(choose) {
  			case 1: 	
				size = Insert (size, choose);
    			break;	
			case 2:
   				size = Delete (size, choose);
				break;
   			case 3: 
   				Print (size, choose);
   				break;
   			case 4:
   				exit(0);
   				break;
  			default:
  				cout << "Bye" << endl;
  				break;
		}
	}
}
