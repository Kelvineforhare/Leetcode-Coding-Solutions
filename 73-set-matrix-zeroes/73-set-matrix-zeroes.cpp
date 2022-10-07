class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> change;
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0; j < matrix[i].size();++j){
                
                if(matrix[i][j] == 0){
                    //cout << i << " " << j << "\n";
                    for(int x = 0; x < matrix.size();++x){
                        change.push_back({x,j});
                    }
                     for(int y = 0; y < matrix[i].size();++y){
                         change.push_back({i,y});
                    }
                }
            }
        }
        for(int i = 0; i < change.size();++i){
            matrix[change[i].first][change[i].second] = 0;
        }
    }
};

// [0,1,2,0]
// [3,4,5,2]
// [1,3,1,5]

// [0,0,0,0]
// [0,4,5,0]
// [0,3,1,0]

// [0,0,0,0]
// [0,4,5,2]
// [0,3,1,5]