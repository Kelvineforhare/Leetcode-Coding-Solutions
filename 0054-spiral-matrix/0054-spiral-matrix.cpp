class Solution {
public:
    set<pair<int,int>> visited;
    vector<int> ret;
    vector<vector<int>> mat;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        mat = matrix;
        int i = 0,j = 0;
        if(matrix.size() == 0){
            vector<int> arr{};
            return arr;
        }
        int mn = matrix.size() * matrix[0].size();
        while(visited.size() < mn){
            goAcross(i,j,true);
            //cout << i << " " << j << "\n";
            ++i;
            goVertical(i,j,true);
            //cout << i << " " << j << "\n";
            --j;
            goAcross(i,j,false);
            //cout << i << " " << j << "\n";
            --i;
            goVertical(i,j,false);
            //cout << i << " " << j << "\n";
            ++j;
        }
        return ret;
    }
    
    void goAcross(int & i, int & j,bool right){
        while(j < mat[0].size() && j >= 0){
            auto insert = visited.insert({i,j});
            if(!insert.second){
                if(right){--j;}
                else{++j;}
                return;
            }
            ret.push_back(mat[i][j]);
            if(right){++j;}
            else{--j;}
        }
        if(right){--j;}
        else{++j;}
    }
    
    void goVertical(int & i,int & j,bool down){
        while(i < mat.size() && i >=0){
            //cout << i << " " << j << "\n";
            auto insert = visited.insert({i,j});
            if(!insert.second){
                if(down){--i;}
                else{++i;}
                return;
            }
            ret.push_back(mat[i][j]);
            if(down){++i;}
            else{--i;}
        }
        if(down){--i;}
        else{++i;}
    }
};