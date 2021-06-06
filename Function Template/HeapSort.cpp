// C++ program for implementation of Heap Sort
#include <iostream>

#include <String>

class student
{
private:
   std::string s_name;
   int s_marks;
public:
  student(std::string initname,int initmarks = 0):s_name(initname),s_marks(initmarks){}

   bool operator>(const student& other)
  {
    if(this->s_marks > other.s_marks)
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

using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template <typename T>
void heapify(T* arr, int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if ((l < n) && (arr[l] > arr[largest]))
		largest = l;

	// If right child is larger than largest so far
	if ((r < n) && (arr[r] > arr[largest]))
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
template <typename T>
void heapSort(T* arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
template <typename T>
void printArray(T* arr, int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);

	double d_arr[] = {12.35,45.369,56.103,47.82,73.023,66.24};
    n = sizeof(d_arr) / sizeof(d_arr[0]);

	heapSort(d_arr, n);

	cout << "Sorted array is \n";
	printArray(d_arr, n);

	student s_arr[] = {
                         student("Vishal",34),
                         student("Sahil",92),
                         student("Om",45),
                         student("shubham",81),
                         student("Suraj",5),
                         student("Atul",77)
                      };

    n = sizeof(s_arr) / sizeof(s_arr[0]);  
    
    heapSort(s_arr, n);

    cout << "Sorted array is \n";
	printArray(s_arr, n);

	return 0;

}


