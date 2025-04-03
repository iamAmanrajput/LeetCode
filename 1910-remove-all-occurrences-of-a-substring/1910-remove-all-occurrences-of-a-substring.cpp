class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);

        while (pos != string::npos) { // Keep removing while part exists
             s.erase(pos, part.length());
             pos = s.find(part);
           
        }
        
        return s; // Return the modified string
    }
};
