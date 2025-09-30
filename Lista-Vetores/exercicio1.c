#include <stdio.h>

float soma(float x, float y)
{
	float resultado;
	resultado = x + y;
	return resultado;
}

float sub(float x, float y)
{
	float resultado;
	resultado = x - y;
	return resultado;
}

float mult(float x, float y)
{
	float resultado;
	resultado = x * y;
	return resultado;
}

float div(float x, float y)
{
	float resultado;
	resultado = x / y;
	return resultado;
}

int main()
{
	float num1, num2, resultado;
	char operator;

	do
	{
		printf("=== MENU ===\n");
		printf("Digite o que deseja calcular\n");
		printf("+ Para Adição\n");
		printf("- Para Subtração\n");
		printf("* Para Multiplicação\n");
		printf("/ == Para Divisão\n");
		printf("0 para Sair\n");
		printf("Insira a operação desejada: ");
		scanf("%c", &operator);
		getchar(); // consumir \n
		switch (operator)
		{
		case '+':
			printf("Insira o primeiro número:\n");
			scanf("%f", &num1);

			printf("Insira o segundo número:\n");
			scanf("%f", &num2);

			resultado = soma(num1, num2);

			printf("O resultado da operação é: %.2f\n\n", resultado);
			break;

		case '-':
			printf("Insira o primeiro número:\n");
			scanf("%f", &num1);

			printf("Insira o segundo número:\n");
			scanf("%f", &num2);

			resultado = sub(num1, num2);

			printf("O resultado da operação é: %.2f\n\n", resultado);
			break;

		case '*':
			printf("Insira o primeiro número:\n");
			scanf("%f", &num1);

			printf("Insira o segundo número:\n");
			scanf("%f", &num2);

			resultado = mult(num1, num2);

			printf("O resultado da operação é: %.2f\n\n", resultado);
			break;

		case '/':
			printf("Insira o primeiro número:\n");
			scanf("%f", &num1);

			printf("Insira o segundo número:\n");
			scanf("%f", &num2);

			if (num2 == 0)
			{
				printf("Operação invalida!!!");
				break;
			}
			else
			{
				resultado = div(num1, num2);
				printf("O resultado da operação é: %.2f\n\n", resultado);
			}
			break;
		}
	} while (operator != '0');
}
