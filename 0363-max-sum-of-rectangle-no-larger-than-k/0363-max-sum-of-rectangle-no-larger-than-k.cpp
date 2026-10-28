class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m < n) {
            vector<vector<int>> transposed(n, vector<int>(m));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    transposed[j][i] = matrix[i][j];
                }
            }

            matrix = transposed;
            swap(m, n);
        }

        long long ans = LLONG_MIN;

        for (int left = 0; left < n; left++) {
            vector<long long> rowSum(m, 0);

            for (int right = left; right < n; right++) {

                for (int r = 0; r < m; r++) {
                    rowSum[r] += matrix[r][right];
                }

                set<long long> prefix;
                prefix.insert(0);

                long long prefix_value = 0;

                for (long long x : rowSum) {
                    prefix_value += x;

                    auto it = prefix.lower_bound(prefix_value - k);

                    if (it != prefix.end()) {
                        ans = max(ans, prefix_value - (*it));
                    }

                    prefix.insert(prefix_value);

                    if (ans == k) return k;
                }
            }
        }

        return (int)ans;
    }
};