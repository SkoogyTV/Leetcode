
#include <set>
#include <vector>

bool hasDuplicates(std::vector<int>& nums);
int main(){




    
    return 0;
}

bool hasDuplicates(std::vector<int>& nums){

    std::set<int> counter;

    for(auto num : nums){
        if(counter.find(num) != counter.end()){
            return true;
        }
        counter.insert(num);
    }

    return false;
}