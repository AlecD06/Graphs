//Programmer: Alec Dady
//Lab: 15
//Section: 004L
//Date: April 27th, 2017
//Description: A program that manipulates graphs.
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
/******************************** node *****************************/
class node
{
public:
	int data;
	node *next;
	node() {
		next = NULL;
	}
	~node() {
		delete next;
	}
	int getdata() {
		if (next != NULL)
			return data;
		else
			return 0;
	}
	node(int v) {
		data = v;
	}

	
};
/******************************************* list ***********************/
class list
{
public:
	node *head, *tail;

	list()
	{
		head = NULL;
		tail = NULL;
	}
	/* node* findnode(int value);
	void listinsertafter(node* curnode, int v);
	void listappend(int);
	void listprepend(int value);
	void listremove(node *n);
	void print();
	int getlength();
	bool empty(list *l);
	list sort(list*);
	void addback(node *n);
	void addfront(node *n);
	list backwards(list*);

	bool operator ==(list);

	*/

	node* gethead() {
		return head;
	}

	/************************************************************/
	list backwards(list *l) {
		node *temp = head;
		list *newl = new list;

		while (temp != NULL) {

			newl->listprepend(temp->data);
			temp = temp->next;

		}
		return *newl;
	}


	/************************************************************************/
	node* findnode(int value)
	{

		node* q = head;
		while (q != NULL && q->data != value) {
			q = q->next;
		}

		return q;
	}


	/****************************************/
	void listinsertafter(node* curnode, int v) {

		node* newnode = new node; //create new node
		newnode->data = v;  //input data
		newnode->next = NULL;
		node* temp = new node;
		if (head == 0) { // list empty
			head = newnode;
			tail = newnode;
		}
		else if (curnode == tail) { // insert after tail
			tail->next = newnode;
			tail = newnode;
		}
		else {
			temp = curnode->next;
			newnode->next = curnode->next;
			curnode->next = newnode;
			newnode->next = temp;
		}
	}

	/*******************************************/
	void listremove(node *n) {
		node *curr = head;
		node *temp = head;
		while (curr != NULL) {

			if (n == head)

				head = curr->next;


			else
				if (curr->next == n) {
					curr->next = n->next;
				}
				else {
					temp = curr;
					curr = curr->next;
				}

		}
		if (n == tail)
			delete tail;
		temp->next = NULL;
		tail = temp;


	}

	/**************************************************************************************/

	void listappend(int value) {
		list* l = new list;
		node* n = new node; //create new node
		n->data = value;  //input data
		n->next = NULL;     //set node to point to NULL

		if (head == NULL) { // list empty

			head = n;
			tail = n;

		}
		else {
			tail->next = n;
			tail = n;

		}
		return;


	}

	/**********************************************/

	bool operator ==(list l) {

		node *n = new node;
		n = head;
		node *m = new node;
		m = l.head;

		if (getlength() != l.getlength()) return false;
		else {

			while (n->next != NULL) {
				cout << "here" << endl;
				if (n->data != m->data) {
					return false;
				}
				else {

					n = n->next;
					m = m->next;
				}

			}
			return true;
		}

	}



	/************************************************************************/
	void print() {
		node* current = head;

		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
	}
	/************************************************************************/
	void listprepend(int value) {
		node* newnode = new node;
		newnode->data = value;  //input data
		newnode->next = NULL;     //set node to point to NULL
		if (head == 0) { // list empty
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}
	/************************************************************************/
	int getlength() {
		node *curr = head;
		int count = 0; //account for the head
		while (curr != NULL)
		{
			count = count + 1;
			curr = curr->next;
		}
		return count;
	}
	/*****************************************************************************/

	/*******************************************************************************/
	bool empty() {
		if (this->getlength() == 0)
			return true;
		else
			return false;

	}

	/********************************************************************************/

	list sort(list* li) {
		node *curr = head;
		list *l = new list;
		node *temp = head;
		node *min = head;

		while (curr != NULL) {
			temp = curr->next;
			min = curr;
			while (temp != NULL) {
				if (temp->data <= min->data) {
					min = temp;
				}

				temp = temp->next;

			}
			l->listappend(min->data);
			li->listremove(min);
			curr = head;
		}

		return *l;
	}


	/*****************************************************/
	void addback(node *n) {
		node *curr = head;

		if (head == 0)
		{
			head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
	}
	/****************************************************/

	void  addfront(node *n) {
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}


};


///***************************************** GRAPH CLASS *******************************************/
class graph {
private:
	int size;
	list *vertices;
	vector<list*> edges;
	vector <list*> con;
	vector<list*> weights;
	vector<list*> sorted;
	
public:
/// CONSTRUCTOR
	graph(int s) {
		size = s;
		vertices = new list;

	}
	//RETURN DATA OF A NODE
	int getdat(int i, int j) {
		node* curr = con.at(i)->gethead();
		int k = 0;
		while (k < j) {
			curr = curr->next;
			k++;
		}
		return curr->data;
	}

//SET VERTICES
	void setvertices()
	{

		for (int i = 0; i < size; i++) {
			vertices->listappend(i);
		}
	}

//RETURN SIZE OF GRAPH
	int getsize() {
		return size;
	}

//ADD EDGES
	void addedge(int i) {
		list *l = new list;
		list *w = new list;
			if (i == 0) 
			{
			w->listappend(4);
			w->listappend(8);
			l->listappend(1);
			l->listappend(4);

			edges.push_back(l);
			weights.push_back(w);
		
		}
		if (i == 1) {
			w->listappend(4);
			w->listappend(9);
			w->listappend(8);
			w->listappend(10);
			l->listappend(0);
			
			l->listappend(2);
			l->listappend(6);

			l->listappend(3);
		
			edges.push_back(l);
			weights.push_back(w);
		
		}
		if (i == 2) {
			w->listappend(9);
			w->listappend(1);
			w->listappend(2);
			w->listappend(8);
			l->listappend(1);
		
			l->listappend(4);
			l->listappend(6);

			l->listappend(0);
				
			edges.push_back(l);
			weights.push_back(w);
		
		}

		if (i == 3) {
			w->listappend(10);
			w->listappend(6);
			w->listappend(5);
			w->listappend(7);
			l->listappend(1);
			l->listappend(5);
			l->listappend(4);
			l->listappend(6);
			edges.push_back(l);
			weights.push_back(w);
		
		}
		if (i == 4) {
			w->listappend(1);
			w->listappend(9);
			w->listappend(5);
			w->listappend(5);
			l->listappend(2);
			l->listappend(6);
			l->listappend(3);
			l->listappend(5);
			
			weights.push_back(w);
        	edges.push_back(l);
		
		}

		if (i == 5) {
			w->listappend(2);
			w->listappend(6);
			l->listappend(4);
			
			l->listappend(3);

			weights.push_back(w);
			edges.push_back(l);


		}
		if (i == 6)
		{
			w->listappend(9);
			w->listappend(7);
			w->listappend(8);
			w->listappend(2);
			l->listappend(4);
			l->listappend(3);
			l->listappend(1);
			l->listappend(2);
			edges.push_back(l);
			weights.push_back(w);
		}

	}
	list sort(list* li) {
		node *curr = li->head;
		list *l = new list;
		node *temp = li->head;
		node *min = li->head;

		while (curr != NULL) {
			temp = curr->next;
			min = curr;
			while (temp != NULL) {
				if (temp->data <= min->data) {
					min = temp;
				}

				temp = temp->next;

			}
			l->listappend(min->data);
			li->listremove(min);
			curr = li->head;
		}

		return *l;
	}
	int numEdges()
	{
		int count = 0;
		for (int i = 0; i < edges.size(); i++)
		{
			count += edges[i]->getlength();
		}
		return count/2;
	}

//CONNECT EDGES	
	void connectededges() {

		int i = 0;
		while (i < size) {
			list *conn = new list;
			for (int j = 0; j < size; j++) {

				if (edges.at(i)->findnode(j) != NULL) {

					conn->listappend(1);
				}
				else
					conn->listappend(0);
			}
			con.push_back(conn);

			i++;
		}

	}
/// CHECK IF TWO NODES ARE ADJACENT
	bool isconnected(int i, int j) {
		bool flag = false;
		if (this->getdat(i, j) == 1) return true;
		else return false;
	}

	///PRINT VERTICES
	void printvertices() {
		vertices->print();
	}
	//PRINT EDGES
	void printedges() {
		for (int i = 0; i < size; i++) {

			edges.at(i)->print();
			cout << endl;
		}
	}
	void printweights() {
		for (int i = 0; i < size; i++) {

			weights.at(i)->print();
			cout << endl;
		}
	}
	///PRINT ADJACENCY MATRIX
	void printconn() {
		for (int i = 0; i < size; i++) {
			con.at(i)->print();
			cout << endl;
		}
	}
//BFS SEARCH

	void bfs(int s) {

		bool *visited = new bool[size + 1];
		queue<int> q;

		for (int i = 0; i < size; i++) {
			visited[i] = false;

		}

		q.push(s);
		visited[s] = true;
		while (!q.empty()) {

			int u = q.front();
			cout << u << " ";
			q.pop();

			for (int i = 0; i < size; i++) {
				if ((isconnected(u, i) == 1) && (visited[i] == false))
				{
					q.push(i);
					visited[i] = true;

				}
			}

		}
	}


	/***************************************dfs ****************************************/
	void dfs(int s) {
		bool *visited = new bool[size + 1];
		stack<int> st;
		for (int i = 0; i < size; i++) {
			visited[i] = false;

		}

		st.push(s);
		visited[s] = true;
		while (!st.empty()) {

			int u = st.top();
			cout << u << " ";
			st.pop();
			for (int i = 0; i < size; i++) {
				if ((isconnected(u, i) == 1) && (visited[i] == false))
				{
					st.push(i);
					visited[i] = true;

				}

			}
		}
	}
	int getMin(list *l)
	{
		
		node *currentNode = l->head;
		int min = l->gethead()->data;
		while(currentNode != l->tail)
		{
			if (min > currentNode->next->data)
			{
				min = currentNode->next->data;
			}
			currentNode = currentNode->next;
		}
		return min;
	}
	int getMinEdges()
	{
		int min = getMin(weights.at(0));
		for (int i = 1; i < weights.size(); i++)
		{
			if (min > getMin(weights.at(i)))
			{
				min = getMin(weights.at(i));
			}
		}
		return min;
	}
	vector<list*>sortEdges()
	{
		for (int i = 0; i < weights.size(); i++)
		{
			list *l = new list;
			*l = weights[i]->sort(weights.at(i));
			sorted.push_back(l);
		}
		return sorted;
	}
	void printSorted()
	{
		sortEdges();
		for (int i = 0; i < sorted.size(); i++)
		{
			sorted.at(i)->print();
			cout << endl;

		}
	}
	
}; //END CLASS



/******************************MIAN ***********************/
int main()
{

	graph g(7);
	
	

	g.setvertices();
	cout << "The vertices are: " << endl;
	g.printvertices();
	cout << endl;
	cout << endl;
	

	g.addedge(0);
	g.addedge(1);
	g.addedge(2);
	g.addedge(3);
	g.addedge(4);
	g.addedge(5);
	g.addedge(6);
	
	
	cout << "Edges are: " << endl;
	g.printedges();

	g.connectededges();
	cout << endl;
	cout << "Adjacency Matrix is: " << endl;

	g.printconn();
	cout << endl;
	cout << "Weights are: " << endl;
	g.printweights();

	cout << "Amount of Edges: " << g.numEdges() << endl;
	cout << "Minimum: " << g.getMinEdges() << endl;
	cout << "Sorted: " << endl;
	g.printSorted();

	

	/*cout<<"BFS traversal is: "<<endl;
	g.bfs(1);
	cout<<endl;
	cout << endl;
	cout << "DFS traversal is: " << endl;
	g.dfs(1);
	cout << endl;*/
}
/*OUTPUT
The vertices are:
0 1 2 3 4 5 6

Edges are:
1 4
0 2 6 3
1 4 6 0
1 5 4 6
2 6 3 5
4 3
4 3 1 2

Adjacency Matrix is:
0 1 0 0 1 0 0
1 0 1 1 0 0 1
1 1 0 0 1 0 1
0 1 0 0 1 1 1
0 0 1 1 0 1 1
0 0 0 1 1 0 0
0 1 1 1 1 0 0

Weights are:
4 8
4 9 8 10
9 1 2 8
10 6 5 7
1 9 5 5
2 6
9 7 8 2
Amount of Edges: 12
Minimum: 1
Sorted:
4 8
4 8 9 10
1 2 8 9
5 6 7 10
1 5 5 9
2 6
2 7 8 9
Press any key to continue . . .*/