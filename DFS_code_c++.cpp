/* Algorithm BFS
======================= SUMMARY =======================
graph ----------->  grafo em forma de lista de adjacencia 
current_vertex -->  vertice atual da fila
visited --------->  vetor para identificar os vertices visitados, sendo para white (2) ele ainda nao foi descoberto, gray (1) ele ja foi descoberto,
					mas os seus descendentes nao foram e black (0) para quando todos os seus descendentes ja foram visitados   
start ----------->  vertice inicial
predecessor ----->  É o vertice antecessor ou pai do vertice que esta sendo descoberto
discovery ------->  É o momento no qual o vertice é descoberto
finish ---------->  É o tempo de termino da descoberta do vertice e dos seus descendentes
time ------------>  Incremento para definir o discovery e o finish
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

map<string,int> color;
vector< vector <int> > graph; // Criando a lista de adjacência 
int *visited; // Definindo se ele 
int *predecessor; // o pai do vertice que esta sendo visitado
int *discovery; // momento de descoberta
int *finish; // tempo de termino do vertice
int time; // tempo total


void initializes(){
	for(int i = 0; i < graph.size(); i++){ // Setando os valores iniciais dos vetores
        visited[i]= color["white"];
        predecessor[i] = -1;
		discovery[i] = 0;
    }
}

void DFS_visit(int current_vertex){ // Verifica se os vertices foram visitados, entrando numa recursividade caso nao tenham sido visitados ainda
	
	visited[current_vertex] = color["gray"]; // setando ele como descoberto
	time++;
	discovery[current_vertex] = time; //Tempo de descoberta do vertice
	
	for(int i = 0; i < graph[current_vertex].size(); i++){ // verificando se seus descendentes ja foram visitados
		if(visited[graph[current_vertex][i]] == color["white"]){
			predecessor[graph[current_vertex][i]] = current_vertex;
            DFS_visit(graph[current_vertex][i]); // recursividade até o ultimo descendente do vertice
		}
	}
	visited[current_vertex] = color["black"];
    finish[current_vertex] = time; // tempo de termino da visita do vertice e seus descendentes
    time++; 
}

void DFS(int start){ // Entra com um vertice qualquer inicial, sendo normalmente zero
	visited = new int[graph.size()]; // definindo o tamanho do vetor de acordo com o tamanho do grafo
	predecessor = new int[graph.size()];
    finish = new int[graph.size()];
    discovery = new int[graph.size()];
    time = -1; // Inicia tempo como -1 por conta do incremento existente na funcao DFS_visit
    
    initializes();
    
    DFS_visit(start);
}

int main(){

	color["white"] = 2; // Quando ainda nao foi descoberto
	color["gray"] = 1; // Quando ja foi descoberto mas seus descendentes nao
	color["black"] = 0; // Quando seus descendentes ja estao pretos

    int reserve_graph;
	int list_adja;
	int vertex_start;
	int A, B;
 	int current_vertex=0;
 	
    cout << "Number of vertices: "; cin >> reserve_graph; // Quantidade de vertices
	cout << "Adjacency list size: "; cin >> list_adja; // lista de adjacencia considerando a ida e volta, ou seja, o numero de arestas multiplicado por 2
	cout << "initial vertex: "; cin >> vertex_start; //Vertice no qual quer iniciar o DFS
	
    graph.resize(reserve_graph); // definindo o tamanho de acordo com os vertices     
    
    for(int i = 0; i < list_adja; i++){  //Criando a lista de adjacencia 
        cout << "Vertex A: ";
		cin >> A;
		cout << "Vertex B: ";
        cin >> B;
        graph[B].push_back(A);      
     	graph[A].push_back(B);
    } 
    DFS(vertex_start);
    
// Abaixo está a representação do grafo com a distancia do vertice i até o vertice inicial e seu pai
   	cout<<"Vertex     Distance to parent     Parent"<<endl;
    for(int i = 0; i < reserve_graph; i++){
        cout<<"   "<<i<<"              "<<discovery[i]<<"                "<<predecessor[i]<<endl<<endl;
    }
    cout<<"Total time: "<<time<<endl;
	
	return 0;
}
