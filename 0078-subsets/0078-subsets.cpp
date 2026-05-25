class Solution {
public:
    void subsetRecur(int i, vector<int>& arr, vector<vector<int>>& ans, vector<int>& subset) {
    
    // add subset at end of array
    if (i == arr.size()) {
        ans.push_back(subset);
        return;
    }
    
    // include the current value and 
    // recursively find all subsets
    subset.push_back(arr[i]);
    subsetRecur(i+1, arr, ans, subset);
    
    // exclude the current value and 
    // recursively find all subsets.
    subset.pop_back();
    subsetRecur(i+1, arr, ans, subset);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        subsetRecur(0, nums, ans, subset);
        return ans;
    }
};