 /*
 You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    
    int totalc(int i,int j){
        int mval = min(i,j);
        if(mval == 0){return 1;}
        else{
            double result = 1;//waring!! int type will overflow!!
            double div = 1;
            int sval = i+j;
            for(int t =0;t<mval;t++)
            {
                result = result * sval;
                sval--;
            }
            for(int k = 2;k<=mval;k++)
            {
                div = div * k;
            }
            return round(result/div);
        }
    }
    
    int climbStairs(int n) {
        int cn = 0;
        //i is the number of 2step.
        for(int i = 0;i<=n/2;i++){
            int j = n-2*i;
        //j is the number of 1step.
            cn = cn+ totalc(i,j);
        }
        return cn;
        
    }
};