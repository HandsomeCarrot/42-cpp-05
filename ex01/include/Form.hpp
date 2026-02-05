/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:02:35 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 16:44:15 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
# include "debug.hpp"
# include <iostream>
# include <exception>

class Form
{
private:
	const std::string	name_;
	bool				signed_;
	const int			min_sign_grade_;
	const int			min_exec_grade_;
public:
	Form(void);
	Form(std::string name, int min_sign_grade, int min_exec_grade);
	Form(const Form &other);
	~Form(void);

	Form	&operator=(const Form &other);

	const std::string&	getName(void) const;
	bool				isSigned(void) const;
	int					getMinSignGrade(void) const;
	int					getMinExecGrade(void) const;

	void	beSigned(const Bureaucrat &b);

	class GradeTooLowException: public std::exception
	{
		virtual const char* what(void) const throw();
	};

	class GradeTooHighException: public std::exception
	{
		virtual const char* what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Form &c);

#endif /* FORM_HPP */
