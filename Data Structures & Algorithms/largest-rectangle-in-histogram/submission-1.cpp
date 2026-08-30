class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int area=0;
        for(int i=0;i<=n;i++){
            int current = (i==n?0:heights[i]);
            while(!st.empty() && current<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width = i-st.top()-1;
                area = max(area,width*height);
            }
            if(i<n) st.push(i);
        }
        return area;
    }
};
