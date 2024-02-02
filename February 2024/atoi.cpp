class Solution{
  public:
    int atoi(string s) {
        int ans = 0;
        int negative = 1;
        if(s.front() == '-') negative = -1;
        
        for(int i = 0; i < s.length(); i++){
            if(i == 0 && s[i] == '-')   continue;
            
            if(s[i] >= 48 && s[i] <= 57){   // ASCII value of '0' is 48 and '9' is 57
                ans = ans*10 + (s[i]-'0');
            }
            else{
                return -1;
            }
        }
        return (ans*negative);
    }
};