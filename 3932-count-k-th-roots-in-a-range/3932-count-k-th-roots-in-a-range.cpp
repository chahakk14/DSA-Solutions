class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int right = pow(r, 1.0 / k)+1e-9;
        int left = pow(l, 1.0 / k)-1e-9;

        while (pow(left, k) < l) {
            left++;
        }
        while (pow(right, k) > r) {
            right--;
        }
        return max(0, right - left + 1);
    }
};