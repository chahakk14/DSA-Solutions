class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> result;

        for (int i : nums) {
            if (result.size() < k || result[result.size() - k] != i) {
            result.push_back(i);
            }
        }

    return result;
    }
};