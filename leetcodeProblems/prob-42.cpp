#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } 
            else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Test Case 1 Output: " << solution.trap(height1) << " (Expected: 6)" << endl;

    // Test case 2
    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Test Case 2 Output: " << solution.trap(height2) << " (Expected: 9)" << endl;

    return 0;
}
