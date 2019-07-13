class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        vector<bool> visited(M.size(), false);
        int groups = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if (visited[i] == 0)
            {
                dfs(M, visited, i);
                groups++;
            }
        }
        return groups;
    }

private:
    void dfs(vector<vector<int>> &M, vector<bool> &visited, int i)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if (M[i][j] == 1 && visited[j] == false)
            {
                visited[j] = true;
                dfs(M, visited, j);
            }
        }
    }
};