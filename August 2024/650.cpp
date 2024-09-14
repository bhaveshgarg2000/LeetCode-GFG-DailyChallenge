class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
        {
            return 0;
        }

        int step = 0;
        int ft = 2;

        while (n > 1)
        {
            while (n % ft == 0)
            {
                step += ft;
                n /= ft;
            }
            ft++;
        }
        return step;
    }
};