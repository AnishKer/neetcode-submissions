class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;
        int n = nums1.size() , m = nums2.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(nums1[i] <= nums2[j]){
                final.push_back(nums1[i]);
                i++;
            }else{
                final.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            final.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            final.push_back(nums2[j]);
            j++;
        }
        if(final.size() % 2 == 0){
            return (double)(final[final.size()/2] + final[final.size()/2-1])/2;
        }else{
            return final[final.size()/2];
        }
    }
};
