#pragma once
#include "libs.h"

class Graph {
	/*
	This class describes an undirected unweighted graph.
	There are no more than __MAX_GRAPH_SIZE__ vertices in the graph.
	*/
private:
	int N, M; // Num of vertices, Num of edges 

	int matrix[__MAX_GRAPH_SIZE__ + 1][__MAX_GRAPH_SIZE__ + 1];
	bool isCreated[__MAX_GRAPH_SIZE__ + 1];

	class queue {
	// This queue is required for BFS
	private:
		int pfront, pback;
		int q[__MAX_GRAPH_SIZE__ + 1];
	public:
		queue();

		void push(int V);
		int front();

		void pop();
		bool empty();
	};

public:
	Graph();

	void addVertex(int V);
	void delVertex(int V);

	void addEdge(int V1, int V2);
	void delEdge(int V1, int V2);

	int getDist(int V1, int V2);
};