class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);

        const int MOD = 1e9 + 7;

        prev[0]=1;
        for(int dice=1; dice<=n; dice++){
            for(int x=1; x<=target; x++){
                int ans=0;
                for(int i=1; i<=k; i++){
                    if(x-i>=0)
                        ans= (ans+ prev[x-i]) % MOD;
                }
                curr[x]=ans;
            }
            prev=curr;
        }
        return prev[target];
    }
};