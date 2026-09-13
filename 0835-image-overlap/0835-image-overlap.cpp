class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        int best = 0;

        for (int dx = -n + 1; dx <= n - 1; dx++) {
            for (int dy = -n + 1; dy <= n - 1; dy++) {
                int score = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int c = 0;
                        if (dx + i >= 0 && dx + i < n && dy + j >= 0 && dy + j < n) {
                            c = img1[dx + i][dy + j];
                        }
                        score += img2[i][j] & c;
                    }
                }
                best = std::max(best, score);
            }
        }

        return best;
    }
};