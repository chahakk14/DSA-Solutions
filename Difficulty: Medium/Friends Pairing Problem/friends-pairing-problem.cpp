class Solution {
  public:
    int countFriendsPairings(int n) {
        // f(n−1)+(n−1)*f(n−2)
        if(n==1) return 1;
        int prev2=1; //f(0)
        int prev1=1; //f(1)
        int curr;
        for(int i=2; i<=n; i++){
            curr= prev1+(i-1)*prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
