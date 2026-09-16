#define ll long long
class Solution {
public:
    vector<ll> fact;
    vector<ll> invFact;
    const int MOD = 1e9+7;

    ll findPower(ll a, ll b) {
        if(b == 0)
            return 1;
        
        ll half = findPower(a, b/2);
        ll result = (half * half) % MOD;

        if(b%2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    //nCr % MOD
    ll nCr(int n, int r) {
        //nCr = n! * inv(n-r)! * inv(r)!
        return (((fact[n] * invFact[r]) % MOD) * invFact[n-r]) % MOD;
    }

    int numberOfSets(int n, int k) {
        
        fact.assign(n+k, 1);
        invFact.assign(n+k, 1);

        for(int i = 2; i < n+k; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        for(int i = 0; i < n+k; i++) {
            invFact[i] = findPower(fact[i], MOD-2);
        }

        return nCr(n+k-1, 2*k);
    }
};
