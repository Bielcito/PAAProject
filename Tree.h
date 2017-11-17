#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::to_string;
using std::cin;

class Tree
{
    public:
        Tree();

    public:
        void defineVector(vector<int> v);
        void defineMatrix(vector< vector <int> > m, unsigned size);
        vector<int> minTree();

        string toString();
		string markedToString();

    private:
        unsigned size;
        vector< vector<int> > m;
        vector<int> getMinEdge();
		bool hasLoop();

		// 0 - Non visited;
		// 1 - Visited and Used;
		// 2 - Visited and not used;
        vector< vector<int> > marked;
};

#endif // TREE_H_INCLUDED
