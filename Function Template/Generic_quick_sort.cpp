#include<iostream>
#include<cstdlib>

class Date
{
private:
	int day,month,year;
public:
	Date(int init_d = 0,int init_m = 0,int init_y = 0):day(init_d),month(init_m),year(init_y){}

	Date& operator=(const Date& other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}

	bool operator<=(const Date& other)
	{
		if(this->year < other.year)
			return true; 
		else if(this->year > other.year)
			return false; 
		else
		{
			if(this->month < other.month)
				return true; 
			else if(this->month > other.month)
				return false; 
			else
			{
				if(this->day <= other.day)
					return true; 
				else
					return false; 
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& os,const Date& other);

};

std::ostream& operator<<(std::ostream& os, const Date& other)
{
	os << other.day << "-" << other.month << "-" << other.year; 
	return os; 
} 


template <typename T> 
void quick_sort(T *a, int p, int r){
	int q; 
	if(p < r){
		q = partition<T>(a, p, r); 
		quick_sort<T>(a, p, q-1); 
		quick_sort<T>(a, q+1, r); 
	}
}

template <typename T>
int partition(T *a, int p, int r){
	int i; 		
	int j; 		 
	T pivot; 	
	T tmp; 	

	pivot = a[r]; 
	i = p - 1; 
	for(j=p; j < r; j++){
		if(a[j] <= pivot){
			i = i + 1; 
			tmp = a[i]; 
			a[i] = a[j]; 
			a[j] = tmp; 
		}
	}
	tmp = a[i+1]; 
	a[i+1] = a[r]; 
	a[r] = tmp; 
	return (i+1); 
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
    double doarr[size] = {45.36,25.69,47.82,12.30,72.14,66.21};

    Date d_arr[size] = {
    	                        Date(23, 4, 2021),
								Date(23, 8, 2021), 
								Date(23, 2, 2020),
								Date(4, 7, 2020), 
								Date(12, 1, 1975),
                                Date(4,5,2021)
                        };

    show<int>(iarr, size, "Integer array:Before sort:"); 
	quick_sort<int>(iarr, 0, size-1); 
	show<int>(iarr, size, "Integer array:After sort:"); 

	show(doarr, size, "Double array:Before sort:"); 
	quick_sort(doarr, 0, size-1); 
	show(doarr, size, "Double array:After sort:"); 

	show(d_arr, size, "Date Array:Before sort:"); 
	quick_sort(d_arr, 0, size-1); 
	show(d_arr, size, "Date Array:After sort:");

	return 0;
}


