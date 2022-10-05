class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> ana;
        for(int i = 0; i < strs.size();++i){
            map<char,int> map;
            for(int j = 0; j < strs[i].size(); ++j){
                auto insert = map.insert({strs[i][j],1});
                if(!insert.second){
                    insert.first->second = insert.first->second + 1;
                }
            }
            vector<string> temp;
            temp.push_back(strs[i]);
            auto insert = ana.insert({map,temp});
            if(!insert.second){
                insert.first->second.push_back(strs[i]);
            }
        }
        vector<vector<string>> ret;
        for(auto it = ana.begin();it != ana.end();++it){
            ret.push_back(it->second);
        }
        return ret;
    }
};