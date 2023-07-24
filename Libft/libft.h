/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:35:12 by parinder          #+#    #+#             */
/*   Updated: 2023/01/25 14:30:29 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>

# define DEC	"0123456789"
# define HEX	"0123456789abcdef"
# define U_HEX	"0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_format
{
	int		minus;
	int		dot;
	int		precision;
	int		zero;
	int		space;
	int		plus;
	int		width;
	int		hashtag;
	char	type;
}	t_format;

/*	-	-	-	-	-	-	Part1	-	-	-	-	-	-	*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
/*	-	-	-	-	-	-	Part2	-	-	-	-	-	-	*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*	-	-	-	-	-	-	Bonus	-	-	-	-	-	-	*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*	-	-	-	-	-	-	Printf	-	-	-	-	-	-	*/
int		ft_printf(const char *format, ...);
void	ft_printf_initvar(const char *arg, t_format *format);
void	ft_printf_putvar(t_format *format, va_list list, int *count);
void	ft_printf_putchar(char c, int *count);
void	ft_printf_putstr(char *s, int precision, int *count);
void	ft_printf_putnbr(size_t n, char *base, size_t len, int *count);
size_t	ft_printf_nbrlen(size_t n, char *base, t_format *format);
void	ft_printf_prefix(int negativ, t_format *format, int *count);
void	ft_printf_frontwidth(t_format *format, int len, int *count);
void	ft_printf_backwidth(t_format *format, int len, int *count);
/*	-	-	-	-	-	get_next_line	-	-	-	-	-	*/
char	*get_next_line(int fd);

#endif
