class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> res(size, 0);  // Result sequence initialized with 0
        vector<bool> used(n + 1, false);  // Track used numbers
        backtrack(res, used, n, 0);
        return res;
    }

private:
    bool backtrack(vector<int>& res, vector<bool>& used, int n, int index) {
        int size = res.size();

        // If all positions are filled, return true
        if (index == size) return true;

        // If position is already filled, move to the next
        if (res[index] != 0) return backtrack(res, used, n, index + 1);

        // Try placing numbers from n to 1 (for lexicographically largest order)
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;

            // If num == 1, it occupies only one position
            if (num == 1) {
                res[index] = 1;
                used[1] = true;
                if (backtrack(res, used, n, index + 1)) return true;
                res[index] = 0;
                used[1] = false;
            }
            // Otherwise, num should be placed at index and (index + num) positions
            else if (index + num < size && res[index + num] == 0) {
                res[index] = res[index + num] = num;
                used[num] = true;

                if (backtrack(res, used, n, index + 1)) return true;

                // Backtrack
                res[index] = res[index + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }
};