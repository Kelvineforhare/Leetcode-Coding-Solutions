class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char,int> map;
        for(int i = 0; i < s.size();++i){
            auto insert = map.insert({s[i],1});
            if(!insert.second){
                insert.first->second = insert.first->second + 1;
            }
        }
        for(int i =0; i < t.size();++i){
            auto insert = map.insert({t[i],0});
            if(!insert.second){
                insert.first->second = insert.first->second - 1;
            }
            else{
                return false;
            }
        }
        for(auto it = map.begin();it!=map.end();++it){
            //cout << it->first << " " << it->second << " \n";
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};