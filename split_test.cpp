#include "split.h"
#include <iostream>

int main(){

Node* end = new Node(4, NULL); //must have end to start or else we are calling nodes that do not yet exist
Node* secondlast = new Node(4, end);
Node* thirdlast = new Node(11, secondlast);
Node* fourthlast = new Node(18, thirdlast);
Node* fifthlast = new Node(21, fourthlast);
Node* start = new Node(17, fifthlast);

Node* odds = NULL;
Node* evens = NULL;

// while(start != NULL){ //test that start is what it should be
// 	cout << start->value << endl;
// 	start = start->next;
// }

split(start, odds, evens);

while(odds != NULL){ //print out odds
	std::cout << odds->value << endl;
	odds = odds->next;
}

while(evens != NULL){ //print out evens
	std::cout << evens->value << endl;
	evens = evens->next;
}

delete end; //deleter nodes for memory allocation sake
delete secondlast; //must go end to front so we have a path to follow
delete thirdlast; 
delete fourthlast;
delete fifthlast;
delete start;

return 0;

}