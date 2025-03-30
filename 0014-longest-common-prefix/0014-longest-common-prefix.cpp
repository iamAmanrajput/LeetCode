class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans = "";
        for(int i =0;i<strs[0].size();i++){
            if(strs[0][i] != strs[strs.size() -1][i]){
                return ans;
            }else{
                ans.push_back(strs[0][i]);
            }
        }

        return ans;
    }
};