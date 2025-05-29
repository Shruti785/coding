class Solution {
public:

void solve(int index,int sum,vector<int>toppingCosts,int target,int &diff1,int &value1){
    // cout<<sum<<endl;
     
     

     if(abs(target-sum) <diff1 ){
        diff1 = abs(target-sum);
        value1 = sum;
     }
     else if(abs(target-sum) == diff1){
        value1 =min(value1,sum);
     }
 if(index>=toppingCosts.size()){
        return ;
     }


     for(int i=1;i<=2;i++){
           solve(index+1,sum+toppingCosts[index]*i , toppingCosts,target,diff1,value1);
     }
     solve(index+1,sum,toppingCosts,target,diff1,value1);


}

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        int diff = INT_MAX;
        int value = -1;
        for(int i=0;i<baseCosts.size();i++){
            int sum = baseCosts[i];
            int diff1 = INT_MAX;
            int value1 = INT_MAX;
            solve(0,sum,toppingCosts,target,diff1,value1);
         
            if(diff1<diff){
                diff = diff1;
                value = value1;
            }
            if(diff == diff1){
                value = min(value,value1);
            }

        }
        return value;
    }
};