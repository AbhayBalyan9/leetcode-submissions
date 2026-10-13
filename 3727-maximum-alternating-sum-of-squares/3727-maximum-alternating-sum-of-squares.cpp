class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        
        for(int i=0;i<n;i++){
            int dig=abs(nums[i]);
            nums[i]=dig;
        }

        sort(nums.begin(),nums.end());

        int max=(n+1)/2;

        for(int i=n-1;i>=0;i--){
            if(max>0){
                max--;
                ans+=nums[i]*nums[i];
            }else{
                ans-=nums[i]*nums[i];
            }
        }
        return ans;

    }
};