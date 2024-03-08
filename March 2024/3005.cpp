class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int fx[101]  ={ 0},
        mx = 0, F = 0;
        for(auto num : nums){
            fx[num]++;
            F += (fx[num] == mx);
            if(fx[num] > mx){
                F = 1;
                mx = fx[num];
            }
        }
        return F * mx;
    }
};