class Solution {
public:
    int mod=1000000007;
    vector<vector<int>>PT;
    int solve(vector<int>& nums){
       
        int n=nums.size();
        if(n<3) return 1;

        vector<int>la;
        vector<int>ra;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root){
                la.push_back(nums[i]);
            }else{
                ra.push_back(nums[i]);
            }
        }
        int left=solve(la) % mod;
        int right=solve(ra) % mod;

        return (((1LL *left * right)%mod) * PT[n-1][la.size()]) % mod;


    }
    int numOfWays(vector<int>& nums) {

        int n=nums.size();

        PT.resize(n+1);

        for(int i=0;i<=n;i++){
            PT[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                PT[i][j]=(PT[i-1][j-1] + PT[i-1][j]) % mod;
            }
        }
        
        return (solve(nums)-1)%mod;

    }
};