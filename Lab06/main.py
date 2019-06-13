import cmath
import math
import sys


class Wartosci:
    "klasa wartosci"

    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
        self.wyswietlWartosci()
        self.wyswietlRownanie()

    def wyswietlWartosci(self):
        s = 'Wartosci:\n' + 'a: ' + \
            repr(self.a) + ' b: ' + repr(self.b) + ' c: ' + repr(self.c)
        print(s)

    def pobierzWartosc(self, n):
        if n == 'a':
            return self.a
        elif n == 'b':
            return self.b
        elif n == 'c':
            return self.c

    def wyswietlRownanie(self):
        s = ""
        print("Rownanie:")
        if self.a == 0 and self.b == 0 and self.c == 0:
            print("0\n")
            sys.exit(0)
        else:
            if self.a == 0 and self.b == 0 and self.c > 0:
                print(repr(self.c) + "=0\nFalsz\n")
                sys.exit(0)
        if self.a == 0:
            pass
        elif self.a == 1:
            s += ("x^4")
        else:
            s += (repr(self.a) + "x^4")

        if self.b > 1:
            s += ("+" + repr(self.b) + "x^2")
        elif self.b == 0:
            pass
        elif self.b == 1:
            s += ("+x^2")
        else:
            s += (repr(self.b) + "x^2")

        if self.c > 0:
            s += ("+" + repr(self.c) + "=0")
        elif self.c == 0:
            s += ("=0")
        else:
            s += (repr(self.c) + "=0")
        print(s)


class Kwadratowe:
    "klasa podstawowego rownania kwadratowego"

    daneWejsciowe = []
    daneWyjsciowe = []
    delta = 0

    def __obliczDelte(self):
        pass

    def pobierzWartosci(self, Wartosci):
        self.daneWejsciowe.append(Wartosci.pobierzWartosc('a'))
        self.daneWejsciowe.append(Wartosci.pobierzWartosc('b'))
        self.daneWejsciowe.append(Wartosci.pobierzWartosc('c'))

    def obliczPierwiastki(self):
        pass

    def wyswietlPierwiastki(self):
        pass

    def wyswietlDelte(self):
        print("Delta: " + repr(self.delta))


class Dwukwadratowe(Kwadratowe):
    "klasa rownania dwukwadratowego"

    def __obliczDelte(self):
        if self.daneWejsciowe[0] != 0:
            self.delta = pow(
                self.daneWejsciowe[1], 2) - (4 * self.daneWejsciowe[0] * self.daneWejsciowe[2])
        else:
            self.delta = 0 - \
                (4 * self.daneWejsciowe[1] * self.daneWejsciowe[2])

    def wyswietlPierwiastki(self):
        print("Pierwiastki rownania dwukwadratowego:")
        for index in range(len(self.daneWyjsciowe)):
            print(self.daneWyjsciowe[index])

    def obliczPierwiastki(self):
        self.__obliczDelte()
        pdelta = math.sqrt(abs(self.delta))
        a = self.daneWejsciowe[0]
        b = self.daneWejsciowe[1]

        if a == 0:
            if self.delta > 0:
                x1r = pdelta / (2*b)
                x2r = -x1r
                self.daneWyjsciowe.append(complex(x1r, 0))
                self.daneWyjsciowe.append(complex(x2r, 0))
            else:
                x1u = pdelta / (2*b)
                x2u = -x1u
                self.daneWyjsciowe.append(complex(0, x1u))
                self.daneWyjsciowe.append(complex(0, x2u))
        else:
            if self.delta > 0:
                x1 = (-b - pdelta) / (2 * a)
                if x1 > 0:
                    x1r = math.sqrt(x1)
                    x2r = -x1r
                    self.daneWyjsciowe.append(complex(x1r, 0))
                    self.daneWyjsciowe.append(complex(x2r, 0))
                else:
                    x1u = math.sqrt(-x1)
                    self.daneWyjsciowe.append(complex(0, x1u))
                    self.daneWyjsciowe.append(complex(0, x1u).conjugate())
                x2 = (-b + pdelta) / (2 * a)
                if x2 > 0:
                    x3r = math.sqrt(x2)
                    self.daneWyjsciowe.append(complex(x3r, 0))
                    self.daneWyjsciowe.append(complex(x3r, 0) * -1)
                else:
                    x3u = math.sqrt(-x2)
                    self.daneWyjsciowe.append(complex(0, x3u))
                    self.daneWyjsciowe.append(complex(0, x3u).conjugate())
            elif self.delta == 0:
                x1 = -b / (2 * a)
                if x1 >= 0:
                    x1r = math.sqrt(x1)
                    x2r = -x1r
                    self.daneWyjsciowe.append(complex(x1r, 0))
                    self.daneWyjsciowe.append(complex(x2r, 0))
                else:
                    x1u = math.sqrt(-x1)
                    x2u = -x1u
                    self.daneWyjsciowe.append(complex(0, x1u))
                    self.daneWyjsciowe.append(complex(0, x2u))
            else:
                x1 = -b / (2 * a)
                x2 = -pdelta / (2 * a)
                tmp = math.sqrt((x1 * x1) + (x2 * x2))
                x1r = math.sqrt((tmp + x1) / 2)
                x3r = -x1r
                x1u = math.sqrt((tmp - x1) / 2)
                self.daneWyjsciowe.append(complex(x1r, x1u))
                self.daneWyjsciowe.append(complex(x1r, x1u).conjugate())
                self.daneWyjsciowe.append(complex(x3r, x1u))
                self.daneWyjsciowe.append(complex(x3r, x1u).conjugate())

    def wykonajDzialania(self):
        self.__obliczSume()
        self.__obliczRoznice()
        self.__obliczIloczyn()

    def __obliczSume(self):
        rzeczywiste = self.daneWyjsciowe[0].real
        urojone = self.daneWyjsciowe[0].imag
        for index in range(len(self.daneWyjsciowe)):
            if index != 0:
                rzeczywiste += self.daneWyjsciowe[index].real
                urojone += self.daneWyjsciowe[index].imag
        print("Suma rzeczywiste: " + repr(rzeczywiste) +
              "\nSuma urojone: " + repr(urojone))

    def __obliczRoznice(self):
        rzeczywiste = self.daneWyjsciowe[0].real
        urojone = self.daneWyjsciowe[0].imag
        for index in range(len(self.daneWyjsciowe)):
            if index != 0:
                rzeczywiste -= self.daneWyjsciowe[index].real
                urojone -= self.daneWyjsciowe[index].imag
        print("Roznica rzeczywiste: " + repr(rzeczywiste) +
              "\nRoznica urojone: " + repr(urojone))

    def __obliczIloczyn(self):
        rzeczywiste = self.daneWyjsciowe[0].real
        urojone = self.daneWyjsciowe[0].imag
        for index in range(len(self.daneWyjsciowe)):
            if index != 0:
                rzeczywiste *= self.daneWyjsciowe[index].real
                urojone *= self.daneWyjsciowe[index].imag
        print("Iloczyn rzeczywiste: " + repr(rzeczywiste) +
              "\nIloczyn urojone: " + repr(urojone))

    def __del__(self):
        self.daneWyjsciowe.clear()


dane = Wartosci(0, 2, 3)
rownanie = Dwukwadratowe()
rownanie.pobierzWartosci(dane)
rownanie.obliczPierwiastki()
rownanie.wyswietlPierwiastki()
rownanie.wykonajDzialania()
del rownanie
