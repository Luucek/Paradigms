package lab05;

public class Dwukwadratowe extends Kwadratowe {

	@Override
	protected void obliczDelte() {
		if (daneWejsciowe.elementAt(0) != 0)
			delta = (daneWejsciowe.elementAt(1) * daneWejsciowe.elementAt(1))
					- (4 * daneWejsciowe.elementAt(0) * daneWejsciowe.elementAt(2));
		else
			delta = 0 - (4 * daneWejsciowe.elementAt(1) * daneWejsciowe.elementAt(2));
	}

	@Override
	public void wyswietlPierwiastki() {
		System.out.println("\nPierwiastki rownania dwukwadratowego:");
		for (int i = 0; i < daneWyjsciowe.size(); i++)
			System.out.println(daneWyjsciowe.elementAt(i));
	}

	@Override
	public void obliczPierwiastki() {

		double x1, x2, pdelta;
		double x1r, x2r, x3r, x1u, x2u, x3u;

		obliczDelte();
		pdelta = Math.sqrt(Math.abs(delta));
		double a = daneWejsciowe.elementAt(0), b = daneWejsciowe.elementAt(1);

		if (a == 0) {
			if (delta > 0) {
				x1r = pdelta / (2 * b);
				daneWyjsciowe.add(new Complex(x1r, 0));
				x2r = -x1r;
				daneWyjsciowe.add(new Complex(x2r, 0));
			} else {
				x1u = pdelta / (2 * b);
				daneWyjsciowe.add(new Complex(0, x1u));
				x2u = -x1u;
				daneWyjsciowe.add(new Complex(0, x2u));
			}
		} else {
			if (delta > 0) {
				x1 = (-b - pdelta) / (2 * a);
				if (x1 > 0) {
					x1r = Math.sqrt(x1);
					daneWyjsciowe.add(new Complex(x1r, 0));
					x2r = -x1r;
					daneWyjsciowe.add(new Complex(x2r, 0));
				} else {
					x1u = Math.sqrt(-x1);
					daneWyjsciowe.add(new Complex(0, x1u));
					daneWyjsciowe.add(new Complex(0, x1u).conjugate());
				}

				x2 = (-b + pdelta) / (2 * a);
				if (x2 > 0) {
					x3r = Math.sqrt(x2);
					daneWyjsciowe.add(new Complex(x3r, 0));
					daneWyjsciowe.add(new Complex(-x3r, 0));
				} else {
					x3u = Math.sqrt(-x2);
					daneWyjsciowe.add(new Complex(0, x3u));
					daneWyjsciowe.add(new Complex(0, -x3u));
				}
			} else if (delta == 0) {
				x1 = -b / (2 * a);
				if (x1 >= 0) {
					x1r = Math.sqrt(x1);
					x2r = -x1r;
					daneWyjsciowe.add(new Complex(x1r, 0));
					daneWyjsciowe.add(new Complex(x2r, 0));
				} else {
					x1u = Math.sqrt(-x1);
					x2u = -x1u;
					daneWyjsciowe.add(new Complex(0, x1u));
					daneWyjsciowe.add(new Complex(0, x2u));
				}
			} else {
				x1 = -b / (2 * a);
				x2 = -pdelta / (2 * a);
				double tmp = Math.sqrt((x1 * x1) + (x2 * x2));
				x1r = Math.sqrt((tmp + x1) / 2);
				x3r = -x1r;
				x1u = Math.sqrt((tmp - x1) / 2);

				daneWyjsciowe.add(new Complex(x1r, x1u));
				daneWyjsciowe.add(new Complex(x1r, x1u).conjugate());
				daneWyjsciowe.add(new Complex(x3r, x1u));
				daneWyjsciowe.add(new Complex(x3r, x1u).conjugate());
			}
		}
	}

	public void wykonajDzialania() {
		obliczSume();
		obliczRoznice();
		obliczIloczyn();
		przeciwne();
		odwrocone();
	}

	private void obliczSume() {
		double rzeczywiste = daneWyjsciowe.elementAt(0).re();
		double urojone = daneWyjsciowe.elementAt(0).im();

		for (int i = 1; i < daneWyjsciowe.size(); i++) {
			rzeczywiste += daneWyjsciowe.elementAt(i).re();
			urojone += daneWyjsciowe.elementAt(i).im();
		}
		System.out.println("\nSuma rzeczywiste: " + rzeczywiste);
		System.out.println("Suma urojone: " + urojone);
	}

	private void obliczRoznice() {
		double rzeczywiste = daneWyjsciowe.elementAt(0).re();
		double urojone = daneWyjsciowe.elementAt(0).im();

		for (int i = 1; i < daneWyjsciowe.size(); i++) {
			rzeczywiste -= daneWyjsciowe.elementAt(i).re();
			urojone -= daneWyjsciowe.elementAt(i).im();
		}
		System.out.println("Roznica rzeczywiste: " + rzeczywiste);
		System.out.println("Roznica urojone: " + urojone);
	}

	private void obliczIloczyn() {
		double rzeczywiste = daneWyjsciowe.elementAt(0).re();
		double urojone = daneWyjsciowe.elementAt(0).im();

		for (int i = 1; i < daneWyjsciowe.size(); i++) {
			rzeczywiste *= daneWyjsciowe.elementAt(i).re();
			urojone *= daneWyjsciowe.elementAt(i).im();
		}
		System.out.println("Iloczyn rzeczywiste: " + rzeczywiste);
		System.out.println("Iloczyn urojone: " + urojone);
	}

	private void przeciwne() {
		System.out.println("\nPierwiastki przeciwne:");
		double xr = 0, xu = 0;
		for (int i = 0; i < daneWyjsciowe.size(); i++) {
			if (daneWyjsciowe.elementAt(i).re() != 0)
				xr = daneWyjsciowe.elementAt(i).re() * -1;
			if (daneWyjsciowe.elementAt(i).im() != 0)
				xu = daneWyjsciowe.elementAt(i).im() * -1;
			System.out.println(xr + " " + xu);
		}
	}

	private void odwrocone() {
		System.out.println("\nPierwiastki odwrocone:");
		double xr = 0, xu = 0;
		for (int i = 0; i < daneWyjsciowe.size(); i++) {
			if (daneWyjsciowe.elementAt(i).re() != 0)
				xr = 1 / daneWyjsciowe.elementAt(i).re();
			if (daneWyjsciowe.elementAt(i).im() != 0)
				xu = 1 / daneWyjsciowe.elementAt(i).im();

			System.out.println(xr + " " + xu);
		}
	}
}
