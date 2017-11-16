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

class Tree
{
    public:
        Tree();

    public:
        void defineVector(vector<int> v);
        void defineMatrix(vector< vector <int> > m, unsigned size);
        vector<int> minTree();

        string toString();

    private:
        unsigned size;
        vector< vector<int> > m;
        vector<int> getMinEdge();

        // 0 - Não visitado.
        // 1 - Visitado e usando.
        // 2 - Visitado mas não pode usar.
        vector< vector<int> > marked;
};

#endif // TREE_H_INCLUDED
