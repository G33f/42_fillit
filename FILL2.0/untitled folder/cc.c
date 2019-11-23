#include <string.h>
#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		putchar(*s);
		s++;
	}
}

void ft_putmat(const char **mat)
{
	if (!mat)
		return;
	while(*mat)
	{
		ft_putstr(*mat);
		//   mat++;
	}
}

void				**ft_memcpy(void ***dest, const void ***source, size_t n1, size_t n2)
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
		return (str1);
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

void	ft_matcp(char **mat1, char **mat2, int mt1_l, int mt2_l)
{
	int i;
	int j;

	if (!mat1 || !mat2 || (mt1_l != mt2_l) || (!mt1_l))
		return (NULL);
	i = 0;
	j = 0;
	while (j < mt1_l)
	{
		while(i < mt2_l)
		{
			mat1[j][i] = mat2[j][i];
			i++;
		}
		i = 0;
		j++;
	}
}

void ddd(char **str)
{
	for(int l = 0; l < 3;l++)
	{
		for(int r = 0;r < 4;r++)
		{
			putchar(str[l][r]);
		}
	}
}

int main()
{
	char **mat1;
	char **mat2;
	mat2= malloc(sizeof(char*) * 3);
	mat2[0] = malloc(sizeof(char)*(4));
	mat2[1] = malloc(sizeof(char)*(4));
	mat2[2] = malloc(sizeof(char)*(4));
	mat1= malloc(sizeof(char*) * 3);
	mat1[0] = malloc(sizeof(char)*(4));
	mat1[1] = malloc(sizeof(char)*(4));
	mat1[2] = malloc(sizeof(char)*(4));


	for(int r = 0; r < 3; r++)
	{
		for(int l = 0;l < 3; l++)
		{
			mat2[r][l] = 'c';
		}
		mat2[r][3] = '\n';
	}
//    for(int l = 0; l < 3;l++)
//    {
//        for(int r = 0;r < 4;r++)
//	    {
//		    putchar(mat2[l][r]);
//	    }
//	}
	// ddd(mat2);
	ft_memcpy(mat1, mat2, 3, 4);
	for(int l = 0; l < 3;l++)
	{
		for(int r = 0;r < 4;r++)
		{
			putchar(mat1[l][r]);
		}
	}
	ft_putmat(mat1);
	return 0;
}
