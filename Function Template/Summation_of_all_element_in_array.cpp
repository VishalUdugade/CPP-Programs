#include<iostream>
#include<cstdlib>


class student
{
private:
   int s_marks;
public:
	student(int initmarks = 0):s_marks(initmarks){}

	student& operator+(const student& other)
	{
		this->s_marks = this->s_marks + other.s_marks;
		return *this;
	}

   /* student& operator=(const student& other)
    {
    	this->s_marks = other.s_marks;
    	return *this;
    }*/
	friend std::ostream& operator<<(std::ostream& os, const student& other);
};

std::ostream& operator<<(std::ostream& os,const student& other)
{
	os << other.s_marks << std::endl;
	return os;
}

template <typename T>
void Sum(T* p_arr, int size ,char* msg)
{
	int i = 0;
	T sum = 0;
    
    for(i = 0; i < size; i++)
    {
    	sum = sum + p_arr[i]; 
    }

    show<T>(sum,msg);
}

template <typename T>
void show(T sum, char* msg)
{
     std::cout << msg << sum << std::endl;
}


const int size = 6;
int main()
{
	
	int i_arr[size] = {10,20,30,40,50,60};
	double d_arr[size] = {33.44,34.553,76.433,3.353,99.303,22.453};

	/*student s_arr[size] = {
		                     student("vishal",34),
		                     student("om",45),
		                     student("sahil",30),
		                     student("nikita",55),
		                     student("mohit",64),
		                     student("atul",77)
	                       };*/

	student s_arr[size] = {
		                     student(34),
		                     student(45),
		                     student(30),
		                     student(55),
		                     student(64),
		                     student(77)
	                       };

    Sum<int>(i_arr,size,"Sum of Integer array = ");
    
    Sum<double>(d_arr,size,"Sum of Float array = ");

    Sum<student>(s_arr,size,"Sum of Student marks = ");

    return 0;
}



