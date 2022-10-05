class Solution {
public:
    
    string longestPalindrome(string s) {
        if(s.size() == 0){
            return "";
        }
        string ans = s.substr(0,1);
        for(int i = 1; i < s.size();++i){
            int p1 = i -1,p2 = i + 1;
            while((p1 >=0 && p2 < s.size()) && s[p2] == s[p1]){
                string temp = s.substr(p1,(p2-p1)+1);
                if(temp.size() > ans.size()){
                    ans = temp;
                }
                //cout << temp << " p1: " << p1<< " p2: " << p2 << "\n";
                --p1;
                ++p2;
                
            }
            if(ans.size() == s.size()){
                return ans;
            }
            p1 = i-1,p2=i;
            while((p1 >=0 && p2 < s.size()) && s[p2] == s[p1]){
                string temp = s.substr(p1,(p2-p1)+1);
                if(temp.size() > ans.size()){
                    ans = temp;
                }
                //cout << temp << " p1: " << p1<< " p2: " << p2 << "\n";
                --p1;
                ++p2;
            }
            if(ans.size() == s.size()){
                return ans;
            }
            //cout << i << "\n";
        }
        return ans;
    }
    
    // bool isPalindrome(string s){
    //     for(int i =0 , j = s.size()-1;i <= j;++i,--j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};