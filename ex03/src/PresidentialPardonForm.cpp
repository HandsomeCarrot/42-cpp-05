/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:48:01 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 19:04:12 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.hpp"
#include "PresidentialPardonForm.hpp"

/**
 * @brief default constructor
*/
PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential Pardon Form", "undefined", 25, 5)
{
	DEBUG_MSG("PresidentialPardonForm default constructor called");
}

/**
 * @brief parameterized constructor
*/
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", target, 25, 5)
{
	DEBUG_MSG("PresidentialPardonForm parameterized constructor called");
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other)
{
	DEBUG_MSG("PresidentialPardonForm copy constructor called");
}

/**
 * @brief destructor
*/
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	DEBUG_MSG("PresidentialPardonForm destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	DEBUG_MSG("PresidentialPardonForm assignment operator called");
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

/**
 * @brief prints a message
 */
void PresidentialPardonForm::startExecution(void) const
{
	std::cout << "Zaphod Beeblebrox pardoned " << this->getTarget() << std::endl;
}
