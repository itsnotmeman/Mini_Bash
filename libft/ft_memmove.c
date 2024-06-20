#include "libft.h"

static size_t	check_overlap(char *dst, char *src, size_t len);
static void		*reverse_copy(char *dst, char *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (check_overlap(dst_ptr, src_ptr, len) == len)
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
		reverse_copy(dst_ptr, src_ptr, len);
	return (dst);
}

static size_t	check_overlap(char *dst, char *src, size_t len)
{
	size_t	gap;

	gap = 0;
	while (gap < len)
	{
		if (&src[gap] == &dst[0])
			break ;
		else
			gap++;
	}
	return (gap);
}

static void	*reverse_copy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[(len - 1) - i] = src[(len - 1) - i];
		i++;
	}
	return (0);
}
