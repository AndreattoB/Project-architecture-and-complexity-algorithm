/* Algorithm BFS
======================= SUMMARY =======================
graph ----------->  grafo em forma de lista de adjacencia 
current_vertex -->  vertice atual da fila
visited --------->  vetor para identificar os vertices visitados, sendo 'N' para NO e 'Y' para YES
distance -------->  distance entre o vertice atual e o vertice inicial
queue_vertex ---->  fila de vertices que precisam ser visitados (vizinhos dos que ja foram visitados)
start ----------->  vertice inicial
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector <int> > graph; // Criando a lista de adjacência 

vector<int> BFS (int start){ // Entra com um vertice qualquer inicial e retorna um vetor
	int current_vertex = 0, i = 0;
	
	vector<int> father(graph.size(), -1); // Vetor para armazena o pai de cada vertice.
    vector<char> visited(graph.size(), 'N'); // Vetor para identificar o vertice já visitado 
 	vector<int> distance(graph.size(), -1); // Vetor da distancia minima para alcancar o vertice
 	
	queue<int> queue_vertex; // Fila para definir a ordem de manipulacao dos vertices
	
	distance[start] = 0; // Define a distancia do vertice inicial para ele mesmo
	visited[start] = 'Y'; // Define que o vertice inicial já foi visitado
	queue_vertex.push(start); // Coloca o vertice inicial dentro da Fila
	
	while(!queue_vertex.empty()){ // enquanto a fila nao estiver vazia faca
		current_vertex = queue_vertex.front(); // Coloca o primeiro da fila numa variavel para manipular
		queue_vertex.pop(); // Retira o primeiro da fila
		
		for(i = 0; i < graph[current_vertex].size(); i++){ // Para verificar todo vertice adjacente
			
			if(visited[graph[current_vertex][i]] == 'N'){ // Caso o vertice nao tenha sido visitado ainda
				
				queue_vertex.push(graph[current_vertex][i]); // Enfileira o vertice adjacente
				visited[graph[current_vertex][i]] = 'Y'; // Define que o vertice foi visitado
				distance[graph[current_vertex][i]] = distance[current_vertex]+1; // Acrescenta na distancia entre o vertice atual e o analisado
				father[graph[current_vertex][i]] = current_vertex; // adiciona o pai do vertice
			}
		}
		
	}
	
	return father; 
}


int main(){
	
	vector <int> distance_vertex;
	vector <int> father_vertex;
	int reserve_graph;
	int list_adja;
	int vertex_start;
	int A, B;
 	int current_vertex=0;
 	
    cout << "Quantidade de vertices: "; cin >> reserve_graph; // Quantidade de vertices
	cout << "Tamanho da lista: "; cin >> list_adja; // lista de adjacencia considerando a ida e volta, ou seja, o numero de arestas multiplicado por 2
	cout << "vertice inicial: "; cin >> vertex_start; //Vertice no qual quer iniciar o BFS
	
	
    graph.resize(reserve_graph); // definindo o tamanho de acordo com os vertices     
    
    for(int i = 0; i < list_adja; i++){  //Criando a lista de adjacencia 
        cout << "Vertice A: ";
		cin >> A;
		cout << "Vertice B: ";
        cin >> B;
        graph[B].push_back(A);      
     	graph[A].push_back(B);
    }
      
    father_vertex = BFS(vertex_start);
    
/*	Exibir os pais de cada vertice	
	cout<<"fathers: "<<endl;
	for (int i=0; i<father_vertex.size(); i++){
		cout<<"Vertice: "<<i<<"  Pai: "<<father_vertex[i]<<endl;
	}
*/

// Abaixo está a representação do grafo em lista de adjacencia
	int size_graph = graph.size();
	cout<<endl<<"Lista de adjacencia"<<endl<<endl; 
	for (int i = 0; i < size_graph; i++){
		cout << i << " > ";
		for (int j = 0; j < size_graph; j++){
			if(father_vertex[j] == i){
				cout << j;	
				if(j+1 < size_graph){ 
					cout << " --> ";
				}
			}
		}
		cout<<endl;
	}
	
	return 0;	
}
