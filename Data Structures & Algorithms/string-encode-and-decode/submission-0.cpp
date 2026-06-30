class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for(string str:strs){
            result+=to_string(str.length());
            result+='#';
            result+=str;
        } 
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.length()){
            //find #
            int j=i;
            int len=0;
            while(s[j]!='#'){
                len = len*10+(s[j]-'0');
                j++;
            }
            //move after #
            j++;
            //extract the string
            string word = s.substr(j,len);
            result.push_back(word);
            //move to next endoers string
            i=j+len;
        }
        return result;
    }
};
