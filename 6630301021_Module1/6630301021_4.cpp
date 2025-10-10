//6630301021 Aphinan Thianhao 

#include <iostream>
using namespace std;

int main() {
    cout << "input : " << endl;
    int map[12][12];

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            map[i][j] = 0;

    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
            cin >> map[i][j];

    int count = 0;

    for (int i = 1; i < 10; i++) {         
        for (int j = 1; j < 10; j++) {     
            if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1 && map[i - 1][j] == 0 && 
                map[i - 1][j + 1] == 0 && map[i + 2][j] == 0 && map[i + 2][j + 1] == 0 && map[i][j + 2] == 0 && map[i + 1][j + 2] == 0) {
                map[i][j] = map[i][j + 1] = map[i + 1][j] = map[i + 1][j + 1] = 0;
                count++;
            }
        }
    }

    cout << endl << "Islands: " << count << endl;
    
    return 0;
}

