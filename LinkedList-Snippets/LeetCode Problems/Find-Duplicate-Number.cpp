//https://leetcode.com/problems/find-the-duplicate-number/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0, fast = 0;

        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while (1) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }

        return -1;
    }
};

int main() {

    Solution solution;

    vector<int> nums = { 3, 1, 3, 4, 2 };

    cout << "Duplicate in nums: ";
    cout << solution.findDuplicate(nums) << endl;

    return 0;
}
