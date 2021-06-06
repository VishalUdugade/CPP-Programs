#include<iostream>
#include<cstdlib>

class HasPtr{
	private:
	    int * p ;
	    int n;
	public:
	     HasPtr(int* init_p,int init_n): p(init_p),n(init_n){}


          HasPtr(const HasPtr& other):p(new int(*other.p)),n(other.n){}

          HasPtr& operator=(const HasPtr& other){
          	delete p;//this and other both have a valid pointer
          	p = other.p;
          	n = other.n;
          	return *this;
          }

          
          
	     int    get_n()                {return n;}
	     void    set_n(int new_n)       {n = new_n;}
	     int*   get_p()                {return p;}
	     int    get_p_val()            {return *p;}
         void   set_p_val(int n)       { *p = n;}

    
         friend std::ostream& operator<<(std::ostream& os,const HasPtr& other);
};

std::ostream& operator<<(std::ostream& os,const HasPtr& other){
	//os << "p = " << other.p << std::endl;
	os << "*p = " << *other.p << std::endl;
	os << "n = " << other.n << std::endl;
	return os;
}

int main(){
	HasPtr hp1(new int(100),1000);
    HasPtr hp2(new int(200),2000);
    HasPtr hp3(hp2);

    std::cout << "hp1:" << hp1 << "hp2:" << hp2 << "hp3:" << hp3 << std::endl;
    hp3.set_p_val(250);
    std::cout << hp2 << std::endl;


    HasPtr hp4(new int(300), 3000);
    hp2 = hp4;

    std::cout << "hp1:" << hp1 << "hp2:" << hp2 << "hp3:" << hp3 << "hp4:" << hp4 << std::endl;
    hp3 = hp4;
    hp1 = hp4;
    std::cout << "hp1:" << hp1 << "hp2:" << hp2 << "hp3:" << hp3 << "hp4:" << hp4 << std::endl;
    return(0);
}