class Solution
{
    public:
     vector <int> search(string pattern, string text)
{
    vector<int>v;
            int p=pattern.size(),t=text.size();
            for(int i=0;i<=t-p;i++){
                if( pattern == text.substr(i,p) ){
                    v.push_back(i+1);
                }
            }
            return v;
}
};