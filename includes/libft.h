/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:59:30 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 17:41:31 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# include "libft_intdefs.h"
# include "ft_array.h"

/*
** Part I
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *hay, const char *need, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Part II
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Lst Bonus
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *newe);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Other list related
*/

t_list			*ft_lstlast(t_list *list);
int				ft_lstcount(t_list *list);
t_list			*ft_lstindex(t_list	*list, size_t index);
t_list			*ft_strlstsplit(char const *str, char c);
void			*ft_lstfold(t_list *lst, void *(*f)(void *e1, void *e2));

t_list			*ft_lstpop(t_list **list, t_list *item);

/*
** Unicode stuff
*/

int				ft_putwchar_fd(int chr, int fd);
int				ft_putwchar(int chr);
int				ft_putwstr_fd(const int *str, int fd);
int				ft_putwstr(const int *str);
int				ft_wstrlen(const int *str);

/*
** Autofree stuff
*/

const void		*ft_autofree_pushpop(const void *to_push);
int				ft_autofree_begin(void);
void			*ft_autofree(const void *to_free);
void			ft_autofree_end(void);
int				ft_autofree_end0(void);
void			ft_autofree_abort(void);
int				ft_autofree_abort0(void);

/*
** Other
*/

int				ft_min(int a, int b);
int				ft_max(int a, int b);
int				ft_sqrt(int nb);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isspace(int c);
int				ft_isxdigit(int c);
char			*ft_strtolower(const char *str);
char			*ft_strtoupper(const char *str);
void			*ft_memdup(const void *s1, size_t size);
char			*ft_strndup(const char *s1, size_t n);
int				ft_memrealloc(void **mem, size_t *prev_size, size_t new_size);
void			ft_free_vectors(void *to_free, int array_layers);

int				ft_isstrnum(const char *str);
int				ft_strbegins(const char *s1, const char *s2);
int				ft_strends(const char *s1, const char *s2);
char			*ft_lltoa(long long int n);
char			*ft_ulltoa_basestr(unsigned long long int n, char *base_str);
int				ft_abs(int nb);

const void		*ft_pushpop(const void *to_push);

# define FT_FREETASK_1ST 0x1
# define FT_FREETASK_2ND 0x2
# define FT_FREETASK_BOTH 0x3
# define FT_FREETASK_ALWAY 0x4

char			*ft_strfuse(char **s1, char **s2, int free_task);
int				ft_memdel0(void **to_free);
int				ft_memdel1(void **to_free);
int				ft_free0(void *to_free);
int				ft_ptrcount(void **ptr);
int				ft_free_vectors0(void *to_free, int layers);

int				ft_random(void);
unsigned int	ft_urandom(void);
t_llint			ft_llrandom(void);
t_ullint		ft_ullrandom(void);

int				ft_pow(int nb, unsigned int p);
t_llint			ft_llpow(t_llint nb, unsigned int p);
char			*ft_ldtoa(long double d, unsigned int precision);
void			ft_strcatchar(char *str, char c);
int				ft_intsize(int i);

void			ft_strputchr(char *str, char c);
long double		ft_alt_round(long double d, unsigned int precision);
char			*ft_strminfield(const char *str, int field_width);

#endif
