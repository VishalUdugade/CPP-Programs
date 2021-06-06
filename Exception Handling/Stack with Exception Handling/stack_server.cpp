#include <iostream>

#include "stack.h"
#include "stack_exceptions.h"

stack::stack(int stack_size)
{
	if(stack_size <= 0)
	   throw neg_size();

	p_array = new int[stack_size];
	this->stack_size = stack_size;
	top_index = -1;
}


ret_t stack::push(data_t new_data)
{
	if(top_index + 1 == stack_size)
	   throw stack_full();

	p_array[++top_index] = new_data;
	return(SUCCESS);
}

ret_t stack::pop(data_t* p_poped_data)
{
	if(top_index == -1)
	  throw is_empty_stack();

	*p_poped_data = p_array[top_index--];
	return (SUCCESS);
}

bool stack::is_empty()
{
	return (top_index == -1);
}

bool stack::find_data(data_t f_data)
{
	if(is_empty() == true)
	   throw is_empty_stack();

	for(int i = 0; i < stack_size; i++)
	{
	     if(p_array[i] == f_data)
	        return true;
	}

	throw stack_data_not_found();  
   return false;
}

stack::~stack()
{
	delete p_array;
}

std::ostream& operator<<(std::ostream& os,const stack& ref_obj)
{
	cout << "[start]<->";
	for(int i = 0; i <= ref_obj.top_index ; i++)
	    cout << "[" << ref_obj.p_array[i] << "]<->" ;

	 cout << "[end]" ;
     return os;
}

