//
// Created by Kylian Lee on 2021/07/29.
//

#include <cstdio>
#include <vector>

using namespace std;

vector<char> seats;

int TakeBurger(int i, int K);

int main(){
  int N, K, distributed = 0;
  scanf("%d %d", &N, &K);
  seats.resize(N);
  getchar();
  for (int i = 0; i < N; ++i) {
    seats[i] = getchar();
//    putchar(seats[i]);
  }
  for (int i = 0; i < N; ++i) {
    if(seats[i] == 'P')
      distributed += TakeBurger(i, K);
  }
  printf("%d\n", distributed);
  return 0;
}

int TakeBurger(int i, int K){
  int s = i - K;
  int ret = 0;
  if(i < K)
    s = 0;
  for (int j = s; j <= i + K; ++j) {
    if(seats[j] == 'H'){
      seats[j] = 'h';
      ret = 1;
      break;
    }
  }
  return ret;
}