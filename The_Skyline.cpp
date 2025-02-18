#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        multiset<int> heights = {0}; 
        vector<pair<int, int>> result; 

        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]);
            events.emplace_back(b[1], b[2]); 
        }
        sort(events.begin(), events.end());

        int prevHeight = 0; 
        for (auto& e : events) {
            int x = e.first, h = e.second;
            
            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }
            int currHeight = *heights.rbegin();
            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    
    vector<pair<int, int>> skyline = sol.getSkyline(buildings);
    
    for (auto& point : skyline) {
        cout << "[" << point.first << ", " << point.second << "] ";
    }
    cout << endl;
    
    return 0;
}
