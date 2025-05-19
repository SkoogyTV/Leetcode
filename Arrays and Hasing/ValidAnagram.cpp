#include<unordered_map>
#include <string>
class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            if(s.size() != t.size()){
                return false;
            }
            else{
                std::unordered_map<char,int> char_counter_s;
                for(int i = 0; i < s.size(); i++){
                    if(char_counter_s.find(s[i]) != char_counter_s.end()){
                        char_counter_s[s[i]]++;
                    }else{
                        char_counter_s.insert({s[i],1});
                    }

                }
                for(int i = 0; i < t.size(); i++){
                    if(char_counter_s.find(t[i]) != char_counter_s.end()){
                        char_counter_s[t[i]]--;
                    }else{
                        return false;
                    }
                }

                //iterate through counter and ensure all keys are zero
                for(auto const pair : char_counter_s){
                    if(pair.second != 0){
                        return false;
                    }
                }

        }
        return true;
    }
};