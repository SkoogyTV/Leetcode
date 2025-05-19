#include<stack>
#include<string>
class Solution {
    public:
        bool isValid(std::string s) {
            if(s.size() < 2){return false;}
            std::stack<char> checker;
            for(int i = 0; i < s.size();i++){
                //if it is an opeining bracket then we push to stack
                //else we look to see if the stack is empty
                if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                    checker.push(s[i]);
                }else{
                    if(checker.empty()){return false;}
                    else{
                        char bracket = checker.top();
                        if(s[i] == ')' && bracket != '(' || s[i] == ']' && bracket != '[' || s[i] == '}' && bracket != '{'){
                            return false;
                        }
                        checker.pop();
                    }
                }
            }
            return checker.empty();
        }
    };

    //time complexity is O(n)
    //space complexity is also o(n)
