/*
breadth first search

*/


#include <iostream>
#include <vector>
#include <queue>
#include <string>

	
//Create the node data structure
class Node {
public:
	//Name of the node
	std::string name;

	//children of the node which will be stored in a vector of Node pointers
	std::vector<Node*> children;

	//Parameterized constructor
	//pass in the name of the node
	Node(std::string nameOfNode);


	//Add a child to a node
	//Give the child a name and push it into the vector of children
	Node* addChild(std::string nameOfNode);


	//Breadth first search method. BTS
	//We want to return a string with all of the nodes in BTS order
	//We are passing in the string array with all the nodes in it
	std::vector<std::string> breadthFirstSearch(std::vector<std::string>* array);

};



Node::Node(std::string nameOfNode) {

	name = nameOfNode;
}


Node* Node::addChild(std::string nameOfNode) {

	//Create a new node
	//passing in the name of the node in the parameterized constructor
	Node* child = new Node(nameOfNode);

	//Once the child is created, push it into the children vector of parent node
	//Children in this case, will be from the CALLER, so children.push_back
	//is the parent pushing the node into their children vector
	children.push_back(child);

	//Once we do this, we want to return back to parent (caller) so we return this
	return this;

}


std::vector<std::string> Node::breadthFirstSearch(std::vector<std::string>* array) {

	//Create a string for the results
	std::vector<std::string> results;

	//The first thing we want to do is implement the queue that will be used for BTS
	//The queue needs memory addresses of nodes
	std::queue<Node*> BTSqueue;

	//Pushes the starting node into the queue
	BTSqueue.push(this);

	//Continues to iterate until the queue is empty
	while (!BTSqueue.empty()) {

		//push the name of the node that is next in the queue into the result string
		results.push_back(BTSqueue.front()->name);
		std::cout << "inserted, " << BTSqueue.front()->name << " into results" << std::endl;

		//Push the node's children into the queue
		//Use a for loop to iterate through each one
		//we need the size of the children vector
		for (int i = 0; i < BTSqueue.front()->children.size(); i++) {

			//push each child into the queue
			BTSqueue.push(BTSqueue.front()->children[i]);
		}

		//After pushing all of the children, pop the node from the queue
		BTSqueue.pop();
	}


	//return the vector with all of the names
	return results;


	//Time O(V+E) -> O(N)
	//Space O(V) -> holding the verticies in the queue
	//also O(V) since we are returning a vector of V

}

