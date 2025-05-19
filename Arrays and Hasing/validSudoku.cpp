//Author: Sean Skaugen

#include <vector>
#include <unordered_set>


class Solution {
    public:
        bool isValidSudoku(std::vector<std::vector<char>>& board) {
            bool valid = true;

            for(int row = 0; row < 9; row++){
                std::unordered_set<char> seen;
                for(int i = 0; i < 9; i++){
                    if(board[row][i] == '.'){
                        continue;
                    }
                    else{
                        //check and see if sudoku is valid or not!
                        if(seen.find(board[row][i]) != seen.end()){
                            valid = false;
                            return valid;
                        }else{
                            seen.insert(board[row][i]);
                        }
                    }
                }
            }
            for(int col = 0; col < 9; col ++){
                std::unordered_set<char> seen;
                for(int i = 0; i < 9; i++){
                    if(board[i][col] == '.'){
                        continue;
                    }else{
                        if(seen.find(board[i][col]) != seen.end()){
                            valid = false;
                            return valid;
                        }else{
                            seen.insert(board[i][col]);
                    }
                }
            }
        }
        for(int square = 0; square < 9; square++){
            std::unordered_set<char> seen;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;

                    if(board[row][col] == '.'){
                        continue;
                    }else{
                        if(seen.find(board[row][col]) != seen.end()){
                            valid = false;
                            return valid;
                        }else{
                            seen.insert(board[row][col]);
                        }
                    }
                }
            }
        }
        return valid;
            //now we need to check the actual squares!!
            //how do we do this! We do this by
            // row / 3

    }
};

    //create a hash table can check the the 3x3s
    //hash table to check the vertical lines
    //hash tables to check the horizontal lines

