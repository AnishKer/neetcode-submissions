class Solution {
public:

    bool checkrow(vector<vector<int>>& matrix,int n, int target){
        int left=0,right = matrix[0].size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(matrix[n][mid] == target) return true;
            else if(matrix[n][mid] < target) left = mid+1;
            else right=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0 , down = matrix.size()-1;
        while(up<=down){
            int mid = up + (down-up)/2;
            if(matrix[mid][0] <= target && matrix[mid][matrix[0].size()-1] >=target){
                return checkrow(matrix,mid,target);
            }else if(matrix[mid][0] >target) down = mid-1;
            else if(matrix[mid][matrix[0].size()-1] <target) up=mid+1;
        }
        return false;
    }
};
