#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct cumsum2d{
  vector<vector<T>> data;
  cumsum2d(int W, int H): data(H+1, vector<T>(W+1, 0)){}

  void add(int w, int h, T z){
    if(w>W+1||h>H+1) return;
    data[h][w]+=z;
  }

  void build(){
    for(int y=0;y<H;y++){
      for(int x=0;x<W;x++){
        data[y+1][x+1] += data[y][x+1]+data[y+1][x]-data[y][x];
      }
    }
  }

  T query(int gx, int gy, int sx, int sy){
    sx--; sy--;
    if(sx<=0||sy<=0||gy>H+1||gx>W+1) return 0;
    return data[gy][gx]-data[sy][gx]-data[gy][sx]+data[sy][sx];
  }
};
