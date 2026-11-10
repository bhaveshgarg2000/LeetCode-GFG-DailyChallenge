// Time Complexity: O(n logn) 
// N : As it took N time to iterate Array and log n time to Sort the Array
// Solution 1 : 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ansVector(n);
        for(int i = 0; i < n;i++){
            ansVector[i] = A[i] * A[i];
        }
        sort(ansVector.begin(),ansVector.end());
        return ansVector;
        
        
        
    }
};



// Solution 2 : Two Pointers – True In-place Variation
// Time Complexity: O(n logn)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        for(int i = 0; i <n; i++){
            A[i] = A[i] * A[i];
        }
        sort(A.begin(),A.end());
        return A;
    }
};




// Solution 3 : Two Pointers + Extra Result Array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans(n);
        int index = n - 1;

        while(left <= right){
            if(abs(A[left]) > abs(A[right])){
                ans[index] = A[left] * A[left];
                left++;
            }else{
                ans[index] = A[right] * A[right];
                right--;
            }
            index--;
        }
        
        return ans;
    }
};


// Solution 4 : Separate + Square + Reverse + Merge


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> positive;
        vector<int> negative;

        for(int num : A) {
            if(num < 0) {
                negative.push_back(num * num);
            } else {
                positive.push_back(num * num);
            }
        }

        reverse(negative.begin(), negative.end());

        vector<int> ans;
        int i = 0;
        int j = 0;

        while(i < negative.size() && j < positive.size()) {
            if(negative[i] < positive[j]) {
                ans.push_back(negative[i]);
                i++;
            } else {
                ans.push_back(positive[j]);
                j++;
            }
        }

        while(i < negative.size()) {
            ans.push_back(negative[i]);
            i++;
        }

        while(j < positive.size()) {
            ans.push_back(positive[j]);
            j++;
        }

        return ans;
    }
};




