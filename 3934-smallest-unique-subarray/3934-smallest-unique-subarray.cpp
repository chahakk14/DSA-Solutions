class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
       int n = nums.size();

        const long long BASE = 911382323;
        const long long MOD = 1e9 + 7;

        vector<long long> power(n + 1, 1);
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            power[i + 1] = (power[i] * BASE) % MOD;
            prefix[i + 1] =
                (prefix[i] * BASE + nums[i] + 1) % MOD;
        }

        auto getHash = [&](int l, int r) {
            long long hash =
                (prefix[r + 1] -
                 (prefix[l] * power[r - l + 1]) % MOD +
                 MOD) % MOD;

            return hash;
        };

        auto check = [&](int len) {

            unordered_map<long long, int> freq;

            for (int i = 0; i + len - 1 < n; i++) {
                freq[getHash(i, i + len - 1)]++;
            }

            for (auto &p : freq) {
                if (p.second == 1)
                    return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans; 
    }
};