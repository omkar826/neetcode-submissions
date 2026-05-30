class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                return true;
                break;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};