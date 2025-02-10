class Solution {
    public:
        string clearDigits(string s) {
            string res;
    
    /*  INSTEAD OF THE BELOW LOOP WE CAN USE THIS ALSO ITS EASY
            for (char c : s) {
        // Process each character 'c'
    }
    */
    
    
            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                if(c>='0' and c<='9') {
                     res.pop_back();
                } 
                else {
                     res.push_back(c);
                }                  
            }
            return res;
        }
    };