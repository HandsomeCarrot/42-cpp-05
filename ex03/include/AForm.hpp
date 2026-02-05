/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:02:35 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 19:02:48 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class AForm
{
private:

	const std::string	name_;
	const std::string	target_; //ex02
	bool				signed_;
	const int			min_sign_grade_;
	const int			min_exec_grade_;

	virtual void	startExecution(void) const = 0; //ex02
public:
	AForm(void);
	AForm(std::string name, std::string target, int min_sign_grade, int min_exec_grade);
	AForm(const AForm &other);
	virtual ~AForm(void);

	AForm	&operator=(const AForm &other);

	const std::string&	getName(void) const;
	const std::string&	getTarget(void) const; //ex02
	bool				isSigned(void) const;
	int					getMinSignGrade(void) const;
	int					getMinExecGrade(void) const;

	void	beSigned(const Bureaucrat &b);

	class GradeTooLowException: public std::exception
	{
		virtual const char* what(void) const throw()
		{
			return ("AForm: Grade too low");
		}
	};

	class GradeTooHighException: public std::exception
	{
		virtual const char* what(void) const throw()
		{
			return ("AForm: Grade too high");
		}
	};

	void	execute(const Bureaucrat& executor) const; //ex02

	class FormNotSignedException: public std::exception //ex02
	{
		virtual const char* what(void) const throw()
		{
			return ("Form is not signed");
		}
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm &c);

#endif /* FORM_HPP */
