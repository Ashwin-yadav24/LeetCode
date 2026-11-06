
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        int m = queries.size();
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        unordered_map<int, int> freq;
        vector<int> ans(m);

        int left = 0, right = 0;
        int activeServers = 0;

        for (auto& query : q) {

            int start = query.first - x;
            int end = query.first;
            int index = query.second;

            while (right < logs.size() && logs[right][1] <= end) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    activeServers++;
                }

                freq[server]++;
                right++;
            }

            while (left < right && logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    activeServers--;
                }

                left++;
            }
            ans[index] = n - activeServers;
        }

        return ans;
    }
};
