#include "gtest/gtest.h"
#include "composite.h"
#include "iterator.h"
#include "composite.cpp"
#include "iterator.cpp"
#include <string>


	Op* a1 = new Op(4);
	Op* a2 = new Op(2);
	Op* a3 = new Op(15);
	Sqr* C = new Sqr(a1);
	Sub* B = new Sub(C,a2);
	Sub*D=new Sub(a3,a2);
	Add* A = new Add(a3,B);
	Root* r = new Root(A);
	
	/*PreorderIterator* pi = new PreorderIterator(r);
	pi->first();*/
TEST(PreorderIte, Null){
	Root* rt=new Root(NULL);
	NullIterator* Pi=new NullIterator(rt);
	Pi->first();
	EXPECT_EQ(true, Pi->is_done());
}	


TEST(PreorderIte, OneNode){

	Op* a=new Op(4);
	Sqr* X=new Sqr(a);
	Root* R=new Root(X);
	PreorderIterator* ite=new PreorderIterator(R);
	ite->first();
	EXPECT_EQ(16,ite->current()->evaluate());
}
TEST (PreorderIte, OneOperation){
	Root* root=new Root(D);
	PreorderIterator* it= new PreorderIterator(root);
	it->first();
	testing::internal::CaptureStdout();
	it->current()->print();
	it->next();
	it->current()->print();
	it->next();
	it->current()->print();
	std::string output=testing::internal::GetCapturedStdout();
	EXPECT_EQ("-152", output);
}
TEST(PreorderIte, WholeTree){
	PreorderIterator* pi=new PreorderIterator(r);
	pi->first();
	testing::internal::CaptureStdout();
	while(!(pi->is_done())){
		pi->current()->print();
		pi->next();
	}
	std::string out=testing::internal::GetCapturedStdout();
	EXPECT_EQ("+15-^242", out);
}


int main(int argc, char **argv) {
		::testing::InitGoogleTest(&argc, argv);		  	   
		       	return RUN_ALL_TESTS();
}
