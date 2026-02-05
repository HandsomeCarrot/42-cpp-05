/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:43:23 by vpoka             #+#    #+#             */
/*   Updated: 2026/01/12 16:30:33 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "debug.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
protected:
	const std::string	name_;
	int					grade_;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat(void);

	Bureaucrat &operator=(const Bureaucrat &other);

	std::string	getName(void) const;
	int			getGrade(void) const;

	void	promote(void); // grade: 2 -> 1
	void	demote(void); // grade: 2 -> 3

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &c);

#endif /* BUREAUCRAT_HPP */
