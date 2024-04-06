#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // this cnt variable is going to hold 3 scenarios:
        //  cnt = 0 : same number of 0 and 1
        //  cnt > 0 : more no of 1s
        //  cnt<0 : more no of 0s
        int cnt = 0;

        // to store the map of count and index of count
        unordered_map<int, int> map;
        // initializing the map
        map[0] = -1;

        // will store the max_length
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i] == 1 ? 1 : -1;

            // if a count that already exists reappears, it implies that between these
            // counts we'll have a effective count of 0 i.e same number of 0 and 1

            if (map.count(cnt))
            {
                res = max(res, i - map[cnt]);
            }

            else
                map[cnt] = i;
        }
        return res;
    }
};