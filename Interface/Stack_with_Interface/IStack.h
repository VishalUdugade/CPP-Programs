#ifndef _ISTACK_H
#define _ISTACK_H

const int SUCCESS  = 1;
const int STACK_FULL  = 2;
const int STACK_EMPTY  = 3

/*Interface to stack*/
class IStack{
 public:
 	IStack() {}
 	virtual int push(int new_element) {return SUCCESS;}
 	virtual int pop(int* p_poped_element) {return SUCCESS;}
 	virtual int top(int* p_top_element) {return SUCCESS;}
 	virtual bool is_empty() const {return true;}
 	virtual ~IStack(){}
 	static IStack* get_stack_instance(size_t size);

};
#endif
