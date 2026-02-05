/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:15:00 by vpoka             #+#    #+#             */
/*   Updated: 2026/01/19 19:32:31 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << x << std::endl
# else
#  define DEBUG_MSG(x)
# endif

#endif /* DEBUG_HPP */
