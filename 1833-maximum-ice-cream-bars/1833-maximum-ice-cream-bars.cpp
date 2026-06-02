class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int spend=0;
        int count=0;
        int i=0;
        while(i<costs.size()){
            spend+=costs[i];
            if(coins>=spend){
                count++;
                i++;
            }
            else{
                break;
            }
        }
        return count;
    }
};