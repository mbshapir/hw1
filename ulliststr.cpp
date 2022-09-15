#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if(empty()){ //no where to push back
		Item* node1 = new Item;	//therefore I need to create a new node
		//node1->first = 0;
		//node1->last = 1;
		node1->val[node1->last] = val;
		node1->last++;
	
		//node1 = head_;
		//node1 = tail_;
		head_ = node1;
		tail_ = node1;
		size_++; //new node increase size
		

	}else if(tail_->last == ARRSIZE){//at first, I thought this meant the array was empty, but actuall the list is empty

		Item* replacement = new Item;

		replacement->first = 0; // check if subtracting 10 is right here, ans:not right
		replacement->last = 1;
		replacement->val[replacement->first] = val;

		tail_->next = replacement; //order important, must change next and prev before switching which is head
		replacement->prev = tail_; //no need to change head since original head and tail were already connected
		tail_ = replacement;
		size_++; //new node increase size

	}else{ // there is space to add, and array not empty
		tail_->val[tail_->last] = val;
		tail_->last = tail_->last + 1;
		size_++;
	}

}

void ULListStr::push_front(const std::string& val){
	if(empty()){ //no where to push front and not empty

		Item* node1 = new Item;
		node1->first = ARRSIZE - 1;
		node1->last = ARRSIZE;
		node1->val[node1->first] = val;

		//node1 = head_;
		//node1 = tail_;
		head_ = node1;
		tail_ = node1;
		size_++; //new node increase size
		
	}else if(head_->first == 0 && head_->last != 0){//same as empty list in push_back
		
		Item* replacement = new Item;

		replacement->first = ARRSIZE - 1;
		replacement->last = ARRSIZE;
		replacement->val[replacement->first] = val;

		replacement->next = head_; //no need to change tail since original head and tail were already connected
		head_->prev = replacement; //order important, must change next and prev before switching which is head
		head_ = replacement;
		size_++; //new node increase size

	}else{ // there is space to add, and array not empty
		head_->val[head_->first-1] = val; //array index must be like thi because we have to remember that 
		head_->first = head_->first - 1;
		size_++;
	}

}

void ULListStr::pop_back(){
	if(empty()){
		return;
	}
	//tail_->val[tail_->last-1] = NULL; //remove last value
	tail_->last--; //end one index earlier since last index was removed
	if(tail_->first == tail_->last){ //check if removal of value emptied node, remove node if so
		tail_ = tail_->prev;
		delete tail_->next;
		size_--;
	}
}

void ULListStr::pop_front(){
	if(empty()){
		return;
	}
	//head_->val[head_->first] = NULL; //remove first value
	head_->first++; //start one index later since first was removed
	if(head_->first == head_->last){ //check if removal of value emptied node, remove node if so
		head_ = head_->next;
		delete head_->prev;
		size_--;
	}	
}

std::string const & ULListStr::back() const{
	return tail_->val[tail_->last-1]; //took val out of inside
}

std::string const & ULListStr::front() const{
	return head_->val[head_->first]; //took val out of inside
}

std::string* ULListStr::getValAtLoc(size_t loc) const{

	// int loccopy = loc/10; //number of nodes deep
	// int index = loc%10; //index at correct node
	// Item* copy = new Item;
	// copy = head_;

	// while(loccopy > 0){
	// 	copy = copy->next;
	// 	loccopy--;
	// }
	// return &copy->val[index];
	unsigned int counter = 0;
	int index = head_->first;
	Item* copy = new Item;
	copy = head_;
	while(counter < loc){

		if(copy->val[index] == ""){
			return NULL;
		}
		if(index % (ARRSIZE-1) == 0){
			copy = copy->next;
			index = 0;
		}
		index++;
		counter++;
	}
	return &copy->val[index];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
