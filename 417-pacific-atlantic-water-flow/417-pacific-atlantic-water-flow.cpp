class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ret;
        set<pair<int,int>> atlaCache; 
        set<pair<int,int>> pacCache;
        for(int i = 0; i < heights.size();++i){
            for(int j = 0;j < heights[i].size();++j){
                set<pair<int,int>> visited;
                set<pair<int,int>> visited2;
                printf("i: %d , j: %d\n",i,j);
                if(canReachAtlantic(i,j,heights,heights[i][j],atlaCache,visited) && canReachPacific(i,j,heights,heights[i][j],pacCache,visited2)){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
    
    bool canReachPacific(int r,int c,vector<vector<int>>& heights,int size,set <pair<int,int>>& pacCache,set<pair<int,int>>& visited){
        //printf("r: %d , c: %d , size: %d current: %d \n",r,c,size,heights[r][c]);
        // if(pacCache.find({r,c}) != pacCache.end()){
        //     return true;
        // }
        auto in = visited.insert({r,c});
        if(!in.second){
            return false;
        }
        if(r-1 < 0 || c - 1 < 0){
            pacCache.insert({r,c});
            //printf("true\n");
            return true;
        }
        
        if(r<heights.size()-1 && heights[r+1][c] <= heights[r][c] && canReachPacific(r+1,c,heights,size,pacCache,visited)){
            pacCache.insert({r,c});
            return true;
        }
        if(c<heights[r].size()-1 && heights[r][c+1] <= heights[r][c] && canReachPacific(r,c+1,heights,size,pacCache,visited)){
            pacCache.insert({r,c});
            return true;
        }
        
        if(r>0 && heights[r-1][c] <= heights[r][c] && canReachPacific(r-1,c,heights,size,pacCache,visited)){
            pacCache.insert({r,c});
            return true;
        }
        
        if(c>0 && heights[r][c-1] <= heights[r][c] && canReachPacific(r,c-1,heights,size,pacCache,visited)){
            pacCache.insert({r,c});
            return true;
        }
        //printf("false\n");
        return false;
    }
    bool canReachAtlantic(int r,int c,vector<vector<int>>& heights,int size,set <pair<int,int>>& atlaCache,set<pair<int,int>>& visited){ // remove size
        //printf("r: %d , c: %d , size: %d current: %d \n",r,c,size,heights[r][c]);
        // if(atlaCache.find({r,c}) != atlaCache.end()){
        //     return true;
        // }
        auto in = visited.insert({r,c});
        if(!in.second){
            return false;
        }
        if(r+1 > heights.size()-1 || c + 1 > heights[r].size()-1){
            //printf("true!!!\n");
            atlaCache.insert({r,c});
            return true;
        }
        if(r<heights.size()-1 && heights[r+1][c] <= heights[r][c] && canReachAtlantic(r+1,c,heights,size,atlaCache,visited)){
            atlaCache.insert({r,c});
            return true;
        }
        if(c<heights[r].size()-1 && heights[r][c+1] <= heights[r][c] && canReachAtlantic(r,c+1,heights,size,atlaCache,visited)){
            atlaCache.insert({r,c});
            return true;
        }
        if(r>0 && heights[r-1][c] <= heights[r][c] && canReachAtlantic(r-1,c,heights,size,atlaCache,visited)){
            atlaCache.insert({r,c});
            return true;
        }
        if(c>0 && heights[r][c-1] <= heights[r][c] && canReachAtlantic(r,c-1,heights,size,atlaCache,visited)){
            atlaCache.insert({r,c});
            return true;
        }
        //printf("false\n");
        return false;
    }
};