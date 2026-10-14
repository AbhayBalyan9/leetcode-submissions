class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        double n=num;
        double s=sum;
        double check=s/n;
        string ans="";
        if(check>9){
            return ans;
        }
        while(num>0){
            int dig;
            if(sum>9){
                dig=9;
                sum-=dig;
            }else{
                dig=sum;
                sum-=dig;
            }
            char c='0'+dig;
            ans.push_back(c);
            num--;
        }
        return ans;
    
    }
};