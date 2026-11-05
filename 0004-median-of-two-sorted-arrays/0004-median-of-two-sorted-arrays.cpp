class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // to perform Binary Search always on smaller array
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;
        int half = (m + n + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = half - i;

            int left1 = (i == 0) ? INT_MIN : nums1[i - 1]; // if no left element then INT_MIN
            int right1 = (i == m) ? INT_MAX : nums1[i]; // if no right element then INT_MAX

            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return max(left1, left2); // odd-case
                }

                return (max(left1, left2) +
                        min(right1, right2)) / 2.0; // even-case
            }
            else if (left1 > right2) {
                high = i - 1; // eliminate right half
            }
            else {
                low = i + 1; // eliminate left half
            }
        }

        return 0.0;

    }
};