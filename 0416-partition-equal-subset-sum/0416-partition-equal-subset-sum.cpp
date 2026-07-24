class Solution {
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>&dp) {
        if (target == 0)
            return true;

        // No elements left or target becomes negative
        if (index >= nums.size() || target < 0)
            return false;

        if (dp[index][target]!=-1)
            return dp[index][target];
            
        // Include
        bool include = solve(nums, index + 1, target - nums[index], dp);

        // Exclude 
        bool exclude = solve(nums, index + 1, target, dp);

        return dp[index][target]= include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;
        
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1, -1)) ;
        return solve(nums, 0, sum / 2, dp);
    }
};