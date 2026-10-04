class Solution {
public:
    bool checkValidString(string s) {
        stack<char>open;
        stack<char>stars;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                open.push(i);
            }else if(ch=='*'){
                stars.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(!stars.empty()){
                    stars.pop(); 
                }else{
                    return false;
                }
            }
        }
        while(!stars.empty() && !open.empty()){
            if(open.top()<stars.top()){
            open.pop();    
            stars.pop();
            }else{
                return false;
            }
        }

        return  open.empty();
        
    }
};