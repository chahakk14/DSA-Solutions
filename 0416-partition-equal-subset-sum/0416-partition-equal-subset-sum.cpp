class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int n= nums.size();
        int target = sum / 2;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1, 0)) ;

        for(int i=0; i<=n; i++){
            dp[i][0]= 1;
        }

        for(int index=n-1; index>=0; index--){
            for(int t= 0; t<=target; t++){
                bool include = false;

                if(t - nums[index] >=0)
                    include = dp [index + 1][t - nums[index]];

                bool exclude = dp [index + 1][t];

                dp[index][t]= include || exclude;
            }
        }
        return dp[0][target];
    }
};