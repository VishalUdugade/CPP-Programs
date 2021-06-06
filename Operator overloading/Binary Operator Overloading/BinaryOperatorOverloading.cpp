#include<iostream>

class Binary
{
private:
	long int x , y;
public:
	Binary(long int initx = 0, long int inity = 0):x(initx),y(inity){}

	Binary operator+(const Binary& other)
	{
        return Binary(this->x + other.x , this->y + other.y);
	}

	Binary operator-(const Binary& other)
	{
		return Binary(this->x - other.x , this->y - other.y);
	}

	Binary operator*(const Binary& other)
	{
		return Binary(this->x * other.x, this->y * other.y);
	}

	Binary operator/(const Binary& other)
	{
		return Binary(this->x / other.x, this->y / other.y);
	}

	void show(const char* msg)
	{
		std::cout << msg << "x = " << this->x << " " << "y = " << this->y << std::endl;
	}
	
};

int main()
{
	Binary *obj1 = new Binary(15,10);

	Binary *obj2 = new Binary(5,2);

	Binary result = *obj1 + *obj2;
    result.show("addition : ");

	result = *obj1 - *obj2;
	result.show("Subtraction : "); 

    result = (*obj1) * (*obj2);
	result.show("Multiplication : "); 

    result = (*obj1) / (*obj2);
	result.show("Division : ");
 	
    return 0;
}