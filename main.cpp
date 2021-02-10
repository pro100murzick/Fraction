#include <iostream>

using namespace std;

class Fraction {
private:
	int _a;
	int _b;
public:
	Fraction() { _a = _b = 1; }
	Fraction(int a, int b);
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
	Fraction operator+(int num);
	friend Fraction operator+(int num, Fraction obj);
	Fraction operator-(Fraction obj);
	bool operator==(Fraction obj);
	bool operator>(Fraction obj);
	double toDouble() { return (double)_a / (double)_b; }
};

Fraction::Fraction(int a, int b)
{
	if (a < 0 && b < 0) {
		_a = -a; _b = -b;
		return;
	}
	else if (b < 0) {
		_a = -a; _b = -b;
		return;
	}
	_a = a; _b = b;
}

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

Fraction Fraction::operator+(int num)
{
	Fraction tmp;
	tmp._b = this->_b;
	int a = num * tmp._b;
	tmp._a = a + this->_a;
	return tmp;
}

Fraction Fraction::operator-(Fraction obj)
{
	Fraction tmp;
	int commonB = getLCM(this->_b, obj._b);
	int a1 = commonB / this->_b * this->_a;
	int a2 = commonB / obj._b * obj._a;
	tmp._a = a1 - a2;
	tmp._b = commonB;
	return tmp;
}

bool Fraction::operator==(Fraction obj)
{
	Fraction tmp1 = *this;
	tmp1.reduction();
	Fraction tmp2 = obj;
	tmp2.reduction();
	if (tmp1._b == tmp2._b && tmp1._a == tmp2._a)
		return true;
	else
		return false;
}

bool Fraction::operator>(Fraction obj)
{
	Fraction tmp1 = *this;
	tmp1.reduction();
	Fraction tmp2 = obj;
	tmp2.reduction();
	int commonB = getLCM(this->_b, obj._b);
	int a1 = commonB / this->_b * this->_a;
	int a2 = commonB / obj._b * obj._a;
	tmp1._b = tmp2._b = commonB;
	tmp1._a = a1;
	tmp1._a = a2;
	if (tmp1._a > tmp2._b)
		return true;
	else
		return false;
}

Fraction operator+(int num, Fraction obj)
{
	Fraction tmp;
	tmp._b = obj._b;
	int a = num * tmp._b;
	tmp._a = a + obj._a;
	return tmp;
}

int main() {
	Fraction a(5, 6);
	Fraction b(6, 8);
	a.toString();
	b.toString();
	cout << " this is primer " << endl;
	Fraction c = a * b;
	c.toString();
	c.reduction();
	c.toString();
	cout << " this is * " << endl;
	c = a / b;
	c.toString();
	c.reduction();
	c.toString();
	cout << " this is / " << endl;
	c = a + b;
	c.toString();
	c.reduction();
	c.toString();
	cout << " this is + " << endl;
	c = a - b;
	c.toString();
	c.reduction();
	c.toString();
	cout << " this is - " << endl;
	Fraction d(3, 5);
	d.toString();
	if (a > d) {
		cout << "Grater" << endl;
	}
	else {
		cout << "Leser" << endl;
	}
	Fraction f(2, 3);
	//c = f + 2;
	//c.toString();
	c = 2 + f;
	c.toString();
	cout << c.toDouble() << endl;
	return 0;
}
