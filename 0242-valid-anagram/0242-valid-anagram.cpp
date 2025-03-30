class Solution {
public:
    bool isAnagram(string s, string t) {
        int frequencyTable[256]={0};
        for(int i =0; i<s.size();i++){
            frequencyTable[s[i]] ++;
        }

         for(int i =0; i<t.size();i++){
            frequencyTable[t[i]] --;
        }

         for(int i =0; i<256;i++){
            if(frequencyTable[i] != 0){
                return false ;
            };
        };

        return true;
    }
};