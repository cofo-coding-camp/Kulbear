class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph_ = vector<vector<int>>(numCourses);
        for (vector<int> p : prerequisites)
        {
            graph_[p[0]].push_back(p[1]);
        }

        vector<int> visited = vector<int>(numCourses, 0);
        // order_ = vector<int> {};
        for (int i = 0; i < numCourses; ++i)
        {
            if (detectCycle(i, visited))
            {
                return {};
            }
        }

        return order_;
    }

private:
    vector<vector<int>> graph_;
    vector<int> order_;
    bool detectCycle(int course, vector<int> &v)
    {
        if (v[course] == 1)
            return true;
        if (v[course] == 2)
            return false;

        v[course] = 1;

        for (int t : graph_[course])
            if (detectCycle(t, v))
            {
                return true;
            }

        v[course] = 2;
        order_.push_back(course);

        return false;
    }
};