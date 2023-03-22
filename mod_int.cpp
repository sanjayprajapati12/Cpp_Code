#include<bits/stdc++.h>
using namespace std;


// uthaya hua hi hai 
int mod = 10000007;
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct mod_int{
    int x;
    mod_int(int x) : x(norm(x % mod)) {}
    int val() const {
        return x;
    }
    mod_int operator-() const {
        return mod_int(norm(mod - x));
    }
    mod_int inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    mod_int &operator*=(const mod_int &rhs) {
        x = int(x) * rhs.x % mod;
        return *this;
    }
    mod_int &operator+=(const mod_int &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) {
        return *this *= rhs.inv();
    }
    friend mod_int operator*(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res *= rhs;
        return res;
    }
    friend mod_int operator+(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res += rhs;
        return res;
    }
    friend mod_int operator-(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res -= rhs;
        return res;
    }
    friend mod_int operator/(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, mod_int &a) {
        int v;
        is >> v;
        a = mod_int(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &a) {
        return os << a.val();
    }
};

int32_t main(){

    mod_int ans = 6;
    ans *= 1666668;
    cout<<ans<<endl;
    return 0;
}