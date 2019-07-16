class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph = vector<vector<int>>(numCourses);

        for (vector<int> p : prerequisites)
            graph[p[0]].push_back(p[1]);

        // states: 0 = haven't touched, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);

        for (int i = 0; i < numCourses; ++i)
        {
            if (hasCycle(i, v))
            {
                return false;
            }
        }

        return true;
    }

private:
    vector<vector<int>> graph;
    bool hasCycle(int course, vector<int> &v)
    {
        if (v[course] == 1)
        {
            return true; // cycle
        }
        if (v[course] == 2)
        {
            return false; // visited course, no cycle
        }

        v[course] = 1; // mark as visiting
        for (int p : graph[course])
        {
            if (hasCycle(p, v))
            {
                return true; // cycle
            }
        }
        v[course] = 2; // mark as visited
        return false;
    }
};