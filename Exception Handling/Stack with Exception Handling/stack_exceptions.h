#ifndef _STACK_H
#define _STACK_H

#include<iostream>
#include <stdexcept>

class is_empty_stack:public std::runtime_error
{
	public:
	   is_empty_stack(): std::runtime_error("Stack is empty")
	   {

	   }
};

class stack_data_not_found: public std::runtime_error
{
	public:
       stack_data_not_found(): std::runtime_error("Data is Not Found in Stack")
       {

       }
};

class neg_size : public std::runtime_error
{
    public:
        neg_size() : std::runtime_error("Size Cannot be Negative or Zero")
        {

        }
};

class stack_full : public std::runtime_error
{
    public:
        stack_full() : std::runtime_error("Stack is Full")
        {

        }
};

#endif _STACK_H


