class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int s = 0, e = nums.size() - 1;

        // first occurrence
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= target) e = mid - 1;
            else s = mid + 1;

            if (nums[mid] == target) first = mid;
        }

        s = 0, e = nums.size() - 1;

        // last occurrence
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] <= target) s = mid + 1;
            else e = mid - 1;

            if (nums[mid] == target) last = mid;
        }

        return {first, last};
    }
};