#define ll long long
class Solution {
public:
    bool isPalindrome(ll n) {
    ll original = n, reversed = 0;

    while (n > 0) {
        ll digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return original == reversed;
}

};