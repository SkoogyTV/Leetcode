#include <string>
#include <iostream>
#include <vector>

std::string encode(std::vector<std::string>& strs){
    std::string encoded = "";
    
    for(int i = 0; i < strs.size(); i++){
       int str_size = strs[i].size();
       encoded+= std::to_string(str_size) + "#" + strs[i];

    }
    return encoded;
}

std::vector<std::string> decode(std::string s){
    std::vector<std::string> vec_strs;
    //so now to decode we need to find the integer eat the delimiter and then move that many positions and add that to a vector
    
    int i = 0;
    while (i < s.size())
    {
        //we need to get the integer
        size_t hash = s.find('#',i);
        int string_size = std::stoi(s.substr(i, hash-i));
        i = hash + 1;
        
        std::string str_builder = s.substr(i,string_size);
        vec_strs.push_back(str_builder);
        i += string_size;
    
    }
    
    return vec_strs;
}

int main(){

    std::vector<std::string> vec_strs = {"Sean", "Chaney", "Lebron", "James"};

   std::string encoded_str = encode(vec_strs);

   std::vector<std::string> result = decode(encoded_str);

   for(const auto& str : result){
    std::cout << str << "\n";
   }
   

   return 0;
}