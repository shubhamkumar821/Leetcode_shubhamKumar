class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        int left = binarySearchInc(mountainArr, 0, peak, target);
        if (left != -1) return left;

        return binarySearchDec(mountainArr, peak + 1,
                               mountainArr.length() - 1, target);
    }

private:
    int findPeak(MountainArray &mountainArr) {
        int l = 0, h = mountainArr.length() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }

    int binarySearchInc(MountainArray &mountainArr, int l, int h, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            if (val < target) l = mid + 1;
            else h = mid - 1;
        }
        return -1;
    }

    int binarySearchDec(MountainArray &mountainArr, int l, int h, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            if (val > target) l = mid + 1;
            else h = mid - 1;
        }
        return -1;
    }
};
