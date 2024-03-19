class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mpp;
        for (char task : tasks)
        {
            mpp[task]++;
        }

        priority_queue<int> pq;
        for (auto it : mpp)
        {
            pq.push(it.second);
        }

        int time = 0;
        while (!pq.empty())
        {
            vector<int> tmp;
            for (int i = 0; i <= n; i++)
            {
                if (!pq.empty())
                {
                    tmp.push_back(pq.top());
                    pq.pop();
                }
            }

            for (int count : tmp)
            {
                if (--count > 0)
                {
                    pq.push(count);
                }
            }

            time += pq.empty() ? tmp.size() : n + 1;
        }

        return time;
    }
};
