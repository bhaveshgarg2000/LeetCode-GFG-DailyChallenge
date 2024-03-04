class Solution{
  public:
    void swapElements(int arr[], int n){
        int i=0;
        while(i<n-2){
            swap(arr[i],arr[i+2]);
            i++;
        }
    }
};