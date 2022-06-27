class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = s.size() - 1;
        for(int i = s.size() - 1; i >= 0  ;--i){
            if(s[i] == ' '){
                --start;
            }
            else{
                break;
            }
        }
        for(int i = start; i >= 0  ;--i){
            if(s[i] == ' '){
                return start - i;
            }
        }
        return start + 1;
    }
};