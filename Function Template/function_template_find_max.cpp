#include <iostream>
#include <cstdlib>

void test1();
//function Template
template <typename T>
T funmax(T a, T  b)
{
	if(a > b)
		return a;
	else
		return b;
}


int main()
{
	int init1 = 10, init = 20;
	float flt1 = 30.98 , flt2 = 21.44;

	test1();

	//following ways to call template function.
    //Case 1 - 
	int max_int = funmax(12,45);
	float max_float = funmax(44.32,21.54);
	double max_double = funmax(3.443,5.322);
	char max_char = ('D','p');
    
    std::cout<<"Maximum Integer value : " << max_int <<std::endl;
    std::cout<<"Maximum Float value: " <<max_float <<std::endl;
    std::cout<<"Maximum double value: " <<max_double <<std::endl;
    std::cout<<"Maximum char value : " <<max_char <<std::endl;

     //case 2 -

     max_int = funmax<int>(27,11);
	 max_float = funmax<float>(89.65,99.414);
    // max_float = funmax(static_cast<float>(50),99.414);
	// max_double = funmax(3.443,static_cast<double>(45.857));
	
    std::cout<<"Maximum Integer value: " << max_int <<std::endl;
    std::cout<<"Maximum Float value: " <<max_float <<std::endl;
    std::cout<<"Maximum double value: " <<max_double <<std::endl;
    
    return 0;

}

void test1()
{
	//	funmax(100, 101.5); // CTE 

	 double d_max =   funmax(static_cast<double>(100), 101.5);
	 int i_max = funmax(100, static_cast<int>(101.5));
	 double max_double = funmax(3.443 , static_cast<double>(45)); 

	 std::cout<<"Maximum double value: " << d_max <<std::endl;
    std::cout<<"Maximum Float value: " <<i_max <<std::endl;
    std::cout<<"Maximum double value: " <<max_double <<std::endl;
}


