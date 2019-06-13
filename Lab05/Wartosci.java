package lab05;

public class Wartosci {
	int a, b, c;

	Wartosci(int setA, int setB, int setC) {
		a = setA;
		b = setB;
		c = setC;
		wyswietl_wartosci();
		wyswietl_rownanie();
	}

	void wyswietl_wartosci() {
		System.out.println("Wartosci:\na: " + a + " b: " + b + " c: " + c);
	}

	void wyswietl_rownanie() {
		System.out.println("Rownanie:");
		if (a == 0 && b == 0 && c == 0) {
			System.out.println("0");
			System.exit(0);
		} else {
			if (a == 0 && b == 0 && c > 0) {
				System.out.println(c + "=0");
				System.out.println("Falsz");
				System.exit(0);
			}

			if (a == 0)
				;
			else if (a == 1)
				System.out.printf("x^4");
			else
				System.out.printf(a + "x^4");

			if (b > 1)
				System.out.printf("+" + b + "x^2");
			else if (b == 0)
				;
			else if (b == 1)
				System.out.printf("+x^2");
			else
				System.out.printf(b + "x^2");

			if (c > 0)
				System.out.printf("+" + c + "=0");
			else if (c == 0)
				System.out.printf("=0");
			else
				System.out.println(c + "=0");
			System.out.println("");
		}
	}

	int pobierz_wartosc(char n) {
		if (n == 'a')
			return a;
		else if (n == 'b')
			return b;
		else if (n == 'c')
			return c;
		return 0;
	}

	public static void main(String[] args) {
		Wartosci w1 = new Wartosci(0, 2, 3);
		Dwukwadratowe w2 = new Dwukwadratowe();
		w2.pobierzWartosci(w1);
		w2.obliczPierwiastki();
		w2.wyswietlPierwiastki();
		w2.wykonajDzialania();
	}
}
