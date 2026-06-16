class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i = 0; i<s.size();i++){
            if(isalpha(s[i])){
                result.push_back(s[i]);
            }else if(s[i] == '*'){
                if(result.size() >= 1){
                    result.pop_back();
                }
            }else if(s[i] == '#'){
                result = result + result;
            }else{
                reverse(result.begin(),result.end());
            }
        }

        return result;
    }
};