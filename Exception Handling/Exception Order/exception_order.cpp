#include <iostream> 
#include <stdexcept> 
#include <typeinfo> 

void f(void); 

int main(void){
	try{
		f(); 
	}catch(std::overflow_error &ref){
		std::cout << "overflow error" << std::endl; 
		std::cout << ref.what() << std::endl; 
	}catch(std::runtime_error& ref){
		std::cout << "runtime error" << std::endl; 
		std::cout << ref.what() << std::endl; 
	}catch(std::exception& ref){
		std::cout << "exception error" << std::endl; 
		std::cout << ref.what() << std::endl; 
		std::exception* pe = &ref; 
		std::cout << typeid(*pe).name() << std::endl; 
	}

	return (0); 
}

void f(){
	throw std::logic_error("LOGIC error exception"); 
}
