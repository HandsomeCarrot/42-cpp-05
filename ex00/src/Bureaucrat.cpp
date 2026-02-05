/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:43:15 by vpoka             #+#    #+#             */
/*   Updated: 2026/01/15 17:03:08 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/**
 * @brief default constructor
*/
Bureaucrat::Bureaucrat(void) :
	name_("default name"),
	grade_(150)
{
	DEBUG_MSG("Bureaucrat default constructor called");
}

/**
 * @brief parameterized constructor
*/
Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	name_(name),
	grade_(grade)
{
	DEBUG_MSG("Bureaucrat parameterized constructor called");
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

/**
 * @brief copy constructor
 *
 * @param other object to copy
*/
Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name_(other.getName()),
	grade_(other.getGrade())
{
	DEBUG_MSG("Bureaucrat copy constructor called");
}

/**
 * @brief destructor
*/
Bureaucrat::~Bureaucrat(void)
{
	DEBUG_MSG("Bureaucrat destructor called");
}

/**
 * @brief assignment operator
 *
 * @param other object to assign from
 *
 * @return reference to 'this' object
*/
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	DEBUG_MSG("Bureaucrat assignment operator called");
	if (this != &other)
	{
		this->grade_ = other.getGrade();
	}
	return (*this);
}

/**
 * @brief output stream operator
 *
 * @param os reference to the outputstream
 * @param class reference to the class object
 *
 * @return reference to the output stream
*/
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &c)
{
	os << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return (os);
}

/**
 * @brief returns the name
 *
 * @return name of the object
 */
std::string Bureaucrat::getName(void) const
{
	return (this->name_);
}

/**
 * @brief returns the grade
 *
 * @return grade of the object
 */
int Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}

/**
 * @brief increases the grade of the object
 *
 * If the grade of the object is 50, it will be 'increased' to 49.
 * - 1 = highest grade
 * - 150 = lowest grade
 *
 * @note throws the 'Bureaucrat::GradeTooHighException' exception, if the grade
 *       is already 1.
 */
void Bureaucrat::promote(void)
{
	if (this->getGrade() <= 1)
	{
		throw GradeTooHighException();
	}
	else
		this->grade_--;
}

/**
 * @brief decreases the grade of the object
 *
 * If the grade of the object is 50, it will be 'decreased' to 51.
 * - 1 = highest grade
 * - 150 = lowest grade
 *
 * @note throws the 'Bureaucrat::GradeTooLowException' exception, if the grade
 *       is already 150.
 */
void Bureaucrat::demote(void)
{
	if (this->getGrade() >= 150)
	{
		throw GradeTooLowException();
	}
	else
		this->grade_++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade is too high (grade < 1)");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade is too low (grade > 150)");
}
