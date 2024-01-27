string  bracket(vector<vector<int>>& split, int i, int j) {
        if(i==j) {
          return string(1,'A'+i-1);
        }
        return "(" + bracket(split,i,split[i][j]) + bracket(split,split[i][j]+1,j) + ")";
       
    }
    
    string matrixChainOrder(int p[], int n){
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<vector<int>>split(n,vector<int>(n,0));
        
        for(int pair = 2; pair<n; pair++) {
            for(int i=1;i<n-pair+1;i++) {
                int j = i+pair-1;
                dp[i][j] = INT_MAX;
                for(int k=i;k<=j-1;k++) {
                    int cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                    if(cost<dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }
        return bracket(split,1,n-1);
        
    }