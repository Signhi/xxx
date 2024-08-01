#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int tag = 0;
        int r = rMove, c = cMove;
        if(c + 1 < 8){
            if(board[r][c + 1] != color){
                int temp = c + 1;
                while(temp < 8 && board[r][temp] != color && board[r][temp] != '.') temp++;
                if(temp != 8 && board[r][temp] != '.') return true;
            }
            
        }
        if(c - 1 >= 0){
            if(board[r][c - 1] != color){
                int temp = c - 1;
                while(temp >= 0 && board[r][temp] != color && board[r][temp] != '.') temp--;
                if(temp != -1 && board[r][temp] != '.') return true;
            }
            
        }
        if(r + 1 < 8){
            if(board[r + 1][c] != color){
                int temp = r + 1;
                while(temp < 8 && board[temp][c] != color && board[temp][c] != '.') temp++;
                if(temp != 8 && board[temp][c] != '.') return true;
            }
        }
        if(r - 1 >= 0){
            if(board[r - 1][c] != color){
                int temp = r - 1;
                while(temp >= 0 && board[temp][c] != color  && board[temp][c] != '.') temp--;
                if(temp != -1  && board[temp][c] != '.') return true;
            }
            
        }
        if(r - 1 >= 0 && c - 1 >= 0){
            if(board[r - 1][c - 1] != color){
                int temp_1 = r - 1, temp_2 = c - 1;
                while(temp_1 >= 0 && temp_2 >= 0 && board[temp_1][temp_2] != color && board[temp_1][temp_2] != '.'){
                    temp_1--;
                    temp_2--;
                }
                if(temp_1 != -1 && temp_2 != - 1 && board[temp_1][temp_2] != '.') return true;
            }
            
        }
        if(r - 1 >= 0 && c + 1 < 8){
            if(board[r - 1][c + 1] != color){
                int temp_1 = r - 1, temp_2 = c + 1;
                while(temp_1 >= 0 && temp_2 < 8 && board[temp_1][temp_2] != color && board[temp_1][temp_2] != '.'){
                    temp_1--;
                    temp_2++;
                }
                if(temp_1 != -1 && temp_2 != 8 && board[temp_1][temp_2] != '.') return true;
            }
            
        }
        if(r + 1 < 8 && c + 1 < 8){
            if(board[r + 1][c + 1] != color){
                 int temp_1 = r + 1, temp_2 = c + 1;
                while(temp_1 < 8 && temp_2 < 8 && board[temp_1][temp_2] != color && board[temp_1][temp_2] != '.'){
                    temp_1++;
                    temp_2++;
                }
                if(temp_1 != 8 && temp_2 != 8 && board[temp_1][temp_2] != '.') return true;
            }
           
        }
        if(r + 1 < 8 && c - 1 >= 0){
            if(board[r + 1][c - 1] != color){
                int temp_1 = r + 1, temp_2 = c - 1;
                while(temp_1 < 8 && temp_2 >= 0 && board[temp_1][temp_2] != color && board[temp_1][temp_2] != '.'){
                    temp_1++;
                    temp_2--;
                }
                if(temp_1 != 8 && temp_2 != -1 && board[temp_1][temp_2] != '.') return true;
            }
            
        }
        return false;

    }
};


int main(){
    vector<vector<char>> v = {
        {'W','W','W','.','.','B','W','B'},
        {'W','.','W','B','B','W','B','W'},
        {'.','W','W','B','.','W','B','W'},
        {'.','.','B','.','B','.','B','B'},
        {'.','W','.','.','.','W','B','.'},
        {'W','W','.','.','B','B','.','.'},
        {'W','.','W','B','B','B','W','B'},
        {'B','B','.','W','.','.','.','W'}};
    Solution s;
    bool b = s.checkMove(v, 4, 2, 'B');
    
    return 0;
}


