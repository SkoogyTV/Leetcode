//Author: Sean Skaugen
//LeetCode 74: Search a 2D Matrix
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //so this is really doing 2 binary searches!
        if(matrix.size() == 0) return false;

        int top = 0, bot = matrix.size()-1, row = 0;

        while(top<=bot){
            row = top + (bot - top) / 2;
            //nums[row][0] < target < nums[row][n-1]
            if(target < matrix[row][0] ){
                bot = row - 1;
            }
            else if(target > matrix[row][matrix[row].size()-1]){
                top = row + 1;
            }else{
                break; //found row
            }
        }
        if(!(top<=bot)) return false;
        //now we do a simple binary search
        int left = 0, right = matrix[0].size()-1;

        while(left<=right){
            int mid = left + (right - left) / 2;

            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};