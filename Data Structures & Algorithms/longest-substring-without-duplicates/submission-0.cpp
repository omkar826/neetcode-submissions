class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> hash;
        int l=0,r=0,maxlen=0,len=0;
        while(r<n){
            if(hash.find(s[r])!=hash.end()){//in the map
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
