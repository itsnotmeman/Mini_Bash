#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_check_format_1(char format, va_list args, int array_6);
int	ft_check_format_2(char format, va_list args, int array_6);
int	*ft_array_reset(int *array);
int	*ft_count_len_1(char format, va_list args, int *array);
int	*ft_count_len_2(char format, va_list args, int *array);
int	*ft_count_len_3(char format, va_list args, int *array);
int	*ft_format_d_i(int *array);
int	*ft_format_hex(int *array, char format);
int	*ft_format_c_p(int *array);
int	*ft_format_percent(int *array);
int	*ft_format_str(int *array);
int	*ft_format_u(int *array);
int	*ft_zeros_before_nb(int *array);
int	*ft_zeros_before_nb_2(int *array);
int	*ft_spaces_zeros_padding(int *array);

#endif
