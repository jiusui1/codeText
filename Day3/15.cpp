/**
 * @brief      
 * 15. 三数之和
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //排序
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            //如果每次遍历的第一个数大于0,直接退出
            if(nums.at(i) > 0){
                return result;
            }

            if(i > 0 and nums[i] == nums[i-1]){
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left and nums[right] == nums[right - 1])
                        right--;
                    while(right > left and nums[left] == nums[left + 1])
                        left++;

                    right--;
                    left++;
                }

            }

        }
        return result;
    }
};