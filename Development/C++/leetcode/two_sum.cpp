#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> inds;
        inds.push_back(0);
        inds.push_back(0);
        bool foundOne = false;
        bool matchFound = false;

        int i = 0;
        int j = 0;
        while (!matchFound) {
            while (!foundOne) {
                if (abs(target - nums[i]) >= 0){
                    inds[0] = i;
                    foundOne = true;
                    j = i + 1;
                }
                i++;
            }
            if (nums[inds[0]] + nums[j] == target) {
                inds[1] = j;
                matchFound = true;
            } else {
                j++;
                if (j >= nums.size()) {
                    foundOne = false;
                }
            }
        }

        return inds;
    }
};

int main() {
    Solution s;
    static const int arr[] = {-2,-7,11,15};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]));
    int target = -9;

    vector<int> solution = s.twoSum(nums, target);
    cout << "[";
    cout << solution[0] << ", ";
    cout << solution[1] << "]" << endl;

    return 0;
}
