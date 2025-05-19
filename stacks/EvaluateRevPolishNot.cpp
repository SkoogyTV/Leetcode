#include <vector>
#include <string>
#include <stack>
class Solution {
    public:
        int evalRPN(std::vector<std::string>& tokens) {
            std::stack<int> holder;
            int i = 0;

            for(int i = 0; i < tokens.size(); i++){
                if(tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/"){
                    if(holder.size() >= 2){
                        int integer1 = holder.top();
                        holder.pop();
                        int integer2 = holder.top();
                        holder.pop();
                        if(tokens[i] == "-"){
                            int sub = integer2 - integer1;
                            holder.push(sub);
                        }
                        else if(tokens[i] == "+"){
                            int add = integer2 + integer1;
                            holder.push(add);
                        }else if(tokens[i] == "*"){
                            int mult = integer2 * integer1;
                            holder.push(mult);
                        }else{
                            int div = integer2 / integer1;
                            holder.push(div);
                        }
                    }
                }else{
                    holder.push(std::stoi(tokens[i]));
                }
            }
            return holder.top();
        }
    };