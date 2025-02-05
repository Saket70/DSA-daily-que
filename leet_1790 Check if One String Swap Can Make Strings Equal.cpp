class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        int m = s1.size();
        int missmatches = 0;
        vector<char> mismatch;
        int pos = 0;

        while (pos < m) {
            if (s1[pos] != s2[pos]) {
                mismatch.push_back(s1[pos]);
                mismatch.push_back(s2[pos]);
                missmatches++;
            }
            if (missmatches > 2) {
                return false;
            }
            pos++;
        }

    
        if (mismatch.size() == 4) {
            return (mismatch[0] == mismatch[3] && mismatch[1] == mismatch[2]);
        }

        return false;  // Edge case where only one mismatch exists
    }
};
