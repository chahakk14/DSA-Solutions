class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n= costs.size();
        int maxEle= *max_element(costs.begin(),costs.end());
        vector<int>freq(maxEle+1);
        for(int i:costs){
            freq[i]++;
        }
        int count=0;
        for(int i=0;i<=maxEle;i++){
            while(freq[i]>0 && coins>=i){
                count++;
                freq[i]--;
                coins-=i;
            }
        }
        return count;
    }
};