class Solution {
public:
    int passwordStrength(string password) {
        int point=0;
        vector<bool> used(256, false);
        for(char ch: password){
            if(used[ch]) continue;

            used[ch] = true;
            if(ch>='a' && ch<='z'){
                point+=1;
            }
            if(ch>='A' && ch<='Z'){
                point+=2;
            }
            if(ch>='0' && ch<='9'){
                point+=3;
            }
            if(ch=='!' || ch=='@' || ch=='#' || ch=='$'){
                point+=5;
            }
        }
        return point;
    }
};