/**
 * @brief      This class describes a solution.
 * 26. 删除有序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        nums.resize(i + 1);
        return nums.size();
    }
};