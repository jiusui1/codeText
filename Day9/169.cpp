#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());  // ����������
        return nums[nums.size() / 2];    // �����м��������Ϊ�м�������ֵĴ�������n/2
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vec = {2, 1, 3, 3, 1, 3, 1};
    int ret = s.majorityElement(vec);
    cout << ret << endl;
    return 0;
}