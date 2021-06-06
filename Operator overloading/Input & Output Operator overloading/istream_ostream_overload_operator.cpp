#include <iostream>

class Student{
	private:
			int roll;
			float marks, attnd;

	public:
			Student(int st_roll = 0, float st_marks = 0.0 , float st_attnd = 0.0) : roll(st_roll),
																					marks(st_marks),
																					attnd(st_attnd)
			{

			}

			friend std::ostream& operator<<(std::ostream&, const Student&);
			friend std::istream& operator>>(std::istream&, Student&);//don't make Student constant 'const Student&' because we want to modify object of Student& st
};

std::ostream& operator<<(std::ostream& os, const Student& st){
	os << "Roll Number:" << st.roll << std::endl
		<< "Marks:" << st.marks << std::endl
		<< "Attendance:" << st.attnd << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Student& st){
	std::cout << "Enter roll:";
	is >> st.roll;
	std::cout << "Enter Marks:";
	is >> st.marks;
	std::cout << "Enter Attendance:";
	is >> st.attnd;
	return is;
}

int main(){
	Student st1;

	std::cin >> st1;
	std::cout << st1;

	return (0);
}
