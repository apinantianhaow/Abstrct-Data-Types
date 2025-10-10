#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool isWordInDictionary(string word, vector<string> &dictionary) {
    return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

int main() {
    int i, j, k, total = 0;
    char puzzle[4][4] = {
        {'T', 'H', 'I', 'S'},
        {'W', 'A', 'T', 'S'},
        {'O', 'A', 'H', 'G'},
        {'F', 'G', 'D', 'T'}
    };

    string dicArray[] = {"THIS", "HIS", "IS", "HI", "AT", "IT", "TWO", "OF", "THAT", "HAT", "FAT"};
    vector<string> dictionary(begin(dicArray), end(dicArray));
    string temp = "";

    // Search horizontally
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            temp = "";
            for(k = j; k < 4; k++) {
                temp += puzzle[i][k];
                if(isWordInDictionary(temp, dictionary)) {
                    cout << "Found: " << temp << endl;
                    total++;
                }
            }
        }
    }

    // Search vertically
    for(j = 0; j < 4; j++) {
        for(i = 0; i < 4; i++) {
            temp = "";
            for(k = i; k < 4; k++) {
                temp += puzzle[k][j];
                if(isWordInDictionary(temp, dictionary)) {
                    cout << "Found: " << temp << endl;
                    total++;
                }
            }
        }
    }

    // Search diagonally (top-left to bottom-right)
    for(int start = 0; start < 4; start++) {
        temp = "";
        for(i = start, j = 0; i < 4 && j < 4; i++, j++) {
            temp += puzzle[i][j];
            if(isWordInDictionary(temp, dictionary)) {
                cout << "Found: " << temp << endl;
                total++;
            }
        }
    }
    for(int start = 1; start < 4; start++) {
        temp = "";
        for(i = 0, j = start; i < 4 && j < 4; i++, j++) {
            temp += puzzle[i][j];
            if(isWordInDictionary(temp, dictionary)) {
                cout << "Found: " << temp << endl;
                total++;
            }
        }
    }

    // Search diagonally (top-right to bottom-left)
    for(int start = 0; start < 4; start++) {
        temp = "";
        for(i = start, j = 3; i < 4 && j >= 0; i++, j--) {
            temp += puzzle[i][j];
            if(isWordInDictionary(temp, dictionary)) {
                cout << "Found: " << temp << endl;
                total++;
            }
        }
    }
    for(int start = 2; start >= 0; start--) {
        temp = "";
        for(i = 0, j = start; i < 4 && j >= 0; i++, j--) {
            temp += puzzle[i][j];
            if(isWordInDictionary(temp, dictionary)) {
                cout << "Found: " << temp << endl;
                total++;
            }
        }
    }

    cout << "Total words found: " << total << endl;

    return 0;
}

