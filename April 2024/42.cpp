class Solution
{
public:
    int trap(vector<int> &height)
    {
        // O(N)
        // int n = height.size();
        // vector<int> leftLen(n);
        // vector<int> rightLen(n);
        // int minHeight;
        // leftLen[0] = height[0];
        // for(int i =1; i < n; i++){
        //     leftLen[i] = max(leftLen[i-1],height[i-1]);
        // }
        // rightLen[n-1] = 0;
        // for(int i = n - 2;i >= 0; i--){
        //     rightLen[i] = max(rightLen[i+1],height[i+1]);
        // }
        // int water = 0;
        // for(int i = 0; i < n; i++){
        //     minHeight = min(leftLen[i],rightLen[i]);

        //     if(minHeight - height[i] >= 0){
        //         water += minHeight - height[i];
        //     }
        // }
        // return water;

        // O(1)
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftmax = 0;
        int rightmax = 0;
        int water = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > leftmax)
                {
                    leftmax = height[left];
                }
                else
                {
                    water += leftmax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] > rightmax)
                {
                    rightmax = height[right];
                }
                else
                {
                    water += rightmax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};