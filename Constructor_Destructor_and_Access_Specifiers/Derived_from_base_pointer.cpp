#include<cstdio>

class Base{
public:
	void f1(){puts("Base::f1()");}
	void f2(){puts("Base::f2()");}

	virtual void f3(){puts("Base::f3()");}
	virtual void f4(){puts("Base::f4()");}
  virtual ~Base(){printf("\nDestructor of Base class\n");}

};

class Derived:public Base{
public:
	void g1() {printf("Derived::g1()\n");}
	void g2() {printf("Derived::g2()\n");}
	void f3() {printf("Derived::f3()\n");} //overriden method
	void f4() {printf("Derived::f4()\n");} //overriden method

  ~Derived()
  {
    printf("\nDestructor of Derived class\n");
  }
};


int main(){
	Base* pB = nullptr;
	pB = new Derived;

    pB->f1();
    pB->f2();
    pB->f3();
    pB->f4();

   // pB->g1(); //not allowed
   // pB->g1(); //not allowed

    reinterpret_cast<Derived*>(pB)->g1(); 
    reinterpret_cast<Derived*>(pB)->g2();
    reinterpret_cast<Derived*>(pB)->f3();//when you make f3 as virtual in base then you need not to use reinterpre_cast call goes to Derived class function
    reinterpret_cast<Derived*>(pB)->f4();//when you make f4 as virtual in base then you need not to use reinterpre_cast call goes to Derived class function
 
     //make f3 and f4 virtual in Base class function
    
    pB->f3();
    pB->f4();

   // B::f3();
  //  B::f4();
    delete pB;

    return 0;

}

