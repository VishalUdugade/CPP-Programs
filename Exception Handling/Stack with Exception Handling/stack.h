#include<iostream>
#include "stack_exceptions.h"
#include<stdexcept>
using namespace std;


const int SUCCESS   = 1;


typedef int ret_t;
typedef int data_t;
typedef int len_t;


class stack
{
private:
	int* p_array;
	int stack_size;
	int top_index;
public:
    stack(int stack_size);
    ret_t push(data_t new_data);
    ret_t pop(data_t* p_poped_data);
    bool is_empty();
    bool find_data(data_t f_data);
    ~stack();

    friend std::ostream& operator<<(std::ostream& ,const stack& ref_obj);
  	
};


