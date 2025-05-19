#include <vector>
class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            int zero_cnt = 0;
            int product_non_zero = 1;

            std::vector<int> result(nums.size(),0);
            for(const auto& num: nums){
                if(num == 0){
                    zero_cnt++;
                }
                else{
                    product_non_zero *= num;
                }

            }

            for(int i = 0; i < result.size(); i++){
                if(zero_cnt > 1){
                    break; //will be all zeros
                }
                else if(zero_cnt == 1){
                    //all positions will be zero besides the index of the position
                    result[i] = (nums[i] == 0) ? product_non_zero : 0; 
                }
                else{
                    result[i] = product_non_zero / nums[i];
                }
            }

            return result;
        }
    };