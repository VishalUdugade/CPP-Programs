#include <cstdio>
#include <cstdlib>

class ITest{
	public:
	   virtual void f1() = 0;
	   virtual void f2() = 0;
	   virtual void f3() = 0;
	   virtual void f4() = 0;
};

class CTest1 : public ITest{
	private:
	   int m, n, k;
	public:
	   void f1() {puts("In CTest1::f1()"); }
	   void f2() {puts("In CTest1::f2()"); }
	   void f3() {puts("In CTest1::f3()"); }
	   void f4() {puts("In CTest1::f4()"); }
};

class CTest2 : public ITest{
	private:
	   int a, b, c, d, e;
	public:
	    void f1() {puts("In CTest2::f1()"); }
	    void f2() {puts("In CTest2::f2()"); }
	    void f3() {puts("In CTest2::f2()"); }
	    void f4() {puts("In CTest2::f2()"); }
};

int main(void)
{
	ITest* pITest = 0;

	pITest = new CTest1;
	pITest->f1();
	pITest->f2();
	pITest->f3();
	pITest->f4();

	delete pITest;
	pITest = 0;

	pITest = new CTest2;
	pITest->f1();
	pITest->f2();
	pITest->f3();
	pITest->f4();

	delete pITest;
	pITest = 0;

	return EXIT_SUCCESS;
}

