/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:43:23 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 19:02:59 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

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

	void	signForm(AForm &form);

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

	void	executeForm(const AForm& form) const; //ex02
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &c);

#endif /* BUREAUCRAT_HPP */
