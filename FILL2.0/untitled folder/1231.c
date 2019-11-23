
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define FILLIT_H
# include <fcntl.h>

typedef struct			s_tetrimino
{
	size_t				numb;
	size_t				x;
	size_t				y;
	char				**content;
	struct s_tetrimino	*next;
}						tetrimino;

int			vtwo(char *s, char sim);
void		ft_two(char *s, int *i, int *count, char *sim);
int			ft_one(char *s, int i, int *m, int *count);
int			valid(char **s);
int		    ft_y(char *s);
int	    	ft_x(char *s);
int		    ft_search(char *s);
tetrimino	*ft_newtet(char **s, int x, int y, int numb);
char		*ft_add_2(char *s, char *buf, int sim);
char		**ft_add(char *s);
tetrimino	*maintet(char *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_strnew(size_t size);
static	int	ft_len(char const *s, char c);
void	    ft_putchar(char c);
static void	ft_clean(char **str, int i);
void    	ft_putstr(char const *s);
size_t		ft_strlen(const char *str);
char		**ft_build(tetrimino *tes, char **cube, int leng);
void    	ft_putmat(const char **mat);
void    	**ft_matcp(void **dest, const void **source, size_t n1, size_t n2);
char    	**ft_put(tetrimino *tes, char **cube, int i, int j);
int	    	ft_starter(int fd);
int	    	lengt(tetrimino *tes);
double		ft_sqrt(double num);
int	    	ft_cu_wards(char const *s, char c);
double		ft_pow(double num, int pow);
int			ft_logic(tetrimino *tes);
char    	**ft_newmat(char **cube, int i);
int	    	ft_check(tetrimino *tes, char **cube, int i, int j);
void    	ft_putstr(char const *s);
void		*ft_memset(void *str, int nb, size_t size);
void    	ft_matdel(void **as, int i);

void	ft_matdel(void **as, int i)
{
	if (!as || !*as)
		return ;
	while(i)
	{
		ft_memdel(&as[i]);
		as[i] = NULL;
		i--;
	}
	ft_memdel(as);
	as = NULL;
}

void		*ft_memset(void *str, int nb, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)str;
	while (i < size)
	{
		new[i] = nb;
		i++;
	}
	return (str);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

int		ft_check(tetrimino *tes, char **cube, int i, int j)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (m < (int)tes->y)
	{
		while (n < (int)tes->x)
		{
			if ((cube[j + m][i + n] == '.') || (tes->content[m][n] == '.'))
				n++;
			else
				return (0);
		}
		n = 0;
		m++;
	}
	return (1);
}

char	**ft_newmat(char **cube, int i)
{
	int 	r;

	r = 0;
	if (!(*cube = malloc(sizeof(i))))
	{
		return (NULL);
	}
	while(r < i)
	{
		if(!(cube[r] = malloc(sizeof(i + 1))))
		{
			ft_matdel((void**)cube, i);
			return (NULL);
		}
		r++;
	}
	r = 0;
	while(r < i)
	{
		*cube[r] = (char)ft_memset(cube[r], '.', i);
		cube[r][i + 1] = '\n';
		r++;
	}
	return (cube);
}

int			ft_logic(tetrimino *tes)
{
	char	**cube;
	int		i;

	i = lengt(tes);
	while(i < (lengt(tes) + 1))
	{
		cube = ft_newmat(cube, i);
		if (cube == NULL)
			return (0);
		cube = ft_build(tes, cube, i);
		if (cube == NULL)
		{
			ft_matdel((void**)cube, i);
			i++;
		}
		else
		{
			ft_putmat((const char**)cube);
			ft_matdel((void**)cube, i);
			return (1);
		}
	}
	return (0);
}

double		ft_pow(double num, int pow)
{
	double	res;
	int		n;

	res = 1;
	if (!pow || pow == 0)
		return (1);
	if (pow < 0)
	{
		n = -1;
		pow *= -1;
	}
	else
		n = 1;
	while (pow != 0)
	{
		res *= num;
		pow--;
	}
	if (n < 0)
		return (1 / res);
	else
		return (res);
}

int		ft_cu_wards(char const *s, char c)
{
	int	cu;
	int	i;

	i = 0;
	cu = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			cu++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cu);
}

double		ft_sqrt(double num)
{
	double	r;
	double	q;
	int		i;

	q = 0;
	r = 1;
	i = 0;
	if (!num)
		return (0);
	while (i < 15)
	{
		q = 1 / ft_pow(10, i);
		while (((r + q) * (r + q)) < num)
			r += q;
		i++;
	}
	return (r);
}

int		lengt(tetrimino *tes)
{
	int i;

	i = tes->numb * 4;
	if (((int)ft_sqrt(i) * (int)ft_sqrt(i)) < i)
		i = ((int)ft_sqrt(i) + 1);
	else
		i = ((int)ft_sqrt(i));
	return (i);
}

int		ft_starter(int fd)
{
	char		*s;
	char		buf[550];
	int			r;
	tetrimino	*head;

	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (valid(&s) < 0)
		return (0);
	head = maintet(s);
	if (!(ft_logic(head)))
		return (0);
	return (1);
}

char	**ft_put(tetrimino *tes, char **cube, int i, int j)
{
	int m;
	int n;

	m = 0;
	n = 0;
	while (m < (int)tes->y)
	{
		while (n < (int)tes->x)
		{
			cube[j + m][i + n] = tes->content[m][n];
		}
		n = 0;
		m++;
	}
	return (cube);
}

void	**ft_matcp(void **dest, const void **source, size_t n1, size_t n2)
{
	unsigned char	**str1;
	unsigned char	**str2;
	size_t			i;
	size_t          j;

	str1 = (unsigned char **)dest;
	str2 = (unsigned char **)source;
	if (!source && !dest)
		return (NULL);
	i = 0;
	j = 0;

	if (n1 <= 0 || n2 <= 0)
		return (dest);
	while (i < n1)
	{
		while(j < n2)
		{
			str1[i][j] = str2[i][j];
			j++;
		}
		j=0;
		i++;
	}
	return (dest);
}

void	ft_putmat(const char **mat)
{
	if (!mat)
		return ;
	while(*mat)
	{
		ft_putstr(*mat);
		mat++;
	}
}

char		**ft_build(tetrimino *tes, char **cube, int leng)
{
	char	**step = NULL;
	int		i;
	int		j;

	j = 0;
	if(!tes)
		return (cube);
	if (!(step = ft_newmat(step, leng)))
		return (NULL);
	ft_matcp((void**)step, (const void**)cube, leng, leng + 1);
	while (j < (leng - (int)tes->y))
	{
		i = 0;
		while (i < (leng - (int)tes->x))
		{
			if (ft_check(tes, cube,i , j) == 1)
			{
				step = ft_put(tes, step, i, j);
				if (!(cube = ft_build(tes->next, step, leng)))
				{
					ft_matdel((void**)step, leng);
					if (!(step = ft_newmat(step, leng)))
						return (NULL);
				}
				else
				{
					ft_matcp((void**)cube, (const void**)step, leng, leng + 1);
					ft_matdel((void**)step, leng);
					return (cube);
				}
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	void	ft_clean(char **str, int i)
{
	while (i >= 0)
	{
		free((*str + i));
		i--;
	}
	free(str);
}

static	int		ft_len(char const *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char		*ft_strnew(size_t size)
{
	char	*new;

	if ((size + 1) < size)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			l;
	char		**str;

	if (!s || !(str = (char **)malloc(sizeof(str) * (ft_cu_wards(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_cu_wards(s, c))
	{
		l = 0;
		if (!(str[i] = ft_strnew(ft_len(&s[j], c) + 1)))
		{
			ft_clean(str, i);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][l++] = s[j++];
		str[i][l] = '\0';
	}
	str[i] = 0;
	return (str);
}

tetrimino		*maintet(char *s)
{
	tetrimino	*head;
	tetrimino	*tmp;
	int			i;
	int			c;
	int			stop;

	i = 0;
	c = 1;
	head = NULL;
	stop = ft_strlen(s);
	while (s[i] && i < stop)
	{
		if (!head)
		{
			head = ft_newtet(ft_add(&s[i]), ft_x(&s[i]), ft_y(&s[i]), c++);
			tmp = head;
		}
		else
		{
			tmp->next = ft_newtet(ft_add(&s[i]), ft_x(&s[i]), ft_y(&s[i]), c++);
			tmp = tmp->next;
		}
		i += 21;
	}
	return (head);
}

char			**ft_add(char *s)
{
	char		**ho;
	char		*buf;
	int			sim;

	sim = 0;
	buf = ft_strnew(10);
	ho = ft_strsplit(ft_add_2(s, buf, sim), '\n');
	free(buf);
	return (ho);
}

char			*ft_add_2(char *s, char *buf, int sim)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (s[i] && i < 20)
	{
		if ((sim = ft_search(&s[i])))
		{
			while (s[i] && s[i] != '\n')
			{
				if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
					buf[j++] = s[i];
				else if (s[i - 5] == sim || s[i - 10] == sim)
					buf[j++] = s[i];
				i++;
			}
			buf[j++] = '\n';
			sim = 0;
			i++;
		}
		else
			i += 5;
	}
	return (buf);
}

tetrimino		*ft_newtet(char **s, int x, int y, int numb)
{
	tetrimino	*tmp;

	tmp = (tetrimino*)ft_memalloc(sizeof(tetrimino));
	tmp->numb = numb;
	tmp->x = x;
	tmp->y = y;
	tmp->content = s;
	tmp->next = NULL;
	return (tmp);
}

int		ft_search(char *s)
{
	int sim;
	int i;

	sim = 0;
	i = 0;
	while (i < 4)
	{
		if (s[i] != '.')
			sim = s[i];
		i++;
	}
	return (sim);
}

int		ft_x(char *s)
{
	int flag;
	int i;
	int x;

	x = 0;
	i = 0;
	flag = 0;
	while (i < 20)
	{
		while (i < 20 && s[i] != '\n')
		{
			if (s[i] != '.' && s[i] != '\0' && !flag)
			{
				flag = 1;
				x++;
			}
			i++;
		}
		flag = 0;
		i++;
	}
	return (x);
}

int		ft_y(char *s)
{
	int	i;
	int y;
	int max;

	max = 0;
	i = 0;
	y = 0;
	while (i < 20)
	{
		if (ft_search(&s[i]))
		{
			while (i < 20 && s[i] != '\n')
			{
				if (s[i] != '.' || (s[i + 5] != '.' && i + 5 < 20))
					y++;
				i++;
			}
			max = (max < y) ? y : max;
			y = 0;
		}
		else
			i += 4;
		i++;
	}
	return (max);
}

int			valid(char **s)
{
	char	sim;
	int		i;
	int		n;
	int		count;
	int		stop;

	n = 0;
	i = 0;
	count = 0;
	stop = ft_strlen(&s[0][0]);
	if (vone(*s, &n, &count) < 0)
		return (-1);
	sim = 'A';
	while (s[0][i] && i < stop)
	{
		if (vtwo(&s[0][i], sim++) < 0)
			return (-1);
		i += 21;
	}
	return (0);
}

int			vone(char *s, int *n, int *count)
{
	int		i;
	int		m;

	i = 0;
	m = 5;
	while (s[i] && i < (m - 1))
	{
		while (s[i] != '\n' && s[i])
		{
			if ((s[i] != '#' && s[i] != '.') || i >= (m - 1))
				return (-1);
			if (s[i++] == '#')
				*count += 1;
		}
		*n += 1;
		if (s[i] == '\n' && s[i - 1] == '\n')
		{
			if (*n > 5)
				return (-1);
			*n = 0;
		}
		if (ft_one(s, i, &m, count) < 0 || i++ > 545)
			return (-1);
	}
	return (0);
}

int			ft_one(char *s, int i, int *m, int *count)
{
	if (i < (*m - 1) && s[i - 1] != '\n')
		return (-1);
	if (s[i] != '\0' && s[i - 1] != '\n')
		*m = *m + 5;
	if ((s[i] == '\n' && s[i + 1] == '\n') || s[i] == '\0')
	{
		if (*count != 4)
			return (-1);
		*count = 0;
		*m += 1;
	}
	if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
		return (-1);
	return (0);
}

int			vtwo(char *s, char sim)
{
	int		count;
	int		e;
	int		i;

	count = 0;
	i = 0;
	e = 0;
	while (s[i] != '#')
		i++;
	e = i;
	while ((s[e + 1] == '#') || (s[e + 5] == '#' || s[e] == '#'))
	{
		s[e] = sim;
		count++;
		i = e;
		ft_two(s, &i, &count, &sim);
		e++;
	}
	return ((count != 4)) ? -1 : 0;
}

void		ft_two(char *s, int *i, int *count, char *sim)
{
	int		j;

	while (s[*i + 5] == '#' && *i + 5 < 21)
	{
		*i += 5;
		j = *i;
		while (s[j + 1] == '#')
		{
			j++;
			s[j] = *sim;
			*count += (s[j + 5] == '#' && j + 5 < 21) ? 2 : 1;
			s[j + 5] = (s[j + 5] == '#' && j + 5 < 21) ? *sim : s[j + 5];
		}
		j = *i;
		while (s[j - 1] == '#')
		{
			j -= 1;
			s[j] = *sim;
			*count += (s[j + 5] == '#' && j + 5 < 21) ? 2 : 1;
			s[j + 5] = (s[j + 5] == '#' && j + 5 < 21) ? *sim : s[j + 5];
		}
		s[*i] = *sim;
		*count += 1;
	}
}

int		main(int argc, char **argv)
{
	if (!(ft_starter(open("untitled", O_RDONLY))))
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

