class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length();
        int len=words[0].size();
        vector<int>ans;
        unordered_map<string,int>map;
        for(string str:words) map[str]++;
        for(int i=0; i<len; i++){
            int left=i;
            int right=i;
            unordered_map<string,int>winMap;
            int count=0;
            while(right<n-len+1){
                string temp= s.substr(right,len);
                if(map.find(temp)!=map.end()){
                    winMap[temp]++;
                    count++;
                    while(winMap[temp]>map[temp]){
                        string leftStr=s.substr(left,len);
                        winMap[leftStr]--;
                        left+=len;
                        count--;
                    }
                    if(count==words.size()) ans.push_back(left);
                }
                else{
                    left=right+len;
                    count=0;
                    winMap.clear();
                }
                right+=len;
            }
        }
        return ans;
    }
};