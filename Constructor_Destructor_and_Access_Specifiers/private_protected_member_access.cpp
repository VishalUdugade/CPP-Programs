#include<cstdio>

class B{
private:
	int private1_of_B;
	int private2_of_B;

protected:
	int protected1_of_B;
	int protected2_of_B;

public:
	B() : private1_of_B(100), private2_of_B(200),protected1_of_B(300),protected2_of_B(400){}
    
    ~B()
    {
    	printf("\nDestructor of class B :\n");
    }
};

class D:public B{
private:
	int private1_of_D;
	int private2_of_D;

public:
	D() : private1_of_D(500),private2_of_D(600){}

	void show(){
		//printf("private1_of_B = %d\n",private1_of_B);
		//printf("private2_of_B = %d\n",private2_of_B);
		printf("protected1_of_B = %d\n",protected1_of_B);
		printf("protected2_of_B = %d\n",protected2_of_B);
		printf("private1_of_D = %d\n",private1_of_D);
		printf("private2_of_D = %d\n",private2_of_D);


	}

    ~D()
    {
    	printf("\nDestructor of Derived class D\n");
    }

};


int main(){
	D *objD = new D();

	objD->show();

    delete objD;
	return 0;
}

