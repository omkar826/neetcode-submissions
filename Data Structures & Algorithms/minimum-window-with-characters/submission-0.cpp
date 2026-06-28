class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int l=0,r=0,minlen=INT_MAX,sindex=-1,count=0,n=s.size(),m=t.size();
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<s.size()){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
        while(count==m){
            if(r-l+1<minlen){ 
                minlen=r-l+1;
                sindex=l;
            }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};
