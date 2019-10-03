class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        start from the leftbotton.
        T: O(m+n)
        */
        int i = matrix.size() - 1;
        int j = 0;
        while (i > - 1 && j < matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) i--;
            else j++;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        start from the leftbotton.
        replace linear search by binary search 
        T: O(m+n)
        */
        int i = matrix.size() - 1;
        int j = 0;
        while (i > - 1 && j < matrix[0].size()) {
            //if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) {
                i = binarySearch(j, 0, i, matrix, target);
                if (matrix[i][j] == target) return true;
                i = i - 1;
            }
            else {
                j = binarySearchH(i, j, matrix[0].size() - 1, matrix, target);
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] < target) j = j + 1;
            }
        }
        return false;
    }
    int binarySearch(int idx, int lo, int hi, vector<vector<int>>& matrix, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][idx] >= target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    int binarySearchH(int idx, int lo, int hi, vector<vector<int>>& matrix, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[idx][mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        divide and conquer
        use binary search to find row idx
        T: O( (logN)^2 )
        */
        if (matrix.empty()) return false;
        return helper(0, matrix[0].size() - 1, 0, matrix.size() - 1, matrix, target);
    }
    bool helper(int left, int right, int up, int down, vector<vector<int>>& matrix, int target) {
        if (left > right || up > down) return false;
        if (matrix[up][left] > target || matrix[down][right] < target) return false;
        int mid = left + (right - left) / 2;
        int row = binarySearch(mid, up, down, matrix, target);
        if (matrix[row][mid] == target) return true;
        return helper(left, mid - 1, row, down, matrix, target) ||
            helper(mid + 1, right, up, row, matrix, target);
    }
    int binarySearch(int idx, int lo, int hi, vector<vector<int>>& matrix, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][idx] >= target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
