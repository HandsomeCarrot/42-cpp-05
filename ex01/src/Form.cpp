/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:02:41 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 16:48:19 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/**
 * @brief default constructor
*/
Form::Form(void) :
	name_("undefined"),
	signed_(false),
	min_sign_grade_(150),
	min_exec_grade_(150)
{
	DEBUG_MSG("Form default constructor called");
}

/**
 * @brief parameterized constructor
*/
Form::Form(std::string name, int min_sign_grade, int min_exec_grade) :
	name_(name),
	signed_(false),
	min_sign_grade_(min_sign_grade),
	min_exec_grade_(min_exec_grade)
{
	DEBUG_MSG("Form parameterized constructor called");
	if (min_sign_grade < 1 || min_exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (min_sign_grade > 150 || min_exec_grade > 150)
		throw Form::GradeTooLowException();
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
Form::Form(const Form &other) :
	name_(other.getName()),
	signed_(other.isSigned()),
	min_sign_grade_(other.getMinSignGrade()),
	min_exec_grade_(other.getMinExecGrade())
{
	DEBUG_MSG("Form copy constructor called");
}

/**
 * @brief destructor
*/
Form::~Form(void)
{
	DEBUG_MSG("Form destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
Form	&Form::operator=(const Form &other)
{
	DEBUG_MSG("Form assignment operator called");
	if (this != &other)
	{
		this->signed_ = other.isSigned();
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
std::ostream	&operator<<(std::ostream &os, const Form &c)
{
	os << "Form " << c.getName() << std::endl;
	os << " - status:  ";
	if (!c.isSigned())
		os << "not ";
	os << "signed" << std::endl;
	os << " - minimum grade to sign:  " << c.getMinSignGrade() << std::endl;
	os << " - minimum grade to execute:  " << c.getMinExecGrade() << std::endl;
	return (os);
}

const std::string& Form::getName(void) const
{
	return (name_);
}

bool Form::isSigned(void) const
{
	return (signed_);
}

int Form::getMinSignGrade(void) const
{
	return (min_sign_grade_);
}

int Form::getMinExecGrade(void) const
{
	return (min_exec_grade_);
}

/**
 * @brief tries to set form status to signed
 * 
 * Checks if the given bureaucrat has a high enough grade to sign
 * 'this' form. If clearance is high enough signage status is set to true.
 * 
 * @param b the bureaucrat who tries to sign the form
 * 
 * @throw Form::GradeTooLowException (std::exception)
 */
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getMinSignGrade())
		this->signed_ = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form: Grade too low");
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Form: Grade too high");
}
