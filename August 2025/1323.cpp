// Solution 1
class Solution {
public:
    int maximum69Number(int num) {
        int pos = -1;
        int index = 0;
        int temp = num;
        // 1. Postive Number
        while (temp > 0) {
            // find last digit of 6
            if (temp % 10 == 6) {
                // update index in position
                pos = index;
            }
            // number divide by 10
            temp /= 10;
            // increase by 1
            index++;
        }
        // if not 6 then return existing number
        if (pos == -1) {
            return num;
        }
        // Add 3 * (10^pos) to flip that 6 into 9
        return num + 3 * pow(10, pos);
    }
};

// Solution 2
class Solution {
public:
    int maximum69Number(int num) {
        string t = to_string(num);
        int n = t.size();
        for (int i = 0; i < n; i++) {
            if(t[i] == '6'){
                t[i] = '9';
                return stoi(t);
            }
        }
        return num;
    }
};

// Solution 3
class Solution {
public:
    int maximum69Number(int num) {
        string t = to_string(num);
        for (char &c : t) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(t);
    }
};