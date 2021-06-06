#include <cstdio>
#include <cstdlib>

struct intptr{
	int *p_int;
	size_t ref_cnt;
};

class HasPtr{
private:
	struct intptr* p_refcounted_ptr;
	int n;
public:
	HasPtr(int int_val, int n){
		this->p_refcounted_ptr = new struct intptr;
		this->p_refcounted_ptr->p_int = new int(int_val);
		this->p_refcounted_ptr->ref_cnt = 1;
		this->n = n;
	}


	/*copy constructor
	  param 1: this pointer: contains address of new but unconstructed object of hasptr

	  param 2: other : refernce to constructec object of HasPtr

	  */

	HasPtr(const HasPtr& other){
		this->p_refcounted_ptr = other.p_refcounted_ptr;
		this->p_refcounted_ptr->ref_cnt = this->p_refcounted_ptr->ref_cnt + 1;
		this->n = other.n;

	}


	/*Overload assignment operator
	  param1: this pointer-> pointer to existing and constructed object of HasPtr
	  param2: other -> reference to existing and constructed objects of HasPtr.

	  */

	HasPtr& operator=(const HasPtr& other){
		this->p_refcounted_ptr->ref_cnt = this->p_refcounted_ptr->ref_cnt - 1;

		if(this->p_refcounted_ptr->ref_cnt == 0){
			 delete this->p_refcounted_ptr->p_int;
			 delete this->p_refcounted_ptr;
		}

		this->p_refcounted_ptr = other.p_refcounted_ptr;
		this->p_refcounted_ptr->ref_cnt = this->p_refcounted_ptr->ref_cnt + 1;

		this->n = other.n;

		return *this;
	}

	/*Destructor */

	~HasPtr(){
		this->p_refcounted_ptr->ref_cnt -= 1;
		if(this->p_refcounted_ptr->ref_cnt == 0){
			delete this->p_refcounted_ptr->p_int;
			delete this->p_refcounted_ptr;
		}
	}

	int get_n(){
		return n;
	}

	void set_n(int new_n){
		n = new_n;
	}

	int get_ptr_val(){
		return *this->p_refcounted_ptr->p_int;
	}

	void set_ptr_val(int new_val){
         *this->p_refcounted_ptr->p_int = new_val;
	}

	size_t get_ref_count(){
		return this->p_refcounted_ptr->ref_cnt;
	};
};


int main(){
	HasPtr* p1= new HasPtr(10,100);
	printf("ref_cnt(p1):%zu\n",p1->get_ref_count());
	HasPtr* p2 = new HasPtr(*p1);
	printf("ref_count(p2):%zu\n",p1->get_ref_count());
	HasPtr* p3 = new HasPtr(*p2);
	printf("ref_count(p3):%zu\n",p1->get_ref_count());

	delete p1;
	p1 = NULL;
	printf("ref_cnt(p2):%zu\n",p2->get_ref_count());

	delete p2;
	p2 = NULL;
	printf("ref_cnt(p3):%zu\n",p3->get_ref_count());

	delete p3;
	p3 = NULL;

	return EXIT_SUCCESS;
}

/*

class T{
	private:
		T1* p1;
		T2* p2;
		T3* p3;
};

In orer to achieve shallow copying

struct T1_ptr{
	T1* p;
	size_t ref_cnt;
};

struct T2_ptr{
	T2* p;
	size_t ref_cnt;
};

struct T3_ptr{
	T3* p;
	size_t ref_cnt;
};

class T must be rewritten as

class T{
	private:
		struct T1_ptr* p1;
		struct T2_ptr* p2;
		struct T3_ptr* p3;
};

repeat struct intptr stratgy in copy control mechanisms
for p1, p2 & p3 in Copy Control mechanisms of class T.

As this strategy is common for all data types, it can be
isolated in class template shared_ptr;

template <typename T>
class shared_ptr{
	private:
		T* p;
		size_t ref_cnt;
};

*/
