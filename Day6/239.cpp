class Solution
{
public:
    int maxIndexDiff(queue<int> q)
    {
        int max = q.front();
        while (q.empty() == false)
        {
            max = max > q.front() ? max : q.front();
            q.pop();
        }
        return max;
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> q;
        vector<int> ans;
        int i = 0;
        for (i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }
        ans.push_back(maxIndexDiff(q));
        for (i = k; i < nums.size(); i++)
        {
            q.pop();
            q.push(nums[i]);
            ans.push_back(maxIndexDiff(q));
        }
        return ans;
    }
};