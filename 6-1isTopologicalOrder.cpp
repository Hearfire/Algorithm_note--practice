/*6-1 Is Topological Order (8 分)*/



bool IsTopSeq(LGraph Graph, Vertex Seq[]) {	
	//计算所有点的入度
	int indegree[MaxVertexNum] = { 0 };
	int i;
	PtrToAdjVNode adjnow;
	for (i = 0; i < Graph->Nv; i++) {
		adjnow = Graph->G[i].FirstEdge;
		while (adjnow != NULL) {
			indegree[adjnow->AdjV]++;
			adjnow = adjnow->Next;
		}
	}
	
	int j;
	for (i = 0; i < Graph->Nv; i++) {
		if (indegree[Seq[i]-1]==0) {
			//当前点确实为入度为0的点，可以访问，将其邻接点入度减一
			adjnow = Graph->G[Seq[i]-1].FirstEdge;
			while (adjnow != NULL) {
						indegree[adjnow->AdjV]--;
						adjnow = adjnow->Next;
			}
		}
		else {
			return false;
		}
	}	
	return true;	
}

LGraph ReadG() {
	int i;
	LGraph LG = (LGraph)malloc(sizeof(GNode));
	for (int j = 0; j < 10; j++)
		LG->G[j].FirstEdge = NULL;
	scanf_s("%d %d", &LG->Nv, &LG->Ne);
	for (i = 0; i < LG->Ne; ++i)
	{
		int p1, p2;
		PtrToAdjVNode adj = (AdjVNode *)malloc(sizeof(AdjVNode));
		scanf_s("%d %d", &p1, &p2);
		p1--; p2--;  //注意这里，他输入后都减了1！！！
		adj->AdjV = p2;
		adj->Next = NULL;
		if (LG->G[p1].FirstEdge == NULL)
		{
			LG->G[p1].FirstEdge = adj;
		}
		else
		{
			adj->Next = LG->G[p1].FirstEdge;
			LG->G[p1].FirstEdge = adj;
		}
	}
	return LG;
}