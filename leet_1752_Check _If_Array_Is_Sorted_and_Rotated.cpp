class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0; // Count the number of "drops"
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1; // Valid if there is at most one drop
    }
};
