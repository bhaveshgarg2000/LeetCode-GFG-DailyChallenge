class Solution
{
public:
    bool isLeapYear(int year)
    {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }
    int dayOfYear(string date)
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 4));

        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year))
        {
            daysInMonths[1] = 29;
        }
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; ++i)
        {
            dayOfYear += daysInMonths[i];
        }
        dayOfYear += day;

        return dayOfYear;
    }
};