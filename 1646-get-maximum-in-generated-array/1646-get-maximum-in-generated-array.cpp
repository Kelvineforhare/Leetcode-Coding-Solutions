class Solution {
public:
    int getMaximumGenerated(int n) {
        int array[n+1];
        if(n>=0){
            array[0] = 0;
        }
         if(n>=1){
            array[1] = 1;
        }
        int i = 1;
        int index = 2;
        while(index <= n ){
            if(index%2 ==0){
                array[2*i] = array[i];
            }
            else{
                array[(2 * i)+ 1] = array[i] + array[i+1];
                ++i;
            }
            ++index;
        }
        int max = 0;
        for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
            if(array[i] > max){
                max = array[i];
            }
        }
        for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
            printf("%d\n",array[i]);
        }
        return max;
    }
    
 
};