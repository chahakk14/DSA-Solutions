class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int p1= nums[n-1]*nums[n-2]*nums[n-3];
        int p2 = nums[0] * nums[1] * nums[n - 1];
        int ans= max(p1,p2);
        return ans;
    }
};