class Solution {
public:
    int swaps(vector<int>& nums){
        int n=nums.size();
        vector<bool>valid(n,false);
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());

        int swaps=0;

        for(int i=0;i<n;i++){
            int cyclesize=0;
            if(p[i].second==i || valid[i]) continue;
            int j=i;

            while( !valid[j]){
                valid[j]=true;
                j=p[j].second;
                cyclesize++;
            }

            swaps+=cyclesize-1;

        }
        return swaps;
    }
    int minSwaps(vector<int>& nums) {
        set<pair<int,int>>set;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            int temp=nums[i];
            while(temp>0){
                sum+=temp%10;
                temp=temp/10;
            }
            set.insert({sum,nums[i]});
        }
        vector<int>sorted;
        for(auto it:set){
            sorted.push_back(it.second);
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[sorted[i]] = i;
        }

        for(int i=0;i<n;i++){
            nums[i]=mpp[nums[i]];
        }

        return swaps(nums);  
    }
};