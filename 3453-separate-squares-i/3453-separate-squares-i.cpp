class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
    // Max l+y height from base
    // Min y height from base
    /*
        We can Bs to find minimum y axis such that square below and above are same
        l<=h l->min(y),h=max(l+y)
        so for a particular y axis i have to check the area 
        if mid>=(l+h) [
            // This means that square is below the line 
        ]
        else if mid<=yi // Square is above the line 
        else if they intersect
    */
        double m = INT_MAX, M = INT_MIN;
    for (auto& p : squares) {
        m = min(m, (double)(p[1]));
        M = max(M, (double)(p[1] + p[2]));
    }

    double l = m, r = M, a = 0;
    while (r - l > 1e-6) {
        double x = l + (r - l) / 2.0, A = 0, B = 0;

        for (auto& p : squares) {
            int X = p[0], y = p[1], L = p[2];
            double Y = y + L;

            if (x <= y) A += (double)L * L;  
            else if (x > Y + 1e-6) B += (double)L * L;  
            else {
                double u = Y - x, d = x - y;
                A += u * L, B += d * L;
            }
        }

        if (A > B) a = x, l = x + 1e-6;
        else r = x - 1e-6;
    }

    return a;
}
};