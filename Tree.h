#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <vector>
#include <string>
using std::vector;
using std::string;
using std::stoi;

class Tree
{
    public:
        Tree();

    public:
        void defineVector(int* v, int size);
        void defineMatrix(vector< vector <int> >* m, int size);

        string toString();

    private:
        vector< vector<int> >* m;
};

#endif // TREE_H_INCLUDED
