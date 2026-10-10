class Solution {
public:
    int trap(vector<int>& height) {
      int l=0,r=height.size()-1;
      int ans=0;
      int leftmax=height[0],rightmax=height[height.size()-1];
      while(l<r){
        leftmax=max(leftmax,height[l]);
        rightmax=max(rightmax,height[r]);
        if(leftmax<rightmax){
            ans+=(leftmax-height[l]);
            l++;
        }
        else{
            ans+=(rightmax-height[r]);
            r--;
        }
      }  
      return ans;
    }
};
