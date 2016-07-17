class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0, i = 0;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it) {
            if(*it == 0)
                zero++;
            else if(*it == 1)
                one++;
            else
                two++;
        }
        while(i < zero) {
            nums[i] = 0;
            i++;
        }
        int k = i;
        while(i-k < one) {
            nums[i] = 1;
            i++;
        }
        k = i;
        while(i-k < two) {
            nums[i] = 2;
            i++;
        }
    }
};
