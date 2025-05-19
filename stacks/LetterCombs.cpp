//Author: Sean Skaugen
//Question 17: Letter Combinations of a phone number
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            
            if(digits.empty()) return {};
            vector<string> letter_maps = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            vector<string> ans = {};

            //we need to get the first mapping
            string first_mapping = letter_maps[digits[0] - '0' -2];
            for(char c : first_mapping){
                ans.push_back(string(1,c));
            }

            for(int i = 1; i < digits.size(); i++){
                //get the current mapping
                string curr_map = letter_maps[digits[i] - '0' - 2];
                vector<string> temp_ans;
                for(string& combo : ans){
                    for(char c : curr_map){
                        temp_ans.push_back(combo + c);
                    }
                }
                ans = temp_ans;
            }
            return ans;
        }
    };