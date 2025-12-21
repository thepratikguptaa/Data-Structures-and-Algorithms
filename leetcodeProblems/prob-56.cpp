class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 1. Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (auto interval : intervals) {
            // If the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, append it.
            if (merged.empty() || interval[0] > merged.back()[1]) {
                merged.push_back(interval);
            }
            // Otherwise, there is overlap, so we merge the current and previous
            // intervals by updating the end time of the previous interval.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};