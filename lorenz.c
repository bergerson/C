//criado em       :2016/07/23
//ult. atualização:2016/07/23
//autor           :Bergerson <bgerso@hotmail.com>
//notas           :Lorenz Attractor (Eqs. Dif. p/ a predição do clima).
//compilação      :gcc modelo.c -lm ou com Makefile
//execução        :./a.out ou ./lorenz

#include <stdio.h>  
#include <stdlib.h> 
#include <math.h>  

#define dt 1.0e-6
#define t0 0.0
#define tf 30.0
#define x0 1.0
#define y0 2.0
#define z0 3.0
#define sigma 10.0
#define rho 27
#define beta 8.0/3.0
#define mult (int)(tf/(dt*10000))

double f(double t, double x, double y)
{
	return (sigma*(y - x));
}

double g(double t, double x, double y, double z)
{
	return (x*(rho - z) - y);
}

double h(double t, double x, double y, double z)
{
	return (x*y - beta*z);
}

int main(int argc, char **argv)
{ 
	int counter= 0;
	double f1, f2, f3, f4;
	double g1, g2, g3, g4;
	double h1, h2, h3, h4;
	double t= t0;
	double x= x0;
	double y= y0;
	double z= z0;

FILE *file= fopen("lorenz.dat", "w");

	while (t < tf)
			{
				if	(counter%mult==0)
					{
						fprintf(file, "%e %e %e %e\n", t, x, y, z);
					}

				f1= f(t, x, y);
				g1= g(t, x, y, z);
				h1= h(t, x, y, z);

				f2= f(t+0.5*dt, x+0.5*dt*f1, y+0.5*dt*g1);
				g2= g(t+0.5*dt, x+0.5*dt*f1, y+0.5*dt*g1, z+0.5*dt*h1);
				h2= h(t+0.5*dt, x+0.5*dt*f1, y+0.5*dt*g1, z+0.5*dt*h1);

				f3= f(t+0.5*dt, x+0.5*dt*f2, y+0.5*dt*g2);
				g3= g(t+0.5*dt, x+0.5*dt*f2, y+0.5*dt*g2, z+0.5*dt*h2);
				h3= h(t+0.5*dt, x+0.5*dt*f2, y+0.5*dt*g2, z+0.5*dt*h2);

				f4= f(t+dt, x+dt*f3, y+dt*g3);
				g4= g(t+dt, x+dt*f3, y+dt*g3, z+dt*h3);
				h4= h(t+dt, x+dt*f3, y+dt*g3, z+dt*h3);

				x+= dt*(f1+2.0*f2+2.0*f3+f4)/6.0;
				y+= dt*(g1+2.0*g2+2.0*g3+g4)/6.0;
				z+= dt*(h1+2.0*h2+2.0*h3+h4)/6.0;

				t+= dt;		
				counter++;
			}
	fclose(file);
	return 0;
}



















