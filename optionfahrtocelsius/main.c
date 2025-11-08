#include <stdio.h>

int main()
{
	float fahr, celsius, kelvin;
	int c;
	
	printf("Press 1 for Fahrenheit to Celsisus and 2 for Celsisus to Fahrenheit\n");
	printf("Press 3 for Fahrenheit to Kelvin\n");
	c = getchar();

	if(c == '1')
	{
		printf ("Please enter Fahrenheit to be converted\n");
		while (scanf("%f", &fahr) != EOF)
		{
			celsius = (5.0 / 9.0) * (fahr - 32.0);
			printf("Celsius: %f\n", celsius);
		}
	}
	if(c == '2')
	{
		printf ("Please enter Celsius to be converted\n");
		while (scanf("%f", &celsius) != EOF)
		{
			fahr = (celsius * 9.0 / 5.0) + 32.0;
			printf("Fahrenheit: %f\n", fahr);
		}
	}
	if(c == '3')
	{
		printf ("Please enter Fahrenheit to be converted\n");
		while (scanf("%f", &fahr) != EOF)
		{
			kelvin = (fahr + 459.67) * 5.0 / 9.0;
			printf("Kelvin: %f\n", kelvin);
		}
	}
}
