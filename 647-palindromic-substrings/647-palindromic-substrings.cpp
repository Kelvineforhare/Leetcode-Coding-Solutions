class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        if(s.size() > 0){
            ++ans;
            //cout << s[0] << "\n";
        }
        for(int i = 1 ; i < s.size();++i){
            //cout << s[i] << "\n";
            ++ans;
            int p1 = i - 1;
            int p2 = i + 1;
            while(p1>=0 && p2 < s.size() && s[p1] == s[p2]){
                //cout << s.substr(p1,p2-p1+1) << "\n";
                ++ans;
                --p1;
                ++p2;
            }
            
            p1 = i - 1;
            p2 = i;
            while(p1>=0 && p2 < s.size() && s[p1] == s[p2]){
                
                //cout << s.substr(p1,p2-p1+1) << "\n";
                ++ans;
                --p1;
                ++p2;
                
            }
        }
        return ans;
    }
};