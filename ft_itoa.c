#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		ft_numlen(int a)
{
	int	i;

	i = 0;
	while ((a / 10) != 0)
	{
		i++;
		a /= 10;
	}
	i++;
	return (i);
}



char	*ft_itoa(int a)
{
	static char	*str;
	int	pos = 0;
	int len;

	len = ft_numlen(a);
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * (len + 2));
		if (!str)
			return (NULL);
		memset(str,'\0', len + 1);
	}
	while(*(str + pos))
		pos++;
	if (a < 0)
	{
		*str = '-';
		a *= -1;
		pos++;
	}
	if (a < 9)
		*(str + pos) = (a + 48);
	else
	{
		ft_itoa(a / 10);
		ft_itoa(a % 10);
	}
	return(str);
}


int	main(void)
{

	char *num;
	int a = -12;
	num = ft_itoa(a);
	printf("%d\n",a);
	printf("%s\n", num);
	free(num);
	return (0);
}
