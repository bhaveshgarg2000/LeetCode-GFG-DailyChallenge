#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0"; // if top is 0, whole thing is 0
        string result;
        // handle sign: if only one of them is negative
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";
        // work with positive long long to avoid overflow shenanigans
        ll num = llabs((ll)numerator);
        ll den = llabs((ll)denominator);
        // dump the integer part first
        result += to_string(num / den);
        ll rem = num % den; // remainder after integer division
        if (rem == 0) return result; // if no remainder, we are done
        result += "."; // okay, decimal part incoming
        // this map remembers: remainder -> index in result string
        unordered_map<ll, int> seen;
        while (rem != 0) {
            // if we’ve seen this remainder before, loop detected
            if (seen.count(rem)) {
                result.insert(seen[rem], "("); // put opening bracket
                result += ")"; // close it
                break;
            }
            // mark where this remainder’s digit will appear
            seen[rem] = result.size();
            rem *= 10; // mimic long division (bring down zero)
            result += to_string(rem / den);
            rem %= den;
        }
        return result;
    }
};