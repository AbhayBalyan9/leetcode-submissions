class Solution {
public:
    int mod=1000000007;
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>count(32,0);
        for(int i=0;i<n;i++){
            for(int b=0;b<32;b++){
                if(nums[i]&(1<<b)){
                    count[b]++;
                }
            }
        }

        int res=0;
        while(k>0){
            int temp=0;
            for(int b=0;b<32;b++){
                if(count[b]>0){
                    count[b]--;
                    temp=(temp|(1<<b));
                }
            }
            res=(res+(1LL*temp*temp)%mod)%mod;
            k--;
        }
        
        return res;
    }
};