class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int i = 0, j = 0, ans = 0;
        set<char> map;
        while (i < n && j < n)
        {
            if (map.count(s[j]) == 0)
            {
                map.emplace(s[j++]);
                ans = max(ans, j - i);
            }
            else
            {
                map.erase(s[i++]);
            }
        }
        return ans;
    }

    int lengthOfLongestSubstringTLE(string s)
    {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (unique(s, i, j))
                {
                    ans = max(ans, j - i);
                }
            }
        }
    }

private:
    bool unique(string &s, int i, int j)
    {
        set<char> map;
        for (; i < j; i++)
        {
            if (map.count(s[i]))
            {
                return false;
            }
            map.emplace(s[i]);
        }
        return true;
    }
};