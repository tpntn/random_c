#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int a)
{
	int	c = 2;
	while(c < a)
	{
		if (a % c == 0)
			return (0);
		c++;
	}
	return (1);
}

int	ft_first_prime(int a)
{
	while (1)
	{
		if (ft_is_prime(a))
			return (a);
		a++;
	}
	return (0);
}

int		num_to_pfactors(int a)
{
	if (a == 1)
		return (1);
	int div = 2;
	while (1)
	{
		if (a % div == 0)
		{
			printf("%d ", div);
			num_to_pfactors(a / div);
			break;
		}
		div = ft_first_prime(div + 1);			
	}
	return (0);		
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	int num = atoi(argv[1]);
	num_to_pfactors(num);
	printf("\n");
	return (0);
}
