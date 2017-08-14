#include "inc.h"

class Solution {
public:
    Solution();
    int max(int &a, int &b){
        return a>b?a:b;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (n < m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int imin = 0;
        int imax = m;
        int mid = (m+n+1)/2;
        int max_left_part;
        int min_right_part;
        while (imin <= imax) {
            int i = (imin+imax)>>1;
            int j = mid - i;
            if (i < m && nums1[i] < nums2[j-1])
            {
                imin = i + 1;
            }
            if (i > 0 && nums1[i-1] > nums2[j])
            {
                imax = i - 1;
            }
            else{
                if (i == 0)
                {
                    max_left_part = nums1[j-1];
                }
                if (j == 0)
                {
                    max_left_part = nums2[i-1];
                }
                else
                {
                    max_left_part = max(nums1[i-1], nums2[j-1]);
                }

                if ((m+n)%2==1)
                {
                    return max_left_part;
                }

                if (i == m)
                {
                    min_right_part = nums2[j];
                }
                if (j == n) {
                    min_right_part = nums1[i];
                }
                return (min_right_part+max_left_part)/2.0;
            }

        }

    }
};

int main(int argc, char const *argv[]) {
    vector<int> v1 = {1,2,6,7};
    vector<int> v2 = {3,4};
    Solution so;
    //cout << so.findMedianSortedArrays(v1,v2) << endl;
    return 0;
}
