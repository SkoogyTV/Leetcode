// Author: Sean Skaugen
#include <vector>

/*
class Solution
{
    public:
    int binary_search(std::vector<int>& nums, int front, int back, int target)
    {
        //Exhaust the Search Space
        if(front > back)
        {
            return -1;
        }

        //check to see nums middle
        int middle = (front + back) / 2;
        if(nums[middle] == target)
        {
            return middle;
        }
        if(nums[middle] > target)
        {
            return binary_search(nums, front, middle - 1, target);
        }

        return binary_search(nums, middle + 1, back, target);

    }

    int search(std::vector<int> &nums, int target)
    {
        return binary_search(nums, 0, nums.size()-1, target);
    }
};
*/
// iterative approach!
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int front = 0, back = nums.size() - 1, middle = 0;

        while (front <= back)
        {
            middle = (front + back) / 2;
            if (nums[middle] == target)
            {
                return middle;
            }else if (nums[middle] > target)
            {
                back = middle - 1;
            }
            else
            {
                front = middle + 1;
            }
        }
        return -1;
    }
};