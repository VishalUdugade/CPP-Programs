#include<iostream>

class Unary
{
	private:
	   int x;
	public:
	   Unary(int initx = 0):x(initx){}

	   Unary operator++() // Pre-Increment.
	   {
            ++x;
            return Unary(x);
	   }

	   Unary operator--() // Pre-Decrement.
	   {
	        --x;
	        return Unary(x);
	   }

	   Unary operator++(int) // Post-Increment
	   { 
             Unary tmp(x);
             x = x + 1;
             return tmp;
	   }

	   Unary operator--(int) // Post-Decrement
	   { 
             Unary tmp(x);
             x = x - 1;
             return tmp;
	   }

	   void show(const char* msg)
	   {
	   	   std::cout << msg << x << std::endl;
	   }
};

int main()
{
	Unary obj(20);
    Unary num;

    obj.show("\nBefore Pre-Increment x = ");
    num = ++obj;
    obj.show("\nAfter Pre-Increment x = ");


    obj.show("\nBefore Pre-Decrement x = ");
    num = --obj;
    obj.show("\nAfter Pre-Decrement x = ");


    obj.show("\nBefore Post-Increment x = ");
    num = obj++;
    obj.show("\nAfter Post-Increment x = ");


    obj.show("\nBefore Post-Decrement x = ");
    num = obj--;
    obj.show("\nAfter Post-Decrement x = ");

	return 0;
}