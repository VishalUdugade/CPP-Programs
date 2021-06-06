#include<iostream>
using namespace std;

class range
{
private:
	int start = 0, r_end = 0;
public:
	range(int init_s = 0, int init_e = 0):start(init_s),r_end(init_e){}

	class iterator
	{
         private:
         	int n;
         public:
         	iterator(int init_n):n(init_n){}

         	iterator operator++()
         	{
         		return ++n;
         	}

         	iterator operator--()
         	{
         		return --n;
         	}

         	int operator*(){
		     	return n; 
		    }

         	bool operator!=(const iterator& other)
         	{
         		return (this->n != other.n);
         	}
	};

	iterator begin()
	{
		return iterator(start);
	}

	iterator end()
	{
		return iterator(r_end);
	}

};


int main()
{
	range R(10,20);

	for(range::iterator iter = R.begin(); iter != R.end(); ++iter)
	{
		std::cout << "*iter = " << *iter << std::endl;
	}

	return 0;
}

