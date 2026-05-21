#include<stack>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        for(int i=0; i<operations.size();i++){
            if(operations[i]=="+"){
                int top1 = s.top(); 
                s.pop();
                int top2 = s.top();
                s.push(top1);             
                s.push(top1 + top2);
            }
            else if(operations[i]=="D"){
                s.push(2 * s.top());
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else{
                s.push(stoi(operations[i]));
            }
        }

        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};