/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:39:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/13 18:32:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_getopt.h"

typedef int (*pfunc)(int, char *const *, const char *);

void	test(FILE *fp, int argc, char *argv[], pfunc f, char **_optarg, int *_optind, int *_optopt)
{
	int c;

	while ((c = f(argc, argv, "abc:def")) != -1)
	{
		fprintf(fp, "- getopt returned %d (%c)\n", c, c);
		fprintf(fp, "optarg = %s\n", *_optarg);
		fprintf(fp, "optind = %d\n", *_optind);
		fprintf(fp, "optopt = %d\n", *_optopt);
	}
	fprintf(fp, "\ngetopt returned %d (%c)\n", c, c);
	fprintf(fp, "optarg = %s\n", *_optarg);
	fprintf(fp, "optind = %d\n", *_optind);
	fprintf(fp, "optopt = %d (%c)\n", *_optopt, *_optopt);
}

int		main(int argc, char *argv[])
{
	FILE *f1;
	FILE *f2;

	f1 = fopen("system.txt", "w+");
	f2 = fopen("my.txt", "w+");
	test(f1, argc, argv, getopt, &optarg, &optind, &optopt);
	test(f2, argc, argv, ft_getopt, &g_optarg, &g_optind, &g_optopt);
	return (0);
}
