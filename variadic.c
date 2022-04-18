#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}


void	ft_putint(int a)
{
	if (a < 9)
		ft_putchar((char)a + 48);
	else
	{
		ft_putint(a / 10);
		ft_putint(a % 10);
	}
}

void	vsum(char *str, ...)
{
	int i;
	int sum;
	va_list args; 			//instance of va_list object
	va_start(args, str); 	//function invoked with valid instance of va_list. count refers to vsum() know argument name.
	
	i = 0;
	sum = 0;
	while (i < 5)
	{
		sum += va_arg(args,int);
		i++;
	}
	va_end(args);
	while (*str != '\0')
	{
		if (!strncmp(str,"%d",2))
		{
			str++;	
			ft_putint(sum);
		}
		else
			ft_putchar(*str);
		str++;
	}
}

int	main()
{
	vsum("Sum of all args is: %d\n" ,1,2,3,400,50);
	return (0);
}
