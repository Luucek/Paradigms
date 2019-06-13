#include <iostream>
#include <vector>
#include <complex>
#include <math.h>

class Wartosci {
	int a, b, c;

	void wyswietl_wartosci() {
		std::cout << "Wartosci:" << std::endl <<
			"a: " << this->a << " b: " << this->b << " c: " << this->c << std::endl;
	}
	void wyswietl_rownanie();
public:
	Wartosci(int a = 0, int b = 0, int c = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
		wyswietl_wartosci();
		wyswietl_rownanie();
	}
	int pobierz_wartosc(char n) {
		if (n == 'a')
			return this->a;
		else if (n == 'b')
			return this->b;
		else if (n == 'c')
			return this->c;
	}
};

class Kwadratowe {
protected:
	std::vector<int> daneWejsciowe;
	std::vector<std::complex<double>> daneWyjsciowe;
	double delta;

	virtual void oblicz_delte();
public:
	void pobierz_wartosci(Wartosci &obj);
	virtual void oblicz_pierwiastki();
	virtual void wyswietl_pierwiastki();
	void wyswietl_delte();
};

class Dwukwadratowe : public Kwadratowe {
	void oblicz_sume();
	void oblicz_roznice();
	void oblicz_iloczyn();

	void oblicz_delte();
public:
	void oblicz_pierwiastki();
	void wyswietl_pierwiastki();
	void wykonaj_dzialania();

	~Dwukwadratowe() {
		daneWyjsciowe.clear();
	}
};

void Wartosci::wyswietl_rownanie() {
	std::cout << "Rownanie:" << std::endl;
	if (a == 0 && b == 0 && c == 0) {
		std::cout << "0\n";
		system("pause");
		exit(0);
	}
	else
	{
		if (a == 0 && b == 0 && c > 0) {
			std::cout << c << "=0\n";
			std::cout << "Falsz\n";
			system("pause");
			exit(0);
		}

		if (a == 0)
			;
		else if (a == 1)
			std::cout << "x^4";
		else
			std::cout << a << "x^4";

		if (b > 1)
			std::cout << "+" << b << "x^2";
		else if (b == 0)
			;
		else if (b == 1)
			std::cout << "+x^2";
		else
			std::cout << b << "x^2";

		if (c > 0)
			std::cout << "+" << c << "=0";
		else if (c == 0)
			std::cout << "=0";
		else
			std::cout << c << "=0";
		std::cout << std::endl;
	}
}

void Kwadratowe::oblicz_delte()
{
}

void Kwadratowe::pobierz_wartosci(Wartosci &obj) {
	daneWejsciowe.push_back(obj.pobierz_wartosc('a'));
	daneWejsciowe.push_back(obj.pobierz_wartosc('b'));
	daneWejsciowe.push_back(obj.pobierz_wartosc('c'));
}

void Kwadratowe::oblicz_pierwiastki()
{
}

void Kwadratowe::wyswietl_pierwiastki()
{
}

void Kwadratowe::wyswietl_delte() {
	std::cout << this->delta << std::endl;
}

void Dwukwadratowe::oblicz_delte() {
	if (daneWejsciowe[0] != 0)
		delta = (daneWejsciowe[1] * daneWejsciowe[1]) - (4 * daneWejsciowe[0] * daneWejsciowe[2]);
	else
		delta = 0 - (4 * daneWejsciowe[1] * daneWejsciowe[2]);
}

void Dwukwadratowe::oblicz_pierwiastki() {

	double x1, x2, pdelta;
	double x1r, x2r, x3r, x1u, x2u, x3u;

	oblicz_delte();
	pdelta = sqrt(abs(delta));
	double a = daneWejsciowe[0], b = daneWejsciowe[1], c = daneWejsciowe[2];

	std::complex<double> temp2;

	if (a == 0) {
		if (delta > 0) {
			x1r = pdelta / (2 * b);
			daneWyjsciowe.push_back(std::complex<double>(x1r, 0));
			x2r = -x1r;
			daneWyjsciowe.push_back(std::complex<double>(x2r, 0));
		}
		else {
			x1u = pdelta / (2 * b);
			daneWyjsciowe.push_back(std::complex<double>(0, x1u));
			x2u = -x1u;
			daneWyjsciowe.push_back(std::complex<double>(0, x2u));
		}
	}
	else {
		if (delta > 0) {
			x1 = (-b - pdelta) / (2 * a);
			if (x1 > 0) {
				x1r = sqrt(x1);
				daneWyjsciowe.push_back(std::complex<double>(x1r, 0));
				x2r = -x1r;
				std::complex<double> x2(x2r, 0);
				daneWyjsciowe.push_back(std::complex<double>(x2r, 0));
			}
			else {
				x1u = sqrt(-x1);
				std::complex<double> x1(0, x1u);
				daneWyjsciowe.push_back(x1);
				daneWyjsciowe.push_back(conj(x1));
			}

			x2 = (-b + pdelta) / (2 * a);
			if (x2 > 0) {
				x3r = sqrt(x2);
				std::complex<double> x3(x3r, 0);
				daneWyjsciowe.push_back(x3);
				daneWyjsciowe.push_back(-x3);
			}
			else {
				x3u = sqrt(-x2);
				std::complex<double> x3(0, x3u);
				daneWyjsciowe.push_back(x3);
				daneWyjsciowe.push_back(conj(x3));
			}
		}
		else if (delta == 0) {
			x1 = -b / (2 * a);
			if (x1 >= 0) {
				x1r = sqrt(x1);
				daneWyjsciowe.push_back(std::complex<double>(x1r, 0));
				x2r = -x1r;
				daneWyjsciowe.push_back(std::complex<double>(x2r, 0));
			}
			else {
				x1u = sqrt(-x1);
				daneWyjsciowe.push_back(std::complex<double>(0, x1u));
				x2u = -x1u;
				daneWyjsciowe.push_back(std::complex<double>(0, x2u));
			}
		}
		else {
			x1 = -b / (2 * a);
			x2 = -pdelta / (2 * a);
			double tmp = sqrt((x1*x1) + (x2*x2));
			x1r = sqrt((tmp + x1) / 2);
			x3r = -x1r;
			x1u = sqrt((tmp - x1) / 2);

			std::complex<double> x1(x1r, x1u);
			daneWyjsciowe.push_back(x1);
			daneWyjsciowe.push_back(conj(x1));
			std::complex<double> x3(x3r, x1u);
			daneWyjsciowe.push_back(x3);
			daneWyjsciowe.push_back(conj(x3));
		}
	}
}

void Dwukwadratowe::oblicz_sume() {
	double rzeczywiste = daneWyjsciowe.at(0).real();
	double urojone = daneWyjsciowe.at(0).imag();
	for (int i = 1; i < daneWyjsciowe.size(); i++) {
		rzeczywiste += daneWyjsciowe.at(i).real();
		urojone += daneWyjsciowe.at(i).imag();
	}
	std::cout << "Suma rzeczywiste: " << rzeczywiste << std::endl
		<< "Suma urojone: " << urojone << std::endl;
}

void Dwukwadratowe::oblicz_roznice() {
	double rzeczywiste = daneWyjsciowe.at(0).real();
	double urojone = daneWyjsciowe.at(0).imag();
	for (int i = 1; i < daneWyjsciowe.size(); i++) {
		rzeczywiste -= daneWyjsciowe.at(i).real();
		urojone -= daneWyjsciowe.at(i).imag();
	}
	std::cout << "Roznica rzeczywiste: " << rzeczywiste << std::endl
		<< "Roznica urojone: " << urojone << std::endl;
}

void Dwukwadratowe::oblicz_iloczyn() {
	double rzeczywiste = daneWyjsciowe.at(0).real();
	double urojone = daneWyjsciowe.at(0).imag();

	for (int i = 1; i < daneWyjsciowe.size(); i++) {
		rzeczywiste *= daneWyjsciowe.at(i).real();
		urojone *= daneWyjsciowe.at(i).imag();
	}
	std::cout << "Iloczyn rzeczywiste: " << rzeczywiste << std::endl
		<< "Iloczyn urojone: " << urojone << std::endl;
}

void Dwukwadratowe::wykonaj_dzialania() {
	oblicz_sume();
	oblicz_roznice();
	oblicz_iloczyn();
}

void Dwukwadratowe::wyswietl_pierwiastki() {
	std::cout << "Pierwiastki rownania dwukwadratowego:" << std::endl;
	for (int i = 0; i < daneWyjsciowe.size(); i++)
		std::cout << daneWyjsciowe[i] << std::endl;
}

int main() {
	Wartosci w1(0, 2, 3);
	Dwukwadratowe *w2 = new Dwukwadratowe();
	w2->pobierz_wartosci(w1);
	w2->oblicz_pierwiastki();
	w2->wyswietl_pierwiastki();
	w2->wykonaj_dzialania();
	w2->~Dwukwadratowe();
	system("pause");
}
