class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        vector<int> prev(x+1,0);
        vector<int> curr(x+1,0);
        
        prev[0]=1;
        for(int dice=1; dice<=n; dice++){
            for(int target=1; target<=x; target++){
                int ans=0;
                for(int i=1; i<=m; i++){
                    if(target-i>=0) 
                        ans= ans+prev[target-i];
                }
                curr[target]=ans;
            }
            prev=curr;
        }
        return prev[x];
    }
};