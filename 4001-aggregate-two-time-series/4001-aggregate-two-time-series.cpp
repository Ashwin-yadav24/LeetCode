class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n = series1.size(), m = series2.size();
        int i = 0;
        int j = 0;
        while (i < n || j < m) {
            int t;
            if (j == m || (i < n && series1[i][0] < series2[j][0])) {
                t = series1[i][0];
            } else if (i == n || (j < m && series2[j][0] < series1[i][0])) {
                t = series2[j][0];
            } else {
                t = series1[i][0];
            }
            int v1 = 0, v2 = 0;
            if (i < n && series1[i][0] == t) {
                v1 = series1[i][1];
                i++;
            } else if (i < n) {
                v1 = series1[i][1];
            }
            if (j < m && series2[j][0] == t) {
                v2 = series2[j][1];
                j++;
            } else if (j < m) {
                v2 = series2[j][1];
            }
            ans.push_back({t, v1 + v2});
        }
        return ans;
    }
};