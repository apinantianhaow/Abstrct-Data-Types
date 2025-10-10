//6530300601 Sophonwit Thapseng
#include <iostream>
#include <string>
#include <set>

using namespace std;

bool InBound(int x,int y,int row,int col);

bool CheckDir(string word,string dir[],int dirSize);

int main()
{
    int count = 0;
    char puzzle[4][4] =
    {
        {'T','H','I','S'},
        {'W','A','T','S'},
        {'O','A','H','G'},
        {'F','G','D','T'}
    };

    string dir[] =
    {
        "IS","THIS","HIS","AT","YOU","HI","IT","TWO",
        "OF","FAT","THAT","HAT","GOD","CAT","AN","FOUR"
    };

    int dirSize = sizeof(dir) / sizeof(dir[0]);

    int row = 4,col = 4;
    int direc[8][2] =
    {
        {-1,0},{1,0},{0,-1},{0,1},
        {-1,-1},{-1,1},{1,-1},{1,1}
    };

    set<string> foundWord;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                int x = i,y = j;
                string word = "";
                while(InBound(x,y,row,col))
                {
                    word += puzzle[x][y];
                    cout << word;
                    if(CheckDir(word,dir,dirSize) && foundWord.find(word) == foundWord.end())
                    {
                        foundWord.insert(word);
                        count++;
                        cout << " Found " << count;
                    }
                    cout << endl;
                    x += direc[k][0];
                    y += direc[k][1];
                }
            }
        }
    }

    cout << "Total = " << count << endl;
    return 0;
}

bool InBound(int x,int y,int row,int col)
{
    return x >= 0 && y >= 0 && x < row && y < col;
}

bool CheckDir(string word,string dir[],int dirSize)
{
    for(int i = 0;i < dirSize;i++)
    {
        if(word == dir[i])
        {
            return true;
        }
    }
    return false;
}

