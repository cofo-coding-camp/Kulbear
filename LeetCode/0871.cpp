class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int curFeul = startFuel;
        int stops = 0;
        priority_queue<int> q;
        int curStation = 0;

        while (true)
        {
            if (curFeul >= target)
            {
                return stops;
            }
            while (curStation < stations.size() && stations[curStation][0] <= curFeul)
            {
                q.push(stations[curStation++][1]);
            }
            if (q.empty())
            {
                break;
            }
            curFeul += q.top();
            q.pop();
            stops++;
        }

        return -1;
    }
};