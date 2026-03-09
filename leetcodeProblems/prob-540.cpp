#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // Boundary case: array of size 1
        if (high == 0) return nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;

            // We want 'mid' to always be even for a simple comparison.
            // If mid is odd, decrement it to make it even.
            if (mid % 2 == 1) {
                mid--;
            }

            // If the element at mid (even) matches the next element (odd),
            // the single element must be further to the right.
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } 
            // Otherwise, we are either at the single element or to the right of it.
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};