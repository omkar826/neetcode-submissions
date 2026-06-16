class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size()-1;
        int j = nums2.size()-1;
        int idx = nums1.size() + nums2.size() - 1;
        vector<int> ans(nums1.size()+nums2.size(),0);
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                ans[idx]=nums1[i];
                idx--;
                i--;
            }else{
                ans[idx]=nums2[j];
                idx--;
                j--;
            }
        }
        while(i>=0){
            ans[idx]=nums1[i];
            idx--;
            i--;
        }
        while(j>=0){
            ans[idx]=nums2[j];
            idx--;
            j--;
        }
        int n=ans.size();
        int mid=n/2;
        if(n%2==0){
            return (ans[mid]+ans[mid-1])/2.0;
        }else{
            return ans[mid];
        }
    }
};
