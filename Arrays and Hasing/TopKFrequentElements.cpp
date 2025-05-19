//Author: Sean Skaugen
//Date: 11:53

#include <vector>
#include <unordered_map>
class Solution {
    public:
        std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
            std::vector<std::vector<int>> buckets(nums.size()+1);

            std::unordered_map<int,int> freq_counter;

            for(const auto& num : nums){
                freq_counter[num]++;
            }

            for(const auto& pair : freq_counter){
                buckets[pair.second].push_back(pair.first);
            }

            std::vector<int> result;
            bool done = false;
            for(int i = nums.size(); i >= 0; i--){
                std::vector<int> freq_at_index = buckets[i];
                if(freq_at_index.size() == 0) {continue;}
                else{
                    for(const auto& num : freq_at_index){
                        if(k > 0){
                            result.push_back(num);
                            k--;
                        }
                        else{
                            done = true;
                            break;
                        }
                    }
                }
                if(done){
                    break;
                }
            }
            return result;
        }
};