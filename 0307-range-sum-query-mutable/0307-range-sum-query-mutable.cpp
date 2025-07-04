class NumArray {
public:
    vector<int> seg = vector<int>(4 * 100000, 0);
    vector<int> lazy = vector<int>(4 * 100000, 0);
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        build(0, 0, n - 1, nums);
    }

    void build(int idx, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void pointUpdate(int idx, int index, int val, int l, int r) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid)
            pointUpdate(2 * idx + 1, index, val, l, mid);
        else
            pointUpdate(2 * idx + 2, index, val, mid + 1, r);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int index, int val) {
        pointUpdate(0, index, val, 0, n - 1);
    }

    void range(int idx, int low, int high, int l, int r, int val) {
        if (lazy[idx] != 0) {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (r < low || l > high || low > high)
            return;

        if (low >= l && high <= r) {
            seg[idx] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        int mid = (low + high) / 2;
        range(2 * idx + 1, low, mid, l, r, val);
        range(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int querySum(int idx, int low, int high, int l, int r) {
        if (lazy[idx] != 0) {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (r < low || l > high || low > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;
        int left = querySum(2 * idx + 1, low, mid, l, r);
        int right = querySum(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    int sumRange(int left, int right) {
        return querySum(0, 0, n - 1, left, right);
    }
};
