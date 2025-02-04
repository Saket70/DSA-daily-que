class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, currSum = nums[0];  // Start with the first element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];  // Extend the subarray
            } else {
                maxSum = max(maxSum, currSum);  // Update max sum if needed
                currSum = nums[i];  // Start a new subarray
            }
        }
        return max(maxSum, currSum);  // Ensure the last subarray is considered
    }
};
