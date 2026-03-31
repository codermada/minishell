/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:13:48 by nnomenja          #+#    #+#             */
/*   Updated: 2025/08/02 22:30:34 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "basic_utils.h"
# include <fcntl.h>
# include "minishell.h"
# include <stdlib.h>

char	**ft_split(char const *s, char c);
void	init_history(int *fd);
void	add_history_(char *s, int *fd);

#endif
