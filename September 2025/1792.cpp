#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // Custom comparator for heap based on "gain"
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max-heap storing {gain, pass, total}
        priority_queue<array<double, 3>> pq;
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), (double)c[0], (double)c[1]});
        }

        // Assign extra students
        for (int s = 0; s < extraStudents; s++) {
            auto top = pq.top(); pq.pop();
            double pass = top[1], total = top[2];

            pass += 1;
            total += 1;

            pq.push({gain(pass, total), pass, total});
        }

        // Compute final average
        double sum = 0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            sum += top[1] / top[2];
        }
        return sum / n;
    }
};
