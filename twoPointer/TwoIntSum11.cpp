//Author: Sean Skaugen
#include <vector>
class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& numbers, int target) {
            int left = 0;
            int right = numbers.size() - 1;
            while(left < right){
                int current_sum = numbers[left] + numbers[right];
                //we have two cases > target and less < target
                if(current_sum > target){
                    right--;
                }
                else if(current_sum < target){
                    left++;
                }else{
                    return {left+1 , right+1};
                }
            }
            return {};
        }
    };