#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9+7;
vector<ll> fac, finv, inv;


void bino_init(ll N){
  fac.resize(N);
  finv.resize(N);
  inv.resize(N);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<N; i++){
    fac[i] = fac[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll comb(ll n, ll r){
  if(r>n||n<0||r<0) return 0;
  return fac[n]*finv[r]%mod*finv[n-r]%mod;
}


int main(){
}

template<typename T>
T comb(T N, T C, ll mod){
  T a = 1;
  T b = 1;
  for(int i=0;i<C;i++){
    a = a*(N-i)%mod;
    b = b*(N+i)%mod;
  }
  return a*modpow(b, mod-2, mod)%mod;
}