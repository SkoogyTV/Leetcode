#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
            
            std::unordered_map<std::string, std::vector<std::string>> holder;
            
            //we need to look ar every single string in the vector list

            for(const auto& str : strs){
                std::vector<int> count(26,0);

                for(auto c : str){
                    count[c - 'a']++;
                }

                std::string key = std::to_string(count[0]);
                for(int i = 0; i < 26; i++){
                    key+= ',' + std::to_string(count[i]);
                }
                holder[key].push_back(str);
            }

            std::vector<std::vector<std::string>> result;
            for(const auto& pair : holder){
                result.push_back(pair.second);
            }
            return result;
        }
    };
    

    int main(){

        Solution solu;
        

        return 0;
    }