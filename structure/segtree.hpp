#include <bits/stdc++.h>
using namespace std;
#define ll long long


template<typename Monoid>
struct segtree{
  using F = function< Monoid(Monoid, Monoid) >;
  int size;
  const Monoid e;
  const F op;
  vector<Monoid> seg;
  segtree(int _N, F _op, const Monoid &_e): op(_op), e(_e){
    size = 1;
    while(size<_N) size <<= 1;
    seg.assign(2*size, e);
  }

  Monoid fold(int l, int r){
    Monoid vl = e, vr = e;
    for(l += size, r += size; l < r; l >>= 1, r >>= 1){
      if(l&1)vl = op(vl, seg[l++]);
      if(r&1)vr = op(vr, seg[--r]);
    }
    return op(vl, vr);
  }

  void set(int i, Monoid x){
    i += size;
    seg[i] = op(x, seg[i]);
    while(i>>=1){
      seg[i] = op(seg[i*2], seg[i*2+1]);
    }
  }

  Monoid get(int i){
    return seg[i+size];
  }

  void debug(){
    for(int i=0;i<size;i++){
      cout << seg[i+size] << ' ';
    }
    cout << endl;
  }
};