#include "libs.h"
#include "Graph.h"

using namespace std;

int main() {

	try {
		Graph g;

		g.addEdge(1, 2);
		g.addEdge(2, 3);
		g.addEdge(3, 4);
		g.addEdge(2, 4);

		cout << g.getDist(1, 4);
	}
	catch (const char* ErrorMessage) {
		cout << ErrorMessage << '\n';
	}

	return 0;
}