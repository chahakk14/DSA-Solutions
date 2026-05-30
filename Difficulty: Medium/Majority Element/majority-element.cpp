class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate=arr[0];
        int count=1;
        for(int i=1; i<arr.size(); i++){
            if(candidate==arr[i]) count++;
            else{
                count--;
                if(count==0){
                    candidate=arr[i];
                    count++;
                }
            }
        }
        count = 0;
        for (int num : arr) {
            if (num == candidate)
                count++;
        }

        return (count > arr.size() / 2) ? candidate : -1;
    }
};