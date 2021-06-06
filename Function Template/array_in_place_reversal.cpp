#include<iostream>

class Date
{
private: 
	int day, month, year; 
public: 
	Date(int init_day = 0, int init_month = 0, int init_year = 0) : day(init_day), 
																	month(init_month), 
																	year(init_year)
	{

	}

	Date& operator=(const Date& other)
	{
		this->day = other.day; 
		this->month = other.month; 
		this->year = other.year; 
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
		else
			return false; 
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& other); 

};

std::ostream& operator<<(std::ostream& os, const Date& other)
{
	os << other.day << "-" << other.month << "-" << other.year; 
	return os; 
} 

template <typename T>
void ArrayinPlaceReversal(T* p_arr,int size)
{
	int i, j; 
	T key; 	 

	for(j = 1; j < size; ++j)
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
void show(T* p_arr, int size,const char* msg)
{
	 std::cout << msg << std::endl;

	 for(int i = 0 ; i < size ; i++)
	 {
	 	std::cout << "A[" << i << "]=" <<  p_arr[i] << std::endl;
	 }
}


const int a_size = 5; 

int main(){
	int ia[a_size] = {50, 40, 30, 20, 10}; 
	double da[a_size] = {5.5, 5.05, 5.005, 5.0005, 5.00005}; 
	Date date_arr[a_size] = {
								Date(11, 1, 2021),
								Date(11, 5, 2021), 
								Date(11, 2, 2020),
								Date(10, 2, 2020), 
								Date(1, 1, 1970) 

							}; 

	show<int>(ia, a_size, "Integer array:Before sort:"); 
	ArrayinPlaceReversal<int>(ia, a_size); 
	show<int>(ia, a_size, "Integer array:After sort:"); 

	show(da, a_size, "Double array:Before sort:"); 
	ArrayinPlaceReversal(da, a_size); 
	show(da, a_size, "Double array:After sort:"); 

	show(date_arr, a_size, "Date Array:Before sort:"); 
	ArrayinPlaceReversal(date_arr, a_size); 
	show(date_arr, a_size, "Date Array:After sort:"); 

	return (0); 
}