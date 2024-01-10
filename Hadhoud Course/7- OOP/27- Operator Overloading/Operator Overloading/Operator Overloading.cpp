#include <iostream>

using namespace std;



// Operator Overloading is a way to implement the polymorphism.

// https://www.programiz.com/cpp-programming/operator-overloading
// https://www.geeksforgeeks.org/operator-overloading-c/


// ( ++ and -- ) overloading
class clsCount
{

private:
	int _Number;

public:

	// Constructor to initialize the _Number
	constexpr clsCount() : _Number(0) {}
	constexpr clsCount(int n) : _Number(n) {}

	// ++ operator prefix overloading
	constexpr clsCount& operator ++ ()
	{
		++_Number;
		return *this;
	}

	// ++ operator postfix overloading
	constexpr clsCount operator ++ (int)
	{
		_Number++;
		return *this;
	}


	// -- operator prefix overloading
	constexpr clsCount operator -- ()
	{
		--_Number;
		return *this;
	}

	// -- operator postfix overloading
	constexpr clsCount operator -- (int)
	{
		_Number--;
		return *this;
	}

	void Print() const
	{
		std::cout << "\nCount = " << _Number << std::endl;
	}

	friend std::ostream& operator << (std::ostream& Out, const clsCount &C) {
		Out << C._Number;
		return Out;
	}

};


//==============================================================================

// ( + and - ) overloading
class clsComplex
{
private:
	double _real, _imag;

public:
	clsComplex() : _real(0.0), _imag(0.0) {}
	clsComplex(double real, double imag) : _real(real), _imag(imag) {}

	void setvalues(const double real, const double imag)
	{
		_real = real;
		_imag = imag;
	}

	// + operator overloading
	clsComplex& operator + (const clsComplex& Obj)
	{
		_real += Obj._real;
		_imag += Obj._imag;
		return *this;
	}

	// - operator overloading
	clsComplex& operator - (const clsComplex& Obj)
	{
		_real -= Obj._real;
		_imag -= Obj._imag;
		return *this;
	}

	void Print(const char* MSG = "") const
	{
		std::cout << MSG << _real << " + " << _imag << 'i' << std::endl;
	}

};



int main()
{
	clsCount Count;

	Count.Print();

	Count++;
	Count.Print();

	++Count;
	Count.Print();

	Count--;
	Count.Print();

	--Count;
	Count.Print();


	cout << "\n\n==================================================================================\n\n";

	clsComplex Complex1, Complex2, Sum;

	Complex1.setvalues(5.4, 7.6);
	Complex1.Print("The Complex1 Number = ");

	Complex2.setvalues(2.8, 1.8);
	Complex2.Print("The Complex2 Number = ");

	cout << "\n";

	Sum = Complex1 + Complex2;
	Sum.Print("The Sum Number = ");


	return 0;
}