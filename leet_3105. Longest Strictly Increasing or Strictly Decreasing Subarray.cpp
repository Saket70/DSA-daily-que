class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int max_length = 1, inc_length = 1, dec_length = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc_length++;
                dec_length = 1;  // Reset decreasing length
            } 
            else if (nums[i] < nums[i - 1]) {
                dec_length++;
                inc_length = 1;  // Reset increasing length
            } 
            else {
                inc_length = 1;  
                dec_length = 1;  // Reset both if equal
            }
            max_length = max(max_length, max(inc_length, dec_length));
        }

        return max_length;
    }
};
