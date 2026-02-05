/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:02:41 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 19:02:46 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/**
 * @brief default constructor
*/
AForm::AForm(void) :
	name_("undefined"),
	target_("undefined"),
	signed_(false),
	min_sign_grade_(150),
	min_exec_grade_(150)
{
	DEBUG_MSG("AForm default constructor called");
}

/**
 * @brief parameterized constructor
*/
AForm::AForm(std::string name, std::string target, int min_sign_grade, int min_exec_grade) :
	name_(name),
	target_(target),
	signed_(false),
	min_sign_grade_(min_sign_grade),
	min_exec_grade_(min_exec_grade)
{
	DEBUG_MSG("AForm parameterized constructor called");
	if (min_sign_grade < 1 || min_exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (min_sign_grade > 150 || min_exec_grade > 150)
		throw AForm::GradeTooLowException();
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
AForm::AForm(const AForm &other) :
	name_(other.getName()),
	target_(other.getTarget()),
	signed_(other.isSigned()),
	min_sign_grade_(other.getMinSignGrade()),
	min_exec_grade_(other.getMinExecGrade())
{
	DEBUG_MSG("AForm copy constructor called");
}

/**
 * @brief destructor
*/
AForm::~AForm(void)
{
	DEBUG_MSG("AForm destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
AForm	&AForm::operator=(const AForm &other)
{
	DEBUG_MSG("AForm assignment operator called");
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
std::ostream	&operator<<(std::ostream &os, const AForm &c)
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

const std::string& AForm::getName(void) const
{
	return (name_);
}

const std::string& AForm::getTarget(void) const
{
	return (target_);
}

bool AForm::isSigned(void) const
{
	return (signed_);
}

int AForm::getMinSignGrade(void) const
{
	return (min_sign_grade_);
}

int AForm::getMinExecGrade(void) const
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
 * @throw AForm::GradeTooLowException
 */
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getMinSignGrade())
		this->signed_ = true;
	else
		throw AForm::GradeTooLowException();
}

/**
 * @brief tries to execute the form
 *
 * Checks the requirements for the execution of the form:
 * 
 * - form has to be signed.
 * 
 * - 'executor' has to at least have minimum execution grade.
 * 
 * If all requirements are met it executes the form by calling startExecution()
 * 
 * @param executor bureaucrat who tries to execute the form
 * 
 * @throw AForm::FormNotSignedException
 * -> if form is not signed
 * @throw AForm::GradeTooLowException
 * -> if 'executors' grade is lower then forms minimum execution grade
 */
void	AForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getMinExecGrade())
		throw (AForm::GradeTooLowException());
	startExecution();
}
