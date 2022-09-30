class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1 = 0;
        int p2 = 1;
        
        map<char,int> map;
        if(s.size() == 0)return 0;
        int max = 1;
        map.insert({s[0],0});
        while(p2 < s.size()){
            
            auto insert = map.insert({s[p2],p2});
            if(!insert.second){
                if(insert.first->second+1 > p1){
                    p1 = insert.first->second+1;
                }
                insert.first->second = p2;
                //printf("p1: %d p2: %d \n",p1,p2);
            }
            
            if((p2 - p1)+1 > max){
                max = (p2 - p1)+1;
            }
            ++p2;
            
            // for(int i = p1; i < p2;++i){
            //     printf("%c \n",s[i]);
            // }
            //printf("\n");
        }
        
        return max;
    }
};