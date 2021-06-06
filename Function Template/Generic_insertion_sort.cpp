#include<iostream>
#include<cstdlib>

class Date
{
private:
	int day, month, year; 
public:
	Date(int init_d = 0,int init_m = 0,int init_y = 0):day(init_d),month(init_m),year(init_y){}

	Date& operator=(const Date& other)
	{
		this->year = other.year;
		this->month = other.month;
		this->day = other.day;
		return *this;
	}

	bool operator>(const Date& other)
	{
		if(this->year > other.year)
			return true;
		else if(this->year < other.year)
			return false;
		else if(this->month > other.month)
			return true;
		else if(this->month < other.month)
			return false;
		else if(this->day > other.day)
			return true;
		else if(this->day < other.day)
		    return false;
		else
		    false; 

	}

	friend std::ostream& operator<<(std::ostream& os,const Date& other);
};

std::ostream& operator<<(std::ostream& os, const Date& other)
{
	os << other.day << "-" << other.month << "-" << other.year;
	return os;
}

template <typename T>
void insertion_sort(T* p_arr,const int size)
{   
	int i,j;
	T key;

    for(j = 1; j <size; j++)
    {
    	key = p_arr[j];
    	i = j - 1;

    	while(i > -1 && p_arr[i] > key)
        {
        	p_arr[i+1] = p_arr[i]; 
			i = i - 1; 
        }
    	
    	p_arr[i+1] = key;
    }
}


template <typename T>
void show(T* p_arr, const int size, const char* msg)
{
	std::cout << msg <<std::endl;

	for(int i=0 ; i < size; i++)
	{
		std::cout << "A[" << i << "]:" << p_arr[i] << std::endl;
	}
}


const int size = 6;
int main()
{
    int iarr[size] = {34,46,45,12,13,96};
    float farr[size] = {45.36,25.69,47.82,12.30,72.14,66.21};

    Date d_arr[size] = {
    	                        Date(23, 4, 2021),
								Date(23, 8, 2021), 
								Date(23, 2, 2020),
								Date(4, 7, 2020), 
								Date(12, 1, 1975)

                        };

    show<int>(iarr,size,"Before sorting Integer array = ");
    insertion_sort<int>(iarr,size);
    show<int>(iarr,size,"After sorting Integer array = ");

    show(farr,size,"Before sorting float array = ");
    insertion_sort(farr,size);
    show(farr,size,"After sorting float array = ");


    show(d_arr,size,"Before sorting Date array is = ");
    insertion_sort(d_arr,size);
    show(d_arr,size,"After sorting Date array is = ");

	return 0;
}

