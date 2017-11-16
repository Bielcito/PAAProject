#include "Tree.h"

Tree::Tree()
{

}

void Tree::defineVector(vector<int> v)
{
    this->size = v.size();
    for(int i = 0; i < v.size(); i++)
    {

    }
}

void Tree::defineMatrix(vector< vector<int> > m, unsigned size)
{
    // saving matrix on class:
    this->m = m;

    // creating matrix of marks:
    this->marked = vector< vector<int> >(this->m.size());

    for(unsigned i = 0; i < this->m.size(); i++)
    {
        this->marked[i] = vector<int>(this->m[i].size(), 0);
    }

    this->size = size;
}

string Tree::toString()
{
    string result = "";

    for(int i = 0; i < this->size; i++)
    {
        for(int j = 0; j < this->size; j++)
        {
            result += to_string(this->m[i][j]) + " ";
        }

        result += "\n";
    }
    
    return result;
}

vector<int> Tree::minTree()
{
    while(true)
    {
        vector<int> edge = this->getMinEdge();
        if(edge.size() == 0)
        {
            return edge;
        }

        cout << edge[0] << " " << edge[1] << endl;
    }

    return vector<int>(2, 0);
}

/**
 * Retorna as coordenadas linha e coluna da menor aresta do grafo, marcando que ela foi pega no this->marked;
 * */
vector<int> Tree::getMinEdge()
{
    vector<int> a(2);
    int min, row, col;
    min = this->m[0][1];

    for(int i = 0; i < this->size; i++)
    {
        for(int j = i+1; j < this->size; j++)
        {
            if(this->marked[i][j] != 0)
            {
                continue;
            }
            if(this->m[i][j] < min)
            {
                min = this->m[i][j];
                a[0] = i;
                a[1] = j;
            }
        }
    }

    this->marked[a[0]][a[1]] = true;

    return a;
}
