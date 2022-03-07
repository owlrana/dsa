// https://leetcode.com/problems/first-missing-positive/

// to find out the first positive number missing from the array
// Time Constraint: O(n)
// Space Constraint: O(1)

#include<everything>
using namespace std;

int firstMissingPositive(vector<int>& nums) {

    // making all negative numbers to 0
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] < 0) {
            nums[i] = 0;
        }
    }
    
    // setting the numbers present inside the array present (index of that number => [num-1] becomes positive)
    for (int i = 0; i < nums.size(); i ++) {

        // if the abs value of this number lies between 1 and the length of nums array
        if (abs(nums[i]) >= 1 and abs(nums[i]) <= nums.size()) {

            // checking if the number is not already 0. 
            if (nums[abs(nums[i]) - 1] != 0) {
                // convert the number into its negative form if not 0
                nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
            } else {
                // In the case it is 0, we make it negative of INT_MAX
                nums[abs(nums[i]) - 1] = -1 * INT_MAX;
            }
        }
    }
    
    int number = 0;
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] >= 0) {
            return i + 1;
        }
    }
    
    return nums.size() + 1;
}

int main()
{
    vector<int> nums = {1, 2, 0};

    int answer = firstMissingPositive(nums);

    cout << answer;

    return 0;
}