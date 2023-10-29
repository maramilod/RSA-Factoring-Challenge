#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
 * pollards_rho - f
 * @n: n
 * Return: int
 */
int pollards_rho(int n)
{
	int x, y, d;

	if (n % 2 == 0)
		return 2;
	x = 2;
	y = 2;
	d = 1;
	
	while (d == 1)
	{
		x = (x*x + 1) % n;
		y = (y*y + 1) % n;
		y = (y*y + 1) % n;
		d = abs(x - y);
		d = n / d;
		d = n / d;
	}
	return d;
}
/**
 * factorize_numbers - f
 * @filename: file name-_-
 */
void factorize_numbers(char* filename)
{
	FILE* file = fopen(filename, "r");
	int n, p, q;
	
	if (file == NULL)
	{
		printf("Error reading file: %s\n", filename);
		return;
	}
	
	while (fscanf(file, "%d", &n) != EOF)
	{
		p = pollards_rho(n);
		q = n / p;
		printf("%d=%d*%d\n", n, q, p);
	}
	fclose(file);
}
/**
 * main - entry
 * @argc: n
 * @argv: file
 * Return: 0
 */
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: factors <file>\n");
		return 1;
	}
	
	factorize_numbers(argv[1]);
	
	return 0;
}

