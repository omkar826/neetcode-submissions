class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int tar, int row){
        int n=mat[0].size();
        int st=0,end=n-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(tar==mat[row][mid]){
                return true;
            }else if(tar>mat[row][mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size();
        int n = mat[0].size();
        int startRow = 0, endRow = m-1;
        while(startRow<=endRow){
            int midRow = startRow+(endRow-startRow)/2;
            if(mat[midRow][0]<=tar && tar<=mat[midRow][n-1]){
                return searchInRow(mat,tar,midRow);
            }else if(mat[midRow][n-1]<tar){
                //bottom
                startRow = midRow+1;
            }else{
                //up
                endRow = midRow-1;
            }
        }
        return false;
    }
};
