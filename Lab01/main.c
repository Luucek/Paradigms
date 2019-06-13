#include <stdio.h>

float a = 0;
float b = 3;
float c = 2;
float err = 10;

float x1r, x2r, x1u, x2u;
float delta, pdelta, temp;

int main(int argc, char *argv)
{
	//1
	if (a == 0 && b == 0 && c == 0)
		printf("%.0f=0\n", a);
	else
	{
		if (a == 0);
		else if (a == 1)
			printf("xx");
		else
			printf("%.0fxx", a);
		if (b > 1)
			printf("+%.0fx", b);
		else if (b == 0)
			;
		else if (b == 1)
			printf("+x");
		else
			printf("%.0fx", b);
		if (c > 0)
			printf("+%.0f=0", c);
		else if (c == 0)
			printf("=0");
		else
			printf("%.0f=0", c);
		printf("\n");
	}
	if (a != 0)
	{
		//2
		delta = (b * b) - (4 * a * c);
		if (delta > 0)
		{
			pdelta = delta / 2;
			//pierwiastkowanie:
		loop:
			temp = pdelta - (delta / pdelta);
			if (temp < 0)
				temp *= -1;
			if (temp > err)
			{
				pdelta = (pdelta + delta / pdelta) / 2;
				if (pdelta * pdelta == delta)
					goto finish;
				goto loop;
			}
		finish:                                  //3
			x1r = ((b * -1) - pdelta) / (2 * a); //5
			x2r = ((b * -1) + pdelta) / (2 * a); //6
			printf("x1r = %f x2r = %f\n", x1r, x2r);
		}
		else if (delta < 0)
		{
			delta = delta * -1;
			pdelta = delta / 2;
			//pierwiastkowanie:
		loop2:
			temp = pdelta - (delta / pdelta);
			if (temp < 0)
				temp *= -1;
			if (temp > err)
			{
				pdelta = (pdelta + delta / pdelta) / 2;
				if (pdelta * pdelta == delta)
					goto finish2;
				goto loop2;
			}
		finish2: //4
			printf("pdelta: %f\n", pdelta);

			x1r = (b * -1) / (2 * a);      //8
			x2r = x1r;                     //9
			x1u = (pdelta * -1) / (2 * a); //10
			x2u = x1u * -1;                //11

			printf("%f + %f * i\n", x1r, x1u); //12
			printf("%f + %f * i\n", x2r, x2u); //13
		}
		else
		{ //7
			x1r = (b * -1) / (2 * a);
			printf("x1r = %f\n", x1r);
		}
	}
	else //a = 0
	{
		if (b != 0)
		{
			x1r = (c * -1) / b; //14
			if (x1r != 0)
				printf("x1r = %f\n", x1r);
			else
				printf("x1r = 0\n");
		}
		if (b == 0 && c != 0)
		{ //15
			printf("Rownanie sprzeczne.\n");
		}
		if (b == 0 && c == 0)
		{ //16
			printf("Rownanie tozsamosciowe.\n");
		}
	}

	system("PAUSE");
	return 0;
}