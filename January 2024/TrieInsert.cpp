class Solution
{
public:
    unordered_map<string, bool> mp;
    void insert(struct TrieNode *root, string key)
    {
        mp[key] = true;
    }

    // Function to use TRIE data structure and search the given string.
    bool search(struct TrieNode *root, string key)
    {
        return mp[key];
    }
};