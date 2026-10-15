class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>set;
        int i=0;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            set.clear();
            for(int j=i;j<n;j++){
                set.insert(nums[j]);
                int k=set.size();
                ans+=k*k;
            }
        }
        return ans;
    }
};