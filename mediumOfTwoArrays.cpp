#include "inc.h"
//Leetcode 4
class Solution {
public:
    int max(int &a, int &b){
        return a>b?a:b;
    }
    //不需要去除重复的数字
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);//nums1要比nums2长度小
        int start = 0;
        int end = m;
        int mid = (m+n)>>1;//表示中间数应该的索引位置
        int Left = 0, Right = 0;
        while(start <= end) {
            int index1 = (start + end + 1)>>1;//nums1中间值得位置
            int index2 = mid-index1;//由index1得到index2
            if (index1>0 && nums1[index1-1] > nums2[index2]) {
                end = index1-1;
            }
            else if (index1 < m && nums1[index1] < nums2[index2-1]) {
                start = index1 + 1;
            }
            else {//满足 nums1[index1-1] <= nums2[index2]和nums2[index2-1] <= nums1[index1]的情况
                if (index1 == 0) {
                    Left = nums2[index2-1];
                }//如果长度是偶数，则要分别取左边的最大值和右边的最小值，取他们的平均值
                else if (index2 == 0) {
                    Left = nums1[index1-1];
                }else Left = max(nums2[index2-1], nums1[index1-1]);//两个都能取到，则直接去最大的左边值
                
                if (index1 == m) {
                    Right = nums2[index2];//如果index1已经取不到了，则最大值直接从能取到的nums2取
                }
                else if (index2 == n) {
                    Right = nums1[index1];
                }else Right = min(nums1[index1], nums2[index2]);//两个都能取到，则直接去最小的右边值
                if ((m+n)%2 == 1) {//如果长度是奇数，则直接返回中间数
                    return Right;
                }
                break;
            }         
        }
        return (Left+Right)/2.0;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v1 = {-1, 0, 1,3};
    vector<int> v2 = {3,4};
    Solution so;
    cout << so.findMedianSortedArrays(v1,v2) << endl;
    return 0;
}
