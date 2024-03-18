#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());  // 将数组排序
        return nums[nums.size() / 2];    // 返回中间的数，因为中间的数出现的次数大于n/2
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vec = {2, 1, 3, 3, 1, 3, 1};
    int ret = s.majorityElement(vec);
    cout << ret << endl;
    return 0;
}
