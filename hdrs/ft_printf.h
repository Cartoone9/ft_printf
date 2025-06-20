/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:49:36 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	unsigned char	chr;
	int				preci;
	int				diese;
	int				width;
	int				blank;
	int				zero;
	int				plus;
	int				left;
	int				neg;
	int				dot;
}					t_flags;

size_t				ft_isvalid(char c);
size_t				ft_isflag(char c);
size_t				ft_intlen(unsigned int n);
char				*ft_uitoa(unsigned int n);
char				*ft_nullstr(void);
char				*ft_s_empty(void);
char				*ft_prefix(char c);
void				ft_free(char **strr);
void				ft_free_flags(t_flags **flags);
char				*ft_tohexa(unsigned long long n_ulnln, t_flags **flags);
void				ft_sixtreculn_fill(unsigned long long n_ulnln, char *base,
						char *dest, size_t max);
void				ft_fhexa_neg(char *str, size_t max, unsigned char chr);
void				ft_tenrec_fill(size_t length, char *ret, unsigned int n);
int					ft_conv_c(char **strr, int index, t_flags **flags, int c);
int					ft_conv_i(char **strr, int index, t_flags **flags, int n);
int					ft_conv_u(char **strr, int index, t_flags **flags,
						unsigned int ui);
int					ft_conv_s(char **strr, int index, t_flags **flags,
						char *str);
int					ft_conv_p(char **strr, int index, t_flags **flags,
						void *ptr);
int					ft_conv_x(char **strr, int index, t_flags **flags,
						unsigned int n_u);
int					ft_conv_prct(char **strr, int index);
int					ft_printer_cs(char *str, t_flags *fl, int chr);
int					ft_printer_di(char *str, t_flags *fl);
int					ft_printer_x(char *str, t_flags *fl);
int					ft_printf(const char *str, ...);
int					ft_printf_suite(char **strr, va_list args, t_flags **flags,
						size_t *i_ptr);
int					ft_railway(char **strr, int index, t_flags **flags,
						va_list args);
int					ft_fillstr(char **strr, const char *s, char c);
int					ft_voidptr(char **strr, int index, t_flags **flags);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strcnt(const char *str, char c);
size_t				ft_nextch(const char *str, char c);
size_t				ft_strlen(const char *str);
char				**ft_split_prct(char const *s);
char				*ft_strdup(const char *src);
char				*ft_itoa(int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t max);
void				ft_width_fill(t_flags **flags, unsigned char c);
void				ft_preci_fill(t_flags **flags, unsigned char c);
t_flags				*ft_flags_init(void);
t_flags				*ft_c_flags(char **strr, int index);
t_flags				*ft_s_flags(char **strr, int index);
t_flags				*ft_i_flags(char **strr, int index, int n);
t_flags				*ft_u_flags(char **strr, int index);
t_flags				*ft_p_flags(char **strr, int index);
t_flags				*ft_x_flags(char **strr, int index, unsigned int n_u);
char				*ft_c_ret(t_flags *flags, unsigned char c);
int					ft_full_print_di(t_flags *fl, char *str);
int					ft_full_print_x(t_flags *fl, char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_width_print_l_cs(size_t width, char *str, int sum);
void				ft_width_print_r_cs(size_t width, char *str, int sum);
void				ft_dot(char **strr, int index, t_flags **flags);
void				ft_i_remove_conflict(t_flags **flags, int n);
void				ft_u_remove_conflict(t_flags **flags);
void				ft_p_remove_conflict(t_flags **flags);
void				ft_x_remove_conflict(t_flags **flags);
int					ft_upperhand(int str_len, int preci);
int					ft_full_print_di_left(t_flags *fl, char *str, int upperhand,
						int str_len);
int					ft_full_print_di_right(t_flags *fl, char *str,
						int upperhand, int str_len);
int					ft_full_print_di_right_suite(t_flags *fl, char *str,
						int str_len);
int					ft_full_print_x_right(t_flags *fl, char *str, int upperhand,
						char *prefix);
int					ft_full_print_x_right_suite(t_flags *fl, char *str,
						char *prefix, int str_len);
int					ft_full_print_x_left(t_flags *fl, char *str, int upperhand,
						char *prefix);

#endif
