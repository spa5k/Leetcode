class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (auto &&mat : matrix)
        {
            bool res = binarySearch(mat, target);
            if (res)
            {
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<int> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        if (target < matrix[left] || target > matrix[right])
        {
            return false;
        }

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int midn = matrix[mid];
            if (target == midn)
            {
                return true;
            }
            else if (target < midn)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};