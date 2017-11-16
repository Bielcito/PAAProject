#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

#include "Tree.h"

int main()
{
    Tree a = Tree();
    Tree b = Tree();

    // Defining with matrix:
    vector< vector<int> > m (3, vector<int>(3, 0));
    m[0][1] = 5;
    m[0][2] = 10;
    m[1][2] = 3;

    a.defineMatrix(m, 3);

    // Get min tree:
    vector<int> min = a.minTree();

    return 0;
}
