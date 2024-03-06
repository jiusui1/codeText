/**
 * @brief      This class describes a solution.
 * 快乐数
 */
class Solution {
public:
	int getSum(int x){
		int sum = 0;
		while(x){
			sum += (x % 10) * (x % 10);
			x /= 10;
		}
		return sum;
	}

    bool isHappy(int n) {
    	unordered_set<int> set;
    	while(1){
    		int sum = getSum(n);
    		if(sum == 1){
    			return true;
    		}
    		if(set.find(sum) != set.end())
    			return false;
    		else
    			set.insert(sum);
    		n = sum;
    	}
    }
};