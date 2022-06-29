class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0){
            return true;
        }
        int sSize = 0;
        for(int i = 0;i < t.size();++i){
            if(s[sSize] == t[i]){
                if(sSize+1 == s.size()){
                    return true;
                }
                ++sSize;
            }
        }
        return false;
    }
};