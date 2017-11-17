#include "Tree.h"

Tree::Tree()
{

}

void Tree::defineVector(vector<int> v)
{
    this->size = v.size();
    for(int i = 0; i < v.size(); ++i)
    {

    }
}

void Tree::defineMatrix(vector< vector<int> > m, unsigned size)
{
    this->m = m;
	this->size = size;
    this->marked = vector< vector<int> >(size, vector<int>(size, 0));
}

string Tree::toString()
{
    string result = "";

    for(int i = 0; i < this->size; ++i)
    {
        for(int j = 0; j < this->size; ++j)
        {
            result += to_string(this->m[i][j]) + " ";
        }

        result += "\n";
    }
    
    return result;
}

string Tree::markedToString()
{
	string result = "";

    for(int i = 0; i < this->size; ++i)
    {
        for(int j = 0; j < this->size; ++j)
        {
            result += to_string(this->marked[i][j]) + " ";
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
		bool hasLoop = this->hasLoop();

        if(edge.size() != 0)
        {
			cout << edge[0] << " " << edge[1] << endl;
        }
		// Fim da execução:
		else
		{
			cout << "cabou" << endl;
			cout << this->markedToString() << endl;
			return edge;
		}
    }

    return vector<int>(2, 0);
}

/**
 * Retorna as coordenadas linha e coluna da menor aresta do grafo, marcando que ela foi pega no this->marked;
 * */
vector<int> Tree::getMinEdge()
{
    vector<int> a(2, 0);
    int row, col;
	int* min = NULL;

    for(unsigned i = 0; i < this->size; ++i)
    {
        for(unsigned j = i+1; j < this->size; ++j)
        {
            if(this->marked[i][j] != 0)
            {
                continue;
            }
            if(this->m[i][j] > 0 && (!min || this->m[i][j] < *min))
            {
                min = &this->m[i][j];
                a[0] = i;
                a[1] = j;
            }
        }
    }

	if(a[0] == 0 && a[1] == 0)
	{
		return vector<int>();
	}
	else
	{
		this->marked[a[0]][a[1]] = 1;
		return a;
	}
}

bool Tree::hasLoop()
{
	vector<int> nonvisited(this->size);
	for(unsigned i = 0; i < this->size; ++i)
	{
		nonvisited[i] = i;
	}

	vector<int> visited;
	vector<int> stack;

	stack.push_back(nonvisited.back());
	while(!stack.empty())
	{
		visited.insert(visited.begin(), stack.back());
		stack.insert(stack.begin(), )
		stack.pop_back();
	}
	nonvisited.pop_back();
}
