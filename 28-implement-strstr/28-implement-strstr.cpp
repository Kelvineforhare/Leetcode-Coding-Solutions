class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        if(needle.size() > haystack.size()){
            return -1;
        }
        for(int i = 0 ; i < haystack.size();++i){
            bool found = true;
            if(i + needle.size() > haystack.size()){
                return -1;
            }
            for(int j = 0; j < needle.size();++j){
                if(haystack[i + j] != needle[j]){
                    found = false;
                    break;
                }
            }  
            if(found){
                return i;
            }
        }
        return -1;
    }
};