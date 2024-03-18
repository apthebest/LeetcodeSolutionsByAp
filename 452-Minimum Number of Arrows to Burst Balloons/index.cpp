#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // sorting the points array by start position
        sort(points.begin(), points.end());

        // stores the number of arrows required
        int count = 0;

        for (int i = 0; i < points.size(); i++)
        {
            // if the balloons are overlapping
            while (i + 1 < points.size() && points[i + 1][0] <= points[i][1])
            {
                // update the end parameter for the balloon with the minimum value
                points[i + 1][1] = min(points[i][1], points[i + 1][1]);
                i++;
            }

            // increment for the count
            count++;
        }

        return count;
    }
};