#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = nums1.size() + nums2.size();
		if (len % 2 != 0) {
			return findKthInSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), len / 2 + 1);
		}
		else {
			return (findKthInSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), len / 2) + findKthInSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), len / 2 + 1)) / 2.0;
		}
	}
	//delete k / 2 elements each time if possible
	double findKthInSortedArrays(vector<int>::iterator beg1, vector<int>::iterator end1, vector<int>::iterator beg2, vector<int>::iterator end2, int k) {
		if (end1 - beg1 > end2 - beg2) {
			return findKthInSortedArrays(beg2, end2, beg1, end1, k);
		}
		if (beg1 == end1) {
			return *(beg2 + k - 1);
		}
		if (k == 1) {
			return *beg1 < *beg2 ? *beg1 : *beg2;
		}
		int pivot = k / 2 < (end1 - beg1) ? k / 2 : (end1 - beg1);
		if (*(beg1 + pivot - 1) < *(beg2 + pivot - 1)) {
			return findKthInSortedArrays(beg1 + pivot, end1, beg2, end2, k - pivot);
		}
		else {
			return findKthInSortedArrays(beg1, end1, beg2 + pivot, end2, k - pivot);
		}
	}
};