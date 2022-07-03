class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        
        long double factIndex = fact(rowIndex);
       printf("row: %Lf\n",factIndex);
        for(int i = 0; i <= rowIndex;++i){

            long double div = fact(i) * fact(rowIndex-i);

            long double ans = (factIndex/div) + 0.5;

            printf("%Lf\n",div);
            row.push_back(ans);
        }
        // printf("29!: %LF\n",fact(29)/ (fact(2) * fact(27)));
        // int t = (fact(29)/ (fact(2) * fact(27))) + 0.5;
        // printf("t: %d\n",t);
        return row;
    }
    
      long double fact(int n){
        long double factorial = 1;
        for(int i = 1; i <= n; ++i) {
            
            factorial *= i;
        }
        return factorial;
    }
};