class Solution{
public:	

    void getans(string temp,int n,vector<string> &ans,char add){
        temp.push_back(add);
        // cout<<temp<<endl;
        if(temp.length()==n){
            ans.push_back(temp);
            return ;
        }
        int c1=0;
        int c2=0;
        for(auto i:temp){
            if(i=='1'){
                c1++;
            }else{
                c2++;
            }
        }
        if(c1>c2){
            getans(temp,n,ans,'0');
            getans(temp,n,ans,'1');
        }else{
            getans(temp,n,ans,'1');
        }
    }



	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string temp="";
	    getans(temp,n,ans,'1');
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};