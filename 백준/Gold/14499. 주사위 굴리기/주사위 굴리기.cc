#include<bits/stdc++.h>
using namespace std;

int n , m , x , y , k ;

int board[21][21];
int dx[5] {0,0,0,-1,1};
int dy[5] {0,1,-1,0,0};
int dice[7] {0,}; //index를 편하기 하기 위해 0번째는 의미없는 수
int topDice = 1;

void moveDice(int dir){ //주사위 굴리기
  if(dir == 1){
    int tmp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = tmp;
  } else if(dir == 2){
    int tmp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = tmp;
  } else if(dir == 3){
    int tmp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = tmp;
  } else {
    int tmp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = tmp;
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n >> m >> x >> y >> k ;

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < m ; ++j)
      cin >> board[i][j];
  }

  while(k--){
    int dir;
    cin >> dir;
    if( x+dx[dir]<0 || x+dx[dir]>=n || y+dy[dir]<0 || y+dy[dir]>=m ) continue;
    x = x+dx[dir];
    y = y+dy[dir];
    moveDice(dir);
    if(board[x][y]==0){ //이동한 칸의 수가 0이면
      board[x][y] = dice[6];
    }
    else{ //0이 아닌 경우에
      dice[6] = board[x][y];
      board[x][y] = 0;
    }
    cout << dice[1] << '\n';
  }

}