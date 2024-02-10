#include "libs.h"
#include "Graph.h"

Graph::queue::queue() {
	pfront = 0;
	pback = 0;
}

void Graph::queue::push(int V) {
	q[pback++] = V;
}

int Graph::queue::front() {
	return q[pfront];
}

void Graph::queue::pop() {
	pfront++;
}

bool Graph::queue::empty() {
	return ((pback - pfront) == 0);
}

Graph::Graph() {
	N = 0;
	M = 0;
	for (int i = 0; i <= __MAX_GRAPH_SIZE__; i++) {
		for (int j = 0; j <= __MAX_GRAPH_SIZE__; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i <= __MAX_GRAPH_SIZE__; i++) {
		isCreated[i] = false;
	}
}

void Graph::addVertex(int V) {
	if (V <= 0 || V > __MAX_GRAPH_SIZE__) {
		throw "The incorrect vertex of the graph!";
	}
	if (isCreated[V]) {
		throw "This vertex of the graph has already been created!";
	}
	N++;
	isCreated[V] = true;
}

void Graph::delVertex(int V) {
	if (V <= 0 || V > __MAX_GRAPH_SIZE__) {
		throw "The incorrect vertex of the graph!";
	}
	if (!isCreated[V]) {
		throw "You cannot delete a graph vertex that has not been added before!";
	}
	N--;
	isCreated[V] = false;
	for (int i = 1; i <= __MAX_GRAPH_SIZE__; i++) {
		matrix[V][i] = 0;
		matrix[i][V] = 0;
	}
}

void Graph::addEdge(int V1, int V2) {
	if (V1 <= 0 || V2 <= 0 || V1 > __MAX_GRAPH_SIZE__ || V2 > __MAX_GRAPH_SIZE__) {
		throw "One of the vertices of the graph is incorrect!";
	}
	if (matrix[V1][V2] != 0) {
		throw "This edge has already been added to the graph!";
	}
	if (!isCreated[V1]) {
		this->addVertex(V1);
	}
	if (!isCreated[V2]) {
		this->addVertex(V2);
	}
	M++;
	matrix[V1][V2] = 1;
	matrix[V2][V1] = 1;
}

void Graph::delEdge(int V1, int V2) {
	if (V1 <= 0 || V2 <= 0 || V1 >= __MAX_GRAPH_SIZE__ || V2 >= __MAX_GRAPH_SIZE__) {
		throw "One of the vertices of the graph is incorrect!";
	}
	if (!isCreated[V1] || !isCreated[V2]) {
		throw "One of the incident vertices of the graph does not exist!";
	}
	if (matrix[V1][V2] == 0) {
		throw "This edge is missing from the graph!";
	}
	M--;
	matrix[V1][V2] = 0;
	matrix[V2][V1] = 0;
}

int Graph::getDist(int V1, int V2) {
	if (V1 <= 0 || V2 <= 0 || V1 >= __MAX_GRAPH_SIZE__ || V2 >= __MAX_GRAPH_SIZE__) {
		throw "One of the vertices of the graph is incorrect!";
	}
	if (!isCreated[V1] || !isCreated[V2]) {
		throw "One of the incident vertices of the graph does not exist!";
	}
	int dists[__MAX_GRAPH_SIZE__ + 1];
	for (int i = 1; i <= __MAX_GRAPH_SIZE__; i++) {
		dists[i] = -1;
	}
	dists[V1] = 0;
	queue q; q.push(V1);
	while (!q.empty()) {
		int curr_V = q.front();
		q.pop();
		for (int next_V = 1; next_V <= __MAX_GRAPH_SIZE__; next_V++) {
			if (matrix[curr_V][next_V] && dists[next_V] == -1) {
				dists[next_V] = dists[curr_V] + 1;
				q.push(next_V);
			}
		}
	}
	return dists[V2];
}