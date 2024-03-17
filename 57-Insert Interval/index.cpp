
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;

        // finding the index where the newInterval can be inserted
        auto insert_index = lower_bound(intervals.begin(), intervals.end(), newInterval);

        // inserting the newInterval
        intervals.insert(insert_index, newInterval);

        for (int i = 0; i < intervals.size(); i++)
        {
            // merging the overlapping intervals
            while (i + 1 < intervals.size() && intervals[i][1] >= intervals[i + 1][0])
            {
                intervals[i + 1][0] = min(intervals[i + 1][0], intervals[i][0]);
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
                i++;
            }
            // adding non-overlapping interval to result
            result.push_back(intervals[i]);
        }
        return result;
    }
};