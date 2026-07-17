class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int lp=0,rp=n-1;
        int maxWater=0;
        while(lp<rp){
            int width=rp-lp;
            int hi=min(heights[lp],heights[rp]);
            maxWater=max(width*hi,maxWater);
            heights[lp]<heights[rp]?lp++:rp--;
        }
        return maxWater;
    }
};
