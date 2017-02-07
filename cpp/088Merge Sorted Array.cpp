 /*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tp  = m+n-1;
        int mt = m;
        int nt = n;
        while(nt>0 && mt>0){
            int i1 = nums1[mt-1];
            int i2 = nums2[nt-1];
            if(i1<i2){
                nums1[tp] = i2;
                nt--;
            }
            else{
                nums1[tp] = i1;
                mt--;
            }
            tp--;
        }
        if(nt!=0){
            for(int i = 0;i<nt;i++){nums1[i]=nums2[i];}
        }
    }
};