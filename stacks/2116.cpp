//Author: Sean Skaugen
//2116. Check if a Parentheses String Can Be Valid
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        bool canBeValid(string s, string locked) {
        
            if(s.length() % 2 == 1) return false;

            stack<int> open_brack, unlocked_brack;
            
            for(int i = 0; i < s.size(); i++){
                if(locked[i] == '0'){
                    unlocked_brack.push(i);
                }
                else if(s[i] == '('){
                    open_brack.push(i);
                }
                else{
                    if(!open_brack.empty()){
                        open_brack.pop();
                    }
                    else if(!unlocked_brack.empty()){
                        unlocked_brack.pop();
                    }else{
                        return false;
                    }
                }
            }
            //now we have the rest of them to match

            while (!open_brack.empty() && !unlocked_brack.empty() && open_brack.top() < unlocked_brack.top()){
                open_brack.pop();
                unlocked_brack.pop();
            }
            
            return open_brack.empty();
    }
};