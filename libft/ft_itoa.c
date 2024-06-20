#include "libft.h"

static int	ft_nbr_len(int n);
static char	*nbr_is_negativ(int n, int len);
static char	*nbr_is_positiv(int n, int len);

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	len = ft_nbr_len(n);
	if (n == 0)
	{
		nbr = ft_calloc(len + 1, sizeof(char));
		if (nbr == 0)
			return (0);
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	else if (n > 0)
	{
		nbr = nbr_is_positiv(n, len);
		return (nbr);
	}
	else if (n < 0)
	{
		nbr = nbr_is_negativ(n, len);
		return (nbr);
	}
	return (0);
}

static char	*nbr_is_positiv(int n, int len)
{
	char	*nbr;
	int		i;
	int		digit;

	i = 1;
	nbr = ft_calloc(len + 1, sizeof(char));
	if (nbr == 0)
		return (0);
	while (n >= 10)
	{
		digit = n % 10;
		n = (n - digit) / 10;
		nbr[len - i] = '0' + digit;
		i++;
	}
	nbr[0] = '0' + n;
	nbr[i] = '\0';
	return (nbr);
}

static char	*nbr_is_negativ(int n, int len)
{
	char	*nbr;
	int		i;
	int		digit;

	i = 1;
	nbr = ft_calloc(len + 2, sizeof(char));
	if (nbr == 0)
		return (0);
	while (n <= -10)
	{
		digit = n % 10;
		n = (n - digit) / 10;
		nbr[len + 1 - i] = '0' + (digit * (-1));
		i++;
	}
	nbr[0] = '-';
	nbr[1] = '0' - n;
	nbr[i + 1] = '\0';
	return (nbr);
}

static int	ft_nbr_len(int n)
{
	int	counter;

	counter = 1;
	if (n >= 0)
	{
		while (n >= 10)
		{
			n /= 10;
			counter++;
		}
	}
	else if (n < 0)
	{
		while (n <= -10)
		{
			n /= 10;
			counter++;
		}
	}
	return (counter);
}
