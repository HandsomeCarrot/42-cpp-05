/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:30:58 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/05 14:25:30 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
private:
	typedef AForm* (*formCreator)(const std::string &);
public:
	Intern(void);
	Intern(const Intern &other);
	~Intern(void);

	Intern&	operator=(const Intern &other);

	AForm*	makeForm(const std::string &formName, const std::string &target);
};

#endif /* INTERN_HPP */
