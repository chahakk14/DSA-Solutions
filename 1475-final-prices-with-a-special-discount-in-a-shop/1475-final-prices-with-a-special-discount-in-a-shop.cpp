class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> result = prices;
        stack<int> s; // will store indices

        for (int i = 0; i < prices.size(); i++) {
            while (!s.empty() && prices[i] <= prices[s.top()]) {
                int idx = s.top();
                s.pop();
                result[idx] = prices[idx] - prices[i];
            }
            s.push(i);
        }
        return result;
    }
};
