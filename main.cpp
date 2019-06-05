#include "iterator.cpp"
#include "composite.cpp"
#include "composite.h"
#include "iterator.h"

int main(){
	Op* a=new Op(3);
	Op* a1 = new Op(4);
	Op* a2 = new Op(2);
	Op* a3 = new Op(15);
	Add* C = new Add(a,a1);
	Sub* B = new Sub(C,a2);
	Add* A = new Add(B,a3);
	Root* r = new Root(A);
	//std::cout<<A->evaluate();
	PreorderIterator* it= new PreorderIterator(r);
	it->first();
	while(!(it->is_done()))
	{
		//std::cout<<"while 1"<<std::endl;
		it->current()->print();
		std::cout<<" ";
		it->next();
		//std::cout<<"next"<<std::endl;
	}
	PreorderIterator* it2=new PreorderIterator(r);
	it2->first();
	/*while(!(it2->is_done())){
		std::cout<<it2->current()->evaluate()<<std::endl;
		it2->next();
	}*/
	//std::cout<<pi->is_done()<<std::endl;
	return 0;
}
