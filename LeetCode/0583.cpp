class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int i = word1.length();
        int j = word2.length();
        dp = vector<vector<int>>(i + 1, vector<int>(j + 1, -1));
        return editDistance(word1, word2, i, j);
    }

private:
    vector<vector<int>> dp;
    int editDistance(string &word1, string &word2, int m, int n)
    {
        if (m == 0)
        {
            return n;
        }
        if (n == 0)
        {
            return m;
        }
        if (dp[m][n] >= 0)
        {
            return dp[m][n];
        }

        int ans;
        if (word1[m - 1] == word2[n - 1])
        {
            ans = editDistance(word1, word2, m - 1, n - 1);
        }
        else
        {
            ans = 1 + min(editDistance(word1, word2, m - 1, n),
                          editDistance(word1, word2, m, n - 1));
        }

        return dp[m][n] = ans;
    }
};