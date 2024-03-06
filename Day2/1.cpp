class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);

            if (iter != map.end())
            {
                return{iter->second , i};
            }
            
            //如果没找到,就加入到map里面去
            map.insert(pair<int,int>(nums[i] , i));
        }
        return{};
    }
};