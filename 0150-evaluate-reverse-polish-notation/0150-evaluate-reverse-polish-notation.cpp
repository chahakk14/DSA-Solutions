class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
            for(int i=0; i<tokens.size(); i++){
                string token = tokens[i];
                
                if(token=="+" || token=="-" || token=="*" || token=="/"){
                    int b= s.top();
                    s.pop();
                    int a=s.top();
                    s.pop();
                    int ans=0;
                if(token=="+") ans=a+b;
                else if(token=="-") ans=a-b;
                else if(token=="*") ans=a*b;
                else if(token=="/") ans=a/b;
                s.push(ans);
                }
                else {
                s.push(stoi(token));
               }
            }
        return s.top();
    }
};