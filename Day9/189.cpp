// class Solution { //³¬Ê±ÁË
//    public:
//     void rotate(vector<int> &nums, int k) {
//         for (int i = 0; i < k; i++) {
//             int temp = nums[nums.size() - 1];
//             for (int j = nums.size() - 1; j > 0; j--) {
//                 nums[j] = nums[j - 1];
//             }
//             nums[0] = temp;
//         }
//     }
// };

class Solution {
   public:
    void rotate(vector<int> &nums, int k) {  // 1,2,3,4,5,6,7  k = 3;
        k = k % nums.size();
        reverse(nums.begin(), nums.end());        // 7,6,5,4,3,2,1
        reverse(nums.begin(), nums.begin() + k);  // 5,6,7,4,3,2,1
        reverse(nums.begin() + k, nums.end());    // 5,6,7,1,2,3,4
    }
};