/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:40:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/09 19:50:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

char		*g_optarg;
int			g_optind = 1;
int			g_optopt;

static int	found(int argc, char * const argv[], char *f, int *pos)
{
	if (*(f + 1) == ':')
	{
		if (argv[g_optind][*pos + 1] == '\0')
		{
			g_optarg = argv[g_optind + 1];
			g_optind += 1;
			if (argv[g_optind] && *argv[g_optind] != '-') /* todo check */
				return ('?');
			g_optind += 1;
			return (g_optind > argc ? -1 : g_optopt);
		}
		else
		{
			g_optarg = &argv[g_optind][*pos + 1];
			g_optind += 1;
			return (g_optopt);
		}
	}
	if (argv[g_optind][*pos + 1] == '\0')
	{
		g_optind += 1;
		*pos = 1;
	}
	else
		*pos += 1;
	return (g_optopt);
}

int			ft_getopt(int argc, char * const argv[], const char *optstring)
{
	static int	pos = 1;
	char		*f;

	if (!argv[g_optind] || g_optind > argc - 1
		|| *argv[g_optind] != '-' || ft_strequ(argv[g_optind], "-"))
		return (-1);
	if (ft_strequ(argv[g_optind], "--"))
	{
		g_optind++;
		return (-1);
	}
	while ((g_optopt = argv[g_optind][pos]))
	{
		if ((f = ft_strchr(optstring, g_optopt)))
			return (found(argc, argv, f, &pos));
		else
		{
			g_optind++;
			pos = 1;
			return ('?');
		}
	}
	return (-1);
}
