/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:36 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:42:31 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_LIB_H
# define C_LIB_H

# include "../lib/lib.h"

void	init_arguments(int argc, char **argv, t_args *a);
void	ft_checker(t_stack *sa, t_stack *sb, char **moves);
void	execute_instructions(t_stack *sa, t_stack *sb, char **moves);
void	exec_double_move(t_stack *sa, t_stack *sb, char *move);
char	**read_moves(int size);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
