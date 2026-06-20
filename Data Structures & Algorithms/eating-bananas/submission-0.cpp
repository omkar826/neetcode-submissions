class Solution {
public:
    int maxiele(vector<int>& piles){
        int maxel=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(maxel<piles[i]){
                maxel=piles[i];
            }
        }
        return maxel;
    }
    int funchours(vector<int>& piles ,int hours){
        int total_hours=0;
        for(int i=0;i<piles.size();i++){
        total_hours += (piles[i] + hours - 1) / hours;
       }
        return total_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxiele(piles),ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalhrs=funchours(piles,mid);
            if(totalhrs<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
