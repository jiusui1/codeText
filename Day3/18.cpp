/**
 * @brief      This class describes a solution.
 * 18. 四数之和
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        //排序
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] > target and nums[j] >= 0)
                break;

            if (j > 0 and nums[j] == nums[j-1])
                continue;

            for (int i = j + 1; i < nums.size(); ++i)
            {
                if (nums[i] + nums[j] > target and nums[i] + nums[j] >= 0)
                    break;

                if(i > j + 1 and nums[i] == nums[i-1])
                    continue;
                int left = i + 1;
                int right = nums.size() - 1;

                while(left < right){
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else if((long)nums[i] + nums[j]+ nums[left] + nums[right] < target)
                        left++;
                    else{
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(right > left and nums[right] == nums[right - 1])
                            right--;
                        while(right > left and nums[left] == nums[left + 1])
                            left++;

                        right--;
                        left++;
                    }

                }
            }
        }
        
        return result;
    }
};