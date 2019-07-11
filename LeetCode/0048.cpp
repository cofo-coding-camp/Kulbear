class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // transpose
        /*
        [1 2 3]          [1 4 7]
        [4 5 6]    >>    [2 5 8]
        [7 8 9]          [3 6 9]
         */
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }

        // horizontally flip
        /*
        [1 4 7]          [7 4 1]
        [2 5 8]    >>    [8 5 2]
        [3 6 9]          [9 6 3]
         */
        for (int i = 0; i < n; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};