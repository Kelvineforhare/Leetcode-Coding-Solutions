class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        else if (x < 10){
            return true;
        }
        else if (x < 100 && x%11 == 0){
            return true;
        }
        std::string stringx = std::to_string(x);
       
        int i = 0;
        int j = stringx.length() - 1;
        for(;i < j;++i,--j){
            if(stringx[i] != stringx[j]){
                return false;
            }
        }
        return true;
    }
};