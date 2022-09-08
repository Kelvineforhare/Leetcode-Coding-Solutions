class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> mp;
        
        for(int i = 0; i < prerequisites.size();++i){
            if(prerequisites[i][1] == prerequisites[i][0]){
                return false;
            }
            
            vector<int> pre {prerequisites[i][1]};
            auto insert = mp.insert({prerequisites[i][0],pre});
            if(!insert.second){
                insert.first->second.push_back(prerequisites[i][1]);
            }
            
        }
    
        set<int> correct;
        for ( auto it = mp.begin(); it != mp.end(); ++it  ){
            set<int> visit;
            // std::cout << (it->first) << '\t';   
            // std::cout << std::endl;
            if(!canFin(mp,it->first,visit,correct)){
                return false;
            }
            correct.insert(it->first);
        }
        return true;
    }
    
    bool canFin(map<int,vector<int>>& mp,int course,set<int> visit,set<int> & noLoop){
        //printf("course: %d \n",course);
        auto in = visit.insert(course); 
        if(!in.second){
            return false; 
        }
        auto inf = noLoop.insert(course); 
        if(!inf.second){
            return true; 
        }
        auto find = mp.find(course);
        if(find == mp.end()){
            return true;
        }
        for(int i = 0; i < find->second.size();++i){
            if(!canFin(mp,find->second[i],visit,noLoop)){
                return false;
            }
        }
        return true;
    }
};