#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0, e = m - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1])
            {
                int st = 0, end = n - 1;

                while (st <= end)
                {
                    int md = st + (end - st) / 2;
                    if (matrix[mid][md] == target)
                        return true;
                    else if (matrix[mid][md] > target)
                        end = md - 1;
                    else if(matrix[mid][md] < target)
                        st = md + 1;
                }
                return false ;
            }
            else if (target <= matrix[mid][0])
                e = mid - 1;
            else if (target >= matrix[mid][n-1])
                s = mid + 1;
        }
        return false;
    }
};
