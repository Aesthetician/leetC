class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
        
        -1 -2 3 4 5 6
              x
            L       R  
        */
        int idx = binarySearch(x, arr);
        int left = idx - 1, right = idx;
        vector<int> resLeft;
        vector<int> resRight;
        vector<int> res;
        while (k > 0 && (left > -1 || right < arr.size())) {
            if (left > -1 && abs(arr[left] - x) <= abs(arr[right] - x)) {
                resLeft.push_back(arr[left]);
                left--;
                k--;
            } else if (right < arr.size()) {
                resRight.push_back(arr[right]);
                right++;
                k--;
            }
        }
        for (int i = resLeft.size() - 1; i > -1; --i) {
            res.push_back(resLeft[i]);
        }
        for (int i = 0; i < resRight.size(); ++i) {
            res.push_back(resRight[i]);
        }
        return res;
    }
    int binarySearch(int target, vector<int>& arr) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
