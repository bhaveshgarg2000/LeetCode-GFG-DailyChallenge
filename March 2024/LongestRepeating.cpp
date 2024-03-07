string longestSubstring(string s, int n) {
        // code here
        string ans;
        for(int i =0; i<n; i++){
            for(int j= i+1; j<n; j++){
                string temp;
                if(s[i] == s[j]){
                        temp = s[i];
                    int x = 1+i, y = 1+j;
                    while(x<j && y < n && s[x] == s[y]){
                            temp+=s[x];
                            x++;
                            y++;
                        }
                }
                if(temp.size() > ans.size()){
                    ans = temp;
                }
            }
        }
        return (ans.size() > 0)?ans:"-1";
    }