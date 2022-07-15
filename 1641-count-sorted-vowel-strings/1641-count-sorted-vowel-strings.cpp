class Solution {
public:
    int countVowelStrings(int n) {
        return solve(n,0,5,0);
    }
    //letter a == 5 e == 4 ...
    int solve(int n, int i, int letter,int total){
        if(n == 1){
            return 5;
        }
        if(i == n-1){
            total+=letter;
            return total;
        }
        for(int j = letter; j > 0;--j){
            total = solve(n,i+1,j,total);
        }
        
        return total;
    }
};