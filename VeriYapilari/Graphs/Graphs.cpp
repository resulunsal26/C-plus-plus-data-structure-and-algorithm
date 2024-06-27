#include <iostream>
#include <vector>
#include <map>



using namespace std;


class Graph
{
private:
	map<int, vector<int>> adjList;


public:
	// yeni bir dugum eklemek icin kkullanilan metod
	void addVertex(int vertex)
	{
		// parametre olarak gelen vertex zaten varsa islem yapma , yoksa ekle
		if (adjList.find(vertex)==adjList.end())
		{
			vector<int> neighbors;//komsu dugum listesi olusturuyoruz
			adjList[vertex] = neighbors; // dugumu komsu dugum listesiyle(vector) iliskilendiririz
		}
	}
	
	void addEdge(int from, int to)// yeni bir  kenar (edge) ekleme
	{
		
		addVertex(from);//ilk olarak dugumlere bak�yoruz yoksa ekletiyoruz
		addVertex(to);//ilk olarak dugumlere bak�yoruz yoksa ekletiyoruz

		adjList[from].push_back(to);//adjliste ba�lant� kurduyoruz
		adjList[to].push_back(from);//adjliste ba�lant� kurduyoruz

	}
	void printGraph()
	{
		int numVertices = adjList.size();
		for (int i = 0; i < numVertices; i++)
		{
			int vertex = i;

			auto it = adjList.begin();
			advance(it, vertex); // dizinin indexi verip degere ula�ma



			vector<int>& neighbors = adjList[it->first]; // it->second

			cout << "Adjacen to vertex " << it->first << ": ";

			for (int j = 0; j < neighbors.size(); j++)
			{
				cout << neighbors[j]<<" ";
			}
			cout << endl;
		}
	}
	void removeVertex(int vertex)
	{
		if (adjList.find(vertex) != adjList.end())// silinmek istenen vertex varm� yok mu diye control eder
		{
			adjList.erase(vertex);


			for (map<int,vector<int>>::iterator it=adjList.begin();it !=adjList.end();it++)
			{
				int key = it->first;// dugum anahtari - key
				vector<int>& neighbors = it->second; // dugumun komsulari - value
				vector<int>::iterator vecIt = neighbors.begin();
				while (vecIt != neighbors.end())
				{
					if (*vecIt == vertex)
					{
						vecIt = neighbors.erase(vecIt); // vecIt E�itlemesi yapma sebebimiz erase ilk olarak siler ve bir sonraki iterator d�nd�r�r.
					}
					else
					{
						vecIt++;// burdada bulamazsak art�rma i�ini yap�yoruz
					}
				}
			}
	    }
		
	}
	void removeEdge(int from, int to)
	{
		if (adjList.find(from) != adjList.end()&& adjList.find(to) != adjList.end())// silinmek istenen vertex varm� yok mu diye control eder find bulamaz ise end d�nd�r�r
		{
			vector<int>& fromNeighbors = adjList[from];
			vector<int>& toNeighbors = adjList[to];
			
			for (int i = 0; i < fromNeighbors.size(); i++)
			{
				if(fromNeighbors[i]==to)
				{
					fromNeighbors.erase(fromNeighbors.begin() + i); // i nci elaman� siler
					break; // ilk eslemeyi kald�r�p d�ng�den ��k
				}
			}
			for (int i = 0; i < toNeighbors.size(); i++)
			{
				if (toNeighbors[i] == from)
				{
					toNeighbors.erase(toNeighbors.begin() + i);
					break;
				}
			}

		}
		

	}
};

int main()
{
	Graph g;
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);

	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);


	cout<<"Baslangic Graph:\n";
	g.printGraph();
	cout << endl;
	g.removeVertex(1);
	cout << endl;
	g.printGraph();
	g.removeEdge(2,4);
	cout << endl;
	g.printGraph();

	cout << endl;
	g.addVertex(8);
	g.addEdge(8, 2);
	g.printGraph();

	return 0;
}

/*

graphslarda nodelara vertexte denir  edgelere connection da denir birbirleri �zerine ili�kilerine dikkat eder tek tarafl� olur
�ift tarafl� olur  ve a��rl�klar vard�r
gps ve gaming a� da kullan�l�r social networklerde kullan�l�r mesela tan�yor olabilice�in arkada�larda bu kullan�l�r.
iki arkada��n begendi diye ayn� g�nderiyi sana ��kar�yor

adjacency matr�x

nodelar�n birbirleri ile ba�lant�l� oldu�u yerlere tabloda 1 koyuyo yoksa 0 koyuyor yada ag�rl�klar� koyar

   a  b  c  d  e
a  0  25 0  2  0
b  25 0  5
c
d
e
gibi tablo haz�rlan�r

adjacency l�st

1:2,3
2:1,5,4
gibi liste ��karmaya denir map kullanrak key value yap keyler ayn� olamaz valueler ayn� olur
 �ift tarafl� ise ok kullan�lmaz 
map

key    value
1      2,3
2      1,5,4

*/