/**
 * @brief      This class describes a solution.
 * 80. 删除有序数组中的重复项Ⅱ
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                while(i + 1 < nums.size() and nums[i + 1] == nums[i])
                {
                    nums.erase(nums.begin() + i + 1);
                }
            }
        }
        return nums.size();
    }
};