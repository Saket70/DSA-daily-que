class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while(s.find(part) != string::npos){
                // inside the loop means part exist in the string
                s.erase(s.find(part),part.length());
            }
            return s;
            
        }
    };