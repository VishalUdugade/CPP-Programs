#include<iostream>

class student
{
private:
   int s_marks;
public:
  student(int initmarks = 0):s_marks(initmarks){}

  bool operator==(const student& other)
  {
    if(this->s_marks == other.s_marks)
      return true;
    else
      return false;
  }

   bool operator>(const student& other)
  {
    if(this->s_marks > other.s_marks)
      return true;
    else
      return false;
  }

};


template <typename T>
int binarySearch(T *p_arr, T x, int low,int high) {
  // Repeat until the pointers low and high meet each other

  //int high = &(p_arr[size - 1]) - p_arr;

  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (p_arr[mid] == x)
      return mid;

    // Search the left half
    if (p_arr[mid] > x)
      return binarySearch(p_arr, x, low, mid - 1);

    // Search the right half
    return binarySearch(p_arr, x, mid + 1, high);
  }

  return -1;
}

void show(int result)
{
    if(result == -1)
    {
      std::cout<<"Not Found"<<std::endl;
    }
    else
    {
      std::cout<< "Element is found at index : " << result << std::endl;
    }
}

const int size = 6;
int main()
{
  
  int i_arr[size] = {10,20,30,40,50,60};
  double d_arr[size] = {33.44,34.553,38.353,22.453,76.433,99.303};

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
                         student(30),
                         student(45),
                         student(55),
                         student(64),
                         student(77)
                         };
    
    //int n = sizeof(i_arr) / sizeof(i_arr[0]);
    int result = binarySearch<int>(i_arr,60,0,size);
    show(result);
   
    //int n = sizeof(i_arr) / sizeof(i_arr[0]);
    result = binarySearch<double>(d_arr,76.433,0,size);
    show(result);

    result = binarySearch<student>(s_arr,45,0,size);
    show(result);
    
    return 0;
}
