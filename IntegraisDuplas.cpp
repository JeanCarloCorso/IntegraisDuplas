#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

double funcao(double x, double y)
{
	double resul;
	//f(x^2+y)
	resul = pow(x, 2) + y;
	return(resul);
}

double calcula(double a, double b, double c, double d, int n)
{
	double i, ajuda;
	double q1[50];
	double q2[50];
	double q3[50];
	i = 0;
	int z;
	ajuda = (b - a) / n;
	for (z = 0; z <= n; z++)
	{
		if (z == 0){
			q1[z] = (a);
		}
		else if (z != n) {
			q1[z] = (q1[z - 1] + ajuda);
		}
		else if (z == n){
			q1[z] = (b);
		}
	}
	////===========================================================================================
	//printf("\nTABELA X\n");
	//printf("i  |x");
	//for (z = 0; z <= n; z++){
	//	printf("\n%d  |%2.4f", z, q1[z]);
	//}
	////===========================================================================================
	ajuda = (d - c) / n;
	for (z = 0; z <= n; z++)
	{
		if (z == 0){
			q2[z] = (c);
		}
		else if (z != n) {
			q2[z] = (q2[z - 1] + ajuda);
		}
		else if (z == n){
			q2[z] = (d);
		}
	}
	////===========================================================================================
	//printf("\nTABELA Y\n");
	//printf("i  |y");
	//for (z = 0; z <= n; z++){
	//	printf("\n%d  |%2.4f", z, q2[z]);
	//}
	////===========================================================================================
	double parcial = 0;
	double aux = 0;
	for (int int2 = 0; int2 <= n; int2++){
		for (z = 0; z <= n; z++){
			if ((z == 0) || (z == n)){
				aux = funcao(q1[int2], q2[z]);
				q3[z] = aux;
			}
			else{
				aux = 3 * (funcao(q1[int2], q2[z]));
				q3[z] = aux;
			}
		}
		aux = 0;
		for (z = 0; z <= n; z++){
			aux += q3[z];
		}
		parcial = aux;
		parcial = (parcial * ((3 * ajuda) / 8));
		if ((int2 == 0) || (int2 == n)){
			i += parcial;
		}
		else
		{
			i += parcial * 3;
		}
	}
	i = i*(3 * (((b - a)/n) / 8));
		return(i);
}
int main()
{
	double a, b, c, d, i;
	int n;
	system("cls");

	printf("%cb %cd\n", 218, 218);
	printf("%ca %cc f(x) dy dx\n\n", 217, 217);

	printf("Informe os limites da integração:\n\n");

	printf("a: ");	scanf("%lf", &a);
	printf("b: ");	scanf("%lf", &b);
	printf("c: ");	scanf("%lf", &c);
	printf("d: ");  scanf("%lf", &d);

	printf("\nInforme o numero de integracoes:\n\n");
	printf("n: "); scanf("%d", &n);

	system("cls");
	printf("%c%4.2f %c%4.2f\n", 218, b, 218, d);
	printf("%c%4.2f %c%4.2f f(x) dy dx\n\n", 217, a, 217, c);
	i=calcula(a, b, c, d, n);
	printf("\n\n");
	system("cls");
	printf("\n\nO resultado final e:\nI: %f\n\n\n", i);
	system("pause");
	return(0);
}
