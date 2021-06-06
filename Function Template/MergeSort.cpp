// Merge sort in Cpp

#include <iostream>
#include <cstdlib>
#include <string.h>

class student
{
private:
   int s_marks;
public:
  student(int initmarks = 0):s_marks(initmarks){}

  student& operator=(const student& other)
  {
    this->s_marks = other.s_marks;
    return *this;
  }

   bool operator<=(const student& other)
  {
    if(this->s_marks <= other.s_marks)
      return true;
    else
      return false;
  }

  friend std::ostream& operator<<(std::ostream& os,const student& other);

};

std::ostream& operator<<(std::ostream& os,const student& other)
{
   os << other.s_marks << std::endl;
   return os;
}


template <typename T>
// Merge two subarrays L and M into arr
void merge(T* arr, int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  const int n1 = q - p + 1;
  const int n2 = r - q;

  //int L[n1], M[n2];

  T* L = new T(n1);
  T* M = new T(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }

  delete(L);
  delete(M);
}

template <typename T>
// Divide the array into two subarrays, sort them and merge them
void mergeSort(T* arr, int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge<T>(arr, l, m, r);
  }
}

template <typename T>
// Print the array
void printArray(T* arr, int size) {
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << std::endl;
}

// Driver program
int main() {
  int i_arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(i_arr) / sizeof(i_arr[0]);
   
  std::cout << "Before Sorting array :" << std::endl;
  printArray(i_arr, size);
  mergeSort<int>(i_arr, 0, size - 1);
  std::cout << "After Sorting sorted array :" << std::endl;
  printArray<int>(i_arr, size);


  double d_arr[] = {12.35,45.369,56.103,47.82,73.023,66.24};
  int dsize = sizeof(d_arr) / sizeof(d_arr[0]);
   
  std::cout << "Before Sorting array :" << std::endl;
  printArray(d_arr, dsize);
  mergeSort<double>(d_arr, 0, dsize - 1);
  std::cout << "After Sorting sorted array :" << std::endl;
  printArray<double>(d_arr, dsize);

  student s_arr[] = {
                         student(34),
                         student(30),
                         student(45),
                         student(55),
                         student(64),
                         student(77)
                         };

   int ssize = sizeof(s_arr) / sizeof(s_arr[0]);
  std::cout << "Before Sorting array :" << std::endl;
  printArray(s_arr, ssize);
  mergeSort<student>(s_arr, 0, ssize - 1);
  std::cout << "After Sorting sorted array :" << std::endl;
  printArray<student>(s_arr, ssize);

  return 0;
}

