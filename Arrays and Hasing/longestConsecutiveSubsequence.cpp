//Author: Sean Skaugen
#include <vector>
#include <unordered_set>
class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            std::unordered_set<int> num_holder;

            for(const auto num : nums){
                num_holder.insert(num);
            }
            int longest_sub_final = 0;
            for(const auto& num : nums){
                if(num_holder.find(num) == num_holder.end()){
                    continue;
                }else{
                    if(num_holder.find(num - 1) == num_holder.end()){
                        //we are at the start of the sequence!
                        int current_sub_len = 1;
                        int current_num = num;

                        num_holder.erase(current_num);
                        current_num++;
                        while(num_holder.find(current_num) != num_holder.end()){
                            num_holder.erase(current_num);
                            current_num++;
                            current_sub_len++;
                        }
                        longest_sub_final = std::max(longest_sub_final,current_sub_len);
                    }
                }
            }
            return longest_sub_final;
        }
};

           /* //now the logic is pretty simple! if nums[i] - 1 is in the set this can not be the start of the subsequence so we skip
            int longest_sub = 0;
            for(int i = 0; i < nums.size(); i++){
                if(num_holder.find(nums[i]-1) != num_holder.end()){
                    continue;
                }else{
                    //we now can count the length of the subsequence!
                    int curr_num = nums[i];
                    int curr_sub = 0;
                    while(num_holder.find(curr_num) != num_holder.end()){
                        curr_sub++;
                        curr_num++;
                    }
                    longest_sub = std::max(longest_sub, curr_sub);
                }
            }

            return longest_sub;

        }
    };
    */