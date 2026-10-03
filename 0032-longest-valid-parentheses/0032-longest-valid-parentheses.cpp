class Solution {
public:
    int longestValidParentheses(string s) {

        // 2 pinters

        // left to right
        int n = s.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        int count = 0;
        while (r < n) {

            if (s[r] == '(') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                int len = r - l + 1;
                ans = max(ans, len);
            }
            if (count < 0) { // reset
                
                l = r+1;
                count = 0;
        
            }
            r++;
        }
    

    // right to left

    int count2 = 0;
    int l2 = n - 1;

    for(int r2 = n - 1; r2 >= 0; r2--) {

        if (s[r2] == ')') {
            count2++;
        } else {
            count2--;
        }

        if (count2 < 0) {
            count2 = 0;
            l2 = r2 - 1;
        }

        if (count2 == 0) {
            int len = l2 - r2 + 1;
            ans = max(ans, len);
        }
    }
    return ans;
}
};