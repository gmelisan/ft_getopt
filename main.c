/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:39:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/09 19:44:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

int		main(int argc, char *argv[])
{
	int c;

	while ((c = ft_getopt(argc, argv, ":abcd:e")) != -1)
	{
		if (c == 'a')
		{
			printf("Have a\n");
		}
		else if (c == 'b')
			printf("Have b\n");
		else if (c == 'c')
			printf("Have c\n");
		else if (c == 'd')
			printf("Have d\n");
		else if (c == 'e')
			printf("Have e\n");
		else
			printf("Unknown\n");
		printf("getopt returned %d (%c)\n", c, c);
		printf("optarg = %s\n", g_optarg);
		printf("optind = %d\n", g_optind);
		printf("optopt = %d\n", g_optopt);
	}
	return (0);
}
