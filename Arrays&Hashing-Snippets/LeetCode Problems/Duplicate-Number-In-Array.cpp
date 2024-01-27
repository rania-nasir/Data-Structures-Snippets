//https://leetcode.com/problems/contains-duplicate/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //// Method 1
        //// Time Complexity: O(n^2) due to hash collisions
        //for (int i = 0; i < nums.size(); i++) {
        //    for (int j = i + 1; j < nums.size(); j++) {
        //        if (nums[i] == nums[j]) {
        //            return true;
        //        }
        //    }
        //}
        //return false;

        // Method 2 
        // Time Complexity : O(n) (Average Case)
        // But it may have worst case TC of O(n^2) due to hash collisions.
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;  // Duplicate found
            }
            seen.insert(num);
        }
        return false;  // No duplicates found
    }
};

void printArray(vector<int>& nums) {
    cout << "\n[ ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    Solution solution;

    int arr[8];

    cout << "\nEnter array Elements : \n";
    for (int i = 0; i < 8; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    vector<int> nums(arr, arr + 8);

    printArray(nums);

    if (solution.containsDuplicate(nums)) {
        cout << "\nDuplicate Exists";
    }
    else {
        cout << "\nNo Duplicates";
    }

    return 0;
}