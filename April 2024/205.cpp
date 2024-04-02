class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int mapping_s[256] = {0}; // Mapping array for characters of string s
        int mapping_t[256] = {0}; // Mapping array for characters of string t

        // Iterate through the characters of both strings simultaneously
        for (int i = 0; i < s.size(); i++)
        {
            // If the current characters in both strings are mapped differently
            if (mapping_s[s[i]] != mapping_t[t[i]])
            {
                return false;
            }
            // If the current characters in both strings are not mapped yet
            // Assign them a new mapping
            if (mapping_s[s[i]] == 0)
            {
                mapping_s[s[i]] = i + 1; // Increment by 1 to avoid confusion with default value (0)
                mapping_t[t[i]] = i + 1;
            }
        }
        return true;
    }
};
