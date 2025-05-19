#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0, back = nums.size()-1, middle = 0;

        while(front <= back){
            middle = front + (back - front) / 2;
            if(nums[middle] > nums[nums.size()-1]){ //where the pivot will be!!
                front = middle + 1;
            }else{
                back = middle - 1;
            }
        }
        int res = specificBinSearch(nums, 0, front - 1, target);
        if(res != -1) return res;
        return specificBinSearch(nums, front, nums.size()-1, target);
    }

    int specificBinSearch(vector<int>& nums, int front_bound, int back_bound, int target){

        int left = front_bound, right = back_bound, middle = 0;

        while(left <= right){
            middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }else if(nums[middle] > target){
                right = middle - 1;
            }else{
                left = middle + 1;
            }   
        }
        return -1;
    }
};