package lab05;

import java.util.Vector;

public class Kwadratowe {

	Vector<Integer> daneWejsciowe = new Vector<Integer>();
	Vector<Complex> daneWyjsciowe = new Vector<Complex>();

	double delta;

	public void pobierzWartosci(Wartosci obj) {
		daneWejsciowe.add(obj.a);
		daneWejsciowe.add(obj.b);
		daneWejsciowe.add(obj.c);
	}

	protected void obliczDelte() {
	}

	public void wyswietlPierwiastki() {
		for (int i = 0; i < daneWyjsciowe.size(); i++)
			System.out.println(daneWyjsciowe.elementAt(i));
	}

	public void obliczPierwiastki() {
	}

	public void wyswietlDelte() {
		System.out.println("Delta: " + delta);
	}
}