#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
struct BIT{
  int N;
  vector<T> data = vector<T>(N);
  BIT(int _N=0): data(_N){}

  void add(int i, T x){
    i++;
    while(i<=data.size()){
      data[i-1]+=x;
      i += i&-i;
    }
  }

  T rsum(int r){
    T s = 0;
    while(r>0){
      s += data[r-1];
      r -= r&-r;
    }
    return s;
  }

  T sum(int l, int r){
    //[l, r)
    return rsum(r)-rsum(l);
  }
};