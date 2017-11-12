#include "Tree.h"

Tree::Tree()
{

}

void Tree::defineVector(int* v, int size)
{

}

void Tree::defineMatrix(vector< vector<int> >* m, int size)
{
    this->m = m;
}

string Tree::toString()
{
    string result;
    for(unsigned i = 0; i < this->m->size(); i++)
    {
        for(unsigned j = 0; j < this->m[i].size(); j++)
        {
            result += std::stoi(this->m[i][j]) + " ";
        }

        result += "\n";
    }

    return result;
}

