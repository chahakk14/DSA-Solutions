class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            int lefts = 0;
            int rights = 0;

            int left = i - 1;
            int right = i + 1;

            while (left >= 0) {
                lefts += nums[left];
                left--;
            }

            while (right < nums.size()) {
                rights += nums[right];
                right++;
            }

            ans.push_back(abs(lefts - rights));
        }

        return ans;
    }
};