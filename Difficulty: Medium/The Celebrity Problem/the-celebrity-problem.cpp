class Solution {
  public:
    int celebrity(vector<vector<int>>& matrix) {
        stack<int> st;
        int size = matrix.size();

    
        for(int i=0; i<size; i++) {
            st.push(i);
        }

        while(st.size() != 1) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
        
            if(matrix[first][second] == 1)  st.push(second);
            else st.push(first);
        }

        int candidate = st.top();
        st.pop();

        for(int i=0; i<size; i++) {
            if (i != candidate) {
                if (matrix[candidate][i] == 1 || matrix[i][candidate] == 0) {
                    return -1;
                }
            }
        }
         return candidate;
    }
};