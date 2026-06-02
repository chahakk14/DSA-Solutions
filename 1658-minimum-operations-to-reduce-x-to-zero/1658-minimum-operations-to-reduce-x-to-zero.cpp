class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];

        int remSum = sum - x;

        if (remSum < 0) return -1;
        if (remSum == 0) return nums.size();

        int operations = INT_MAX;
        int windowSum = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            windowSum += nums[right];

            while (left <= right && windowSum > remSum) {
                windowSum -= nums[left];
                left++;                    
            }

            if (windowSum == remSum) {
                int len = right - left + 1;
                operations = min(operations,(int)nums.size() - len);
            }
            right++;
        }

        return (operations == INT_MAX) ? -1 : operations;
    }
};