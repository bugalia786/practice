#include <stdio.h>
#include <stdlib.h>

int visited[9] ={0,0,0,0,0,0,0,0,0};
int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
void DFS(int i){
    if(visited[i]==0){
        printf("%d ",i);
        visited[i]=1;
    }
    for(int v=1;v<=8;v++){
        if(A[i][v]==1 && visited[v]==0){
            DFS(v);
        }
    }
}

int main() {
	
    DFS(6);
	return 0;
}
