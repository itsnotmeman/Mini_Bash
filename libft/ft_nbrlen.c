int	ft_nbrlen(int nbr, unsigned int unbr, int type)
{
	int	len;

	len = 1;
	if (type == 0)
	{
		while (unbr >= 10)
		{
			unbr /= 10;
			++len;
		}
		return (len);
	}
	else
	{
		while (nbr <= -10 || nbr >= 10)
		{
			nbr /= 10;
			++len;
		}
		if (nbr < 0)
			++len;
		return (len);
	}
}
