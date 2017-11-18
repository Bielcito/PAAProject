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
		cout << this->markedToString() << endl;
		bool hasLoop = this->hasLoop();

        if(edge.size() != 0)
        {
			cout << edge[0] << " " << edge[1] << endl;
        }
		// Fim da execução:
		else
		{
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
	cout << "início do hasLoop" << endl;
	// Vetor com os vértices não visitados:
	vector<int> unvisited(this->size);
	for(unsigned i = 0; i < this->size; ++i)
	{
		unvisited[i] = i;
	}

	// Vértices já visitados:
	vector<int> visited;

	// Pilha:
	vector<int> stack;

	// Escolhe um vértice não visitado que faça parte da instância, e coloca ele no início da pilha:
	for(unsigned i = 0; i < unvisited.size(); ++i)
	{
		int pivot = unvisited[i];
		for(unsigned j = 0; j < this->size; ++j)
		{
			if(this->marked[j][pivot] == 1)
			{
				stack.insert(stack.begin(), pivot);
				goto minTree;
			}
		}
	}

	minTree:
	cout << "Vértice escolhido: " << stack[0] << endl;

	while(stack.size() > 0)
	{
		// Caso o início da pilha não tiver sido visitado ainda, adiciona os vizinhos do 
		// primeiro da pilha ao fim da pilha e depois remove ele, colocando ele nos visitados.

		// Verifica se o início da pilha já foi visitado, até achar um que não seja:
		while(stack.size() > 0)
		{
			bool isVisited = false;
			for(unsigned i = 0; i < visited.size(); ++i)
			{
				if(stack[0] == visited[i])
				{
					cout << stack[0] << " já visitado." << endl;
					stack.erase(stack.begin());
					isVisited = true;
					break;
				}
			}

			if(!isVisited)
			{
				cout << "Não foi visitado." << endl;
				break;
			}
		}

		if(stack.size() == 0)
		{
			cout << "stack = 0" << endl;
			return false;
		}

		// Aqui temos certeza que o primeiro da pilha ainda não foi visitado.
		// Então adiciona seus vizinhos ao fim da pilha.
		for(unsigned i = 0; i < this->size; ++i)
		{
			// Caso a aresta do início da pilha com o vértice i exista, adiciona i à pilha:
			if(i < stack[0] && this->marked[i][stack[0]] == 1)
			{
				cout << "c1: " << i << " " << stack[0] << endl;
				cout << "Adicionou " << i << " à pilha" << endl;
				stack.push_back(i);
			}
			else if(i > stack[0] && this->marked[stack[0]][i] == 1)
			{
				cout << "c2: " << stack[0] << " " << i << endl;
				cout << "Adicionou " << i << " à pilha" << endl;
				stack.push_back(i);
			}
		}

		// Adiciona o vertice de inicio da pilha aos visitados, e apaga-o da pilha. Repete o processo.
		cout << "Adicionou " << stack[0] << " aos visitados." << endl;
		visited.push_back(stack[0]);
		stack.erase(stack.begin());
	}
}
