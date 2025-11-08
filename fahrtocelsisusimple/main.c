#include <stdio.h>

int main()
{
	float fahr, celsius;
	
	printf("Fahrenheit to Celsius Converter\n");

	while (scanf("%f", &fahr) != EOF)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("Celsius: %f\n", celsius);
	}
}
