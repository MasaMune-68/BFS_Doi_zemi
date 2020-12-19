#include <stdio.h>
#define NODES 9 /*点の数*/

int a[NODES+1][NODES+1] = {  /*挿入は厳しかったため、プログラムに隣接行列を打ち込む*/
  {0, 1, 0, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 0, 0, 1, 0, 0, 0},
  {1, 1, 0, 0, 0, 0, 1, 1, 0},
  {0, 1, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 0, 0, 1, 1},
  {0, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0, 1, 1, 0, 1},
  {0, 0, 0, 0, 0, 1, 0, 1, 0}
};

int v[NODES+1]; /*訪問フラグ*/
int queue[100]; /*キュー*/
int head = 0; /*先頭データのインデックス*/
int tail = 0; /*終端データのインデックス*/

int main(int argc, char *argv[]){ /*幅優先探索*/

  int i, j;
  for(i = 1; i <= NODES; i++){
    v[i] = 0;
  }

  queue[tail++] = 1;
  v[1] = 1;

  do{
    i = queue[head++]; /* キューから取り出す */
    for(j = 1; j <= NODES; j++){
      if( a[i][j] == 1 && v[j] == 0 ){
    printf("(%d, %d)", i, j);
    queue[tail++] = j; /* キューに入れる */
    v[j] = 1;
      }
    }
  }while( head != tail);

  printf("\n");
  
  return 0;
}
