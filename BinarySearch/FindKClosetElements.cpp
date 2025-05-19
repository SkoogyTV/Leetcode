// Author: Sean Skaugen
// 658 find K closet Members: Medium
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> res;
        if (arr.empty() || k == 0)
            return {};
        if (arr.size() == k)
            return arr;

        // we need to find the closet number to x this will use binary search!
        int left = 0, right = arr.size() - 1, middle = 0, closest = 0;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (arr[middle] >= x)
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        left -= 1;
        right = left + 1;
        while (right - left - 1 < k)
        {
            if (left == -1)
            {
                right += 1;
            }
            else
            {
                if (right == arr.size() || abs(arr[left] - x) <= abs(arr[right] - x))
                {
                    left -= 1;
                }
                else
                {
                    right += 1;
                }
            }
        }
        cout << "Out of Loop" << endl;
        for (int i = left + 1; i < right; i++)
        {
            res.push_back(arr[i]);
        }

        return res;
    }
    
};
    int main()
    {
        
        Solution sol;
        
        vector<int> arr = {1, 1, 2, 3, 4, 5};
        vector<int> test = sol.findClosestElements(arr, 4, -1);
        
        if(test.empty()){
            cout << "I AM EMPTY FOOL\n"; 
        }
        for(int nums : test){
            cout << nums << "\n";
        }
        
        return 0;
    }