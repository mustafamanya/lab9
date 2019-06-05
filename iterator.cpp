#include "iterator.h"
#include <iostream>
#include <stack>
#include <iostream>
/*void OperatorIterator::first(){
	if(this->self_ptr!=NULL){
		if(this->self_ptr->get_left()!=NULL){
			this->current_ptr=this->self_ptr->get_left();
		}
		else{
			std::cout<<"erreur 1"<<std::endl;
		}
	}
	else{
		std::cout<<"Left child is NULL"<<std::endl;
	}
}
void OperatorIterator::next(){
	std::cout<<"operatoriterator"<<std::endl;
	if(this->current_ptr!=NULL){
		std::cout<<"if 1"<<std::endl;
		if(this->current_ptr==this->self_ptr->get_left() && (this->self_ptr->get_right()!=NULL)){
			std::cout<<"if 2"<<std::endl;
			this->current_ptr=this->self_ptr->get_right();
		}
		else if(this->current_ptr==this->self_ptr->get_right()){
			std::cout<<"else if"<<std::endl;
			this->current_ptr=NULL;
		}
	}
	else{
		std::cout<<"Already NULL"<<std::endl;
	}
}
void OperatorIterator::first(){
	current_ptr=self_ptr->get_left();
}
void OperatorIterator::next(){
	if(current_ptr==self_ptr->get_left()){
		current_ptr=self_ptr->get_right();
	}
	else{
		if(current_ptr==self_ptr->get_right()){
			current_ptr=NULL;
		}
	}
}
bool OperatorIterator::is_done(){
	bool result=true;
	if(current_ptr!=NULL){
		result=false;
	}
	return result;
}
Base* OperatorIterator::current(){
	return this->current_ptr;
}

/*void UnaryIterator::first(){
	if(this->self_ptr!=NULL){
		if(this->self_ptr->get_left()!=NULL){
			this->current_ptr=this->self_ptr->get_left();
		}
	}
	else{
		std::cout<<"Left child is NULL"<<std::endl;
	}
}

void UnaryIterator::next(){
	if(this->current_ptr==NULL){
		std::cout<<"Already NULL"<<std::endl;
	}
	else{
		this->current_ptr=NULL;
	}
}
void UnaryIterator::first(){
	current_ptr=self_ptr->get_left();
}
void UnaryIterator::next(){
	if(current_ptr==self_ptr->get_left()){
		current_ptr=NULL;
	}
}

bool UnaryIterator::is_done(){
	bool result=true;
	if(this->current_ptr!=NULL){
		result=false;
	}
	return result;
}
Base* UnaryIterator::current(){
	return this->current_ptr;
}

bool NullIterator::is_done(){
	bool result=true;
	return result;
}
Base* NullIterator::current(){
	return NULL;
}
void NullIterator::first(){
	std::cout<<"No child for NullIterator first"<<std::endl;
}
void NullIterator::next(){
	std::cout<<"No child for NullIterator next"<<std::endl;
}

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    	while(!iterators.empty())
	{
		iterators.pop();
    	}
    	Iterator* ite = this->self_ptr->create_iterator();
	ite->first();

    	iterators.push(ite);
}
/*void PreorderIterator::next(){
	Iterator* it=(this->iterators).top()->current()->create_iterator();
	std::cout<<(this->iterators).top()->current()->evaluate()<<std::endl;
	//it->first();
	//(this->iterators).push(it);
	while((this->iterators).size()>0 && !(this->iterators).top()->is_done())
	{
		(this->iterators).top()->first();
		Base* node=((this->iterators).top())->current();
		std::cout<<"bonjour"<<std::endl;
		std::cout<<node->evaluate()<<std::endl;
		(this->iterators).pop();

		if(node->get_right()!=NULL)
		{
			std::cout<<"1 "<<node->get_right()->evaluate()<<std::endl;
			(this->iterators).push(node->get_right()->create_iterator());
		}
		if(node->get_left()!=NULL)
		{
			std::cout<<"2 "<<node->get_left()->evaluate()<<std::endl;
			(this->iterators).push(node->get_left()->create_iterator());
		}*/
		/*if((this->iterators).top()->current()->get_right()!=NULL)
		{
			std::cout<<"1 "<<(this->iterators).top()->current()->get_right()->evaluate()<<std::endl;
		}
		
	}
}*/
/*void PreorderIterator::next() {

	Iterator* it = (this->iterators).top()->current()->create_iterator();
	Iterator* itbis;
	std::cout<<(this->iterators).top()->current()->evaluate()<<std::endl;
	it->first();
	(this->iterators).push(it);
	//for((this->iterators).top()->first();(this->iterators).top()->is_done();(this->iterators).top()->next() )
	while((this->iterators).size() > 0 && !(this->iterators).top()->is_done())
	{
		std::cout<<"bonjour"<<std::endl;
		
		std::cout << (this->iterators).top()->current()->evaluate() << std::endl;
		Base* node=(this->iterators).top()->current();
		while(((this->iterators).top()->current->get_left())!=NULL)
		{
			

		//(this->iterators).top()->next();
		
		//Iterator* it = (this->iterators).top()->current()->create_iterator();
		//it->first();
		 
		//(this->iterators).pop();
	
		
	}
	(this->iterators).pop();

    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
}

void PreorderIterator::next(){
	Iterator* it=(this->iterators).top()->current()->create_iterator();
	it->first();
	(this->iterators).push(it);
	//std::cout<<"entree: "<<(this->iterators).top()->current()->evaluate()<<std::endl;
	while((this->iterators).size()>0 && (this->iterators).top()->is_done()){
		//std::cout<<(this->iterators).top()->current()->evaluate()<<std::endl;
		(this->iterators).pop();
		if((this->iterators).empty()){
			break;
		}
		(this->iterators).top()->next();
	}
}

bool PreorderIterator::is_done() {
	bool flag = false;
	if((this->iterators).empty())
	{
		flag = true;
	}
	return flag;
    // Return true if there are no more elements on the stack to iterate
}

/*Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
    return (this->iterators).top()->current();
    }
Base* PreorderIterator::current(){
	if(this->iterators.size()>0){
		return iterators.top()->current();
	}
	else{
		return NULL;
	}
}*/
void NullIterator::first(){};
void NullIterator::next(){};
bool NullIterator::is_done(){
	return true;
}
Base* NullIterator::current(){
	return NULL;
}

void UnaryIterator::first(){
	current_ptr=self_ptr->get_left();
};
void UnaryIterator::next(){
		current_ptr=NULL;
}
bool UnaryIterator::is_done(){
	if(current_ptr==NULL){
		return true;
	}
	else{
		return false;
	}
}
Base* UnaryIterator::current(){
		return current_ptr;
	
}

void OperatorIterator::first(){
	current_ptr=self_ptr->get_left();
}
void OperatorIterator::next(){
	if(current_ptr==self_ptr->get_left()){
		current_ptr=self_ptr->get_right();
	}
	else
	{
		if(current_ptr==self_ptr->get_right()){
			current_ptr=NULL;
		}
	}
}
bool OperatorIterator::is_done(){
	if(current_ptr!=NULL){
		return false;
	}
	else{
		return true;
	}
}
Base* OperatorIterator::current(){
	return this->current_ptr;
}

void PreorderIterator::first(){
	while(!iterators.empty()){
		iterators.pop();
	}
	Iterator* iter=this->self_ptr->create_iterator();
	iter->first();
	iterators.push(iter);
}
void PreorderIterator::next(){
	Iterator* iter=iterators.top()->current()->create_iterator();
//	iterators.top()->current()->print();
	iter->first();
	iterators.push(iter);
	while(iterators.top()->is_done()){
		//std::cout<<"is done 1 :"<<iterators.top()->is_done()<<std::endl;
		iterators.pop();
		//std::cout<<"test 1"<<std::endl;
		//iterators.top()->current()->print();
		//std::cout<<"test 2"<<std::endl;
		if(this->is_done()){
			//std::cout<<"break"<<std::endl;
			break;
		}
		iterators.top()->next();
		//std::cout<<"test 3"<<std::endl;
		//iterators.top()->current()->print();
		//std::cout<<"fin du while next"<<std::endl;
	}
	//std::cout<<"fin du next"<<std::endl;
}
bool PreorderIterator::is_done(){
	if(iterators.empty()==true){
		return true;
	}
	else{
		return false;
	}
}

Base* PreorderIterator::current(){
	return iterators.top()->current();
	
}

		
