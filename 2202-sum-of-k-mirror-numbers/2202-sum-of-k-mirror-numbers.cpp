#define ll long long 
class Solution {
public:

    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    ll createPalindrome(ll num, bool odd) {
        ll x = num;
        if (odd) x /= 10;
        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    string toBaseK(ll num, int k) {
        if (num == 0) return "0";
        string res = "";
        while (num > 0) {
            int rem = num % k;
            res += (rem < 10 ? (rem + '0') : (rem - 10 + 'A'));
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    ll kMirror(int k, int n) {
        ll sum = 0;
        for (ll i = 1; n > 0; i *= 10) {

            for (ll j = i; n > 0 && j < i * 10; ++j) {
                ll p = createPalindrome(j, true);
                string baseK = toBaseK(p, k);
                if (isPalindrome(baseK)) {
                    sum += p;
                    n--;
                }
            }

            for (ll j = i; n > 0 && j < i * 10; ++j) {
                ll p = createPalindrome(j, false);
                string baseK = toBaseK(p, k);
                if (isPalindrome(baseK)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};
