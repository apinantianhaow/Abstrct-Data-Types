#include <iostream>
using namespace std;

int main() {
    int grid[10][10];
    bool visited2x2[10][10] = { false };
    string line;

    for (int i = 0; i < 10; i++) {
        getline(cin, line);
        for (int j = 0; j < 10; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    int count = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!visited2x2[i][j] &&
                grid[i][j]     == 1 &&
                grid[i][j+1]   == 1 &&
                grid[i+1][j]   == 1 &&
                grid[i+1][j+1] == 1) 
				{
                count++;
                visited2x2[i][j] = true; 
            }
        }
    }

    cout << "Islands: " << count << endl;
    return 0;
}

