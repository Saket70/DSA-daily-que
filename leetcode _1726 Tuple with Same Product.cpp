#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to calculate combinations (n choose 2)
    int countPairs(int n) {
        return (n * (n - 1)) / 2;  // Formula: nC2 = n! / (2!(n-2)!)
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount; // Stores product frequencies
        
        int n = nums.size();
        
        // Count occurrences of each product
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;  // Increase count of this product
            }
        }
        
        int totalTuples = 0;
        
        // Calculate valid tuples
        for (auto it : productCount) {
            int frequency = it.second;
            if (frequency > 1) { // Only consider products that appear more than once
                totalTuples += 8 * countPairs(frequency); // Multiply by 8 for all permutations
            }
        }
        
        return totalTuples;
    }
};

// Test the function
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4, 6};
    cout << sol.tupleSameProduct(nums) << endl; // Output: 8
    return 0;
}
