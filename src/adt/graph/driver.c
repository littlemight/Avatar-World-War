#include "graph.h"

int main(){
	Graph g;
    CreateGraph(1, &g);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d",&x);
            if (x == 1) {
                InsertEdge(&g, i, j);
            }
        }
    }
    
	/* Print all edges */
	adrNode P = First(g);
	while(P != NilGraph){
		infotypeGraph Id1 = Id(P);
		adrSuccNode Ps = Trail(P);
        printf("%d -> ", Id1);
		while (Ps != NilGraph){
			infotypeGraph Id2 = Id(Succ(Ps));
            printf("%d ", Id2);
			Ps = Next(Ps);
		}
        printf("\n");
		P = Next(P);
	}
    return 0;
}
	