/*
** my_getnbr.c for overflow_asm in /home/sylvain.lefevre/test/overflow_asm
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Tue Mar 21 20:00:05 2017 Sylvain Lefevre
** Last update Tue Mar 21 20:00:05 2017 Sylvain Lefevre
*/

int	my_getnbr(char *str)
{
  int	nbr;
  int	sign;
  int	i;

  nbr = 0;
  sign = 1;
  i = -1;
  if (!str)
    return (0);
  while (str[++i] == '-')
    sign = (sign == 1) ? -1 : 1;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (nbr * sign);
      nbr = nbr * 10 + str[i++] - '0';
    }
  return (nbr * sign);
}

int	str_isnum(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i += 1;
    }
  return (1);
}
