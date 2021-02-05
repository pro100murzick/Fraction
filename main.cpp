#include <iostream>

using namespace std;

class Fraction {
	private:
		int _a;
		int _b;
	public:
		Fraction() { _a = _b = 1; }
		Fraction(int a, int b) { _a = a; _b = b; }
		~Fraction() {};
		void setA(int a) { _a = a; }
		void setB(int b) { _b = b; }
		int setA() { return _a; }
		int setB() { return _b; }
		int getGCD(int b1, int b2);
		int getLCM(int b1, int b2);
		void toString() { cout << _a << "/" << _b << endl; }
		void reduction();
		Fraction operator*(Fraction obj);
		Fraction operator/(Fraction obj);
		Fraction operator+(Fraction obj);
		Fraction operator-(Fraction obj);
};

int Fraction::getGCD(int b1, int b2)
{
	if (b1 < b2) // b1 = max(b1, b2);
		swap(b1, b2);
	while (b2) { // b2 != 0
		b1 = b1 % b2;
		swap(b1, b2);
	}
	return b1;
}

int Fraction::getLCM(int b1, int b2)
{
	return (double)b1 / getGCD(b1, b2) * b2;
}

void Fraction::reduction()
{
	int GCD = getGCD(_a, _b);
	_a /= GCD;
	_b /= GCD;
}

Fraction Fraction::operator*(Fraction obj)
{
	Fraction tmp;
	int a = this->_a * obj._a;
	int b = this->_b * obj._b;
	tmp.setA(a);
	tmp.setB(b);
	return tmp;
}

Fraction Fraction::operator/(Fraction obj)
{
	Fraction tmp;
	int a = this->_a * obj._b;
	int b = this->_b * obj._a;
	tmp.setA(a);
	tmp.setB(b);
	return tmp;
}

Fraction Fraction::operator+(Fraction obj)
{
	Fraction tmp;
	int commonB = getLCM(this->_b, obj._b);
	int a1 = commonB / this->_b * this->_a;
	int a2 = commonB / obj._b * obj._a;
	tmp._a = a1 + a2;
	tmp._b = commonB;
	return tmp;
}

Fraction Fraction::operator$(Fraction obj)
{
	return Fraction();
}

int main() {
	Fraction a(5, 6);
	Fraction b(6, 8);
	a.toString();
	b.toString();
	Fraction c = a * b;
	c.toString();
	c.reduction();
	c.toString();
	c = a / b;
	c.toString();
	c.reduction();
	c.toString();
	c = a + b;
	c.toString();
	return 0;
}
