/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &arr, int target, int low, int high, bool ascending) {

        while (low <= high) {

            int mid = low + (high - low) / 2;
            int val = arr.get(mid);

            if (val == target)
                return mid;

            if (ascending) {

                if (target < val)
                    high = mid - 1;
                else
                    low = mid + 1;

            } else {

                if (target < val)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int low = 0;
        int high = arr.length() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (arr.get(mid) < arr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        int peak = low;

        int left = binarySearch(arr, target, 0, peak, true);

        if (left != -1) return left;

        return binarySearch(arr, target, peak + 1, arr.length() - 1, false);
    }
};