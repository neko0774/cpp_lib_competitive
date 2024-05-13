#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(ll N){
  ll i=3;
  if (N==2) return true;
  if (N==1||N%2==0) return false;
  while (i*i<=N){
    if (N%i==0) return false;
    i +=2;
  }
  return true;
}

ll divisionors(ll N){
  ll i=1, cnt=0;
  while (i*i<=N){
    if (N%i==0&&i==N/i) cnt++;
    else if(N%i==0) cnt+=2;
    i++;
  }
  return cnt;
}

ll gcd(ll A, ll B){
  if (A>B) swap(A,B);
  ll R = A%B;
  if (R==0){return B;}
  else return gcd(B, R);
}