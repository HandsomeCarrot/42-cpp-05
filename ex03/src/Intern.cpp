/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:31:01 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/05 17:51:57 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.h"
#include "debug.hpp"
#include <iostream>

/**
 * @brief default constructor
*/
Intern::Intern(void)
{
	DEBUG_MSG("Intern default constructor called");
}

/**
 * @brief copy constructor
 *
 * @note This does nothing as this class has not saved anything
 * 
 * @param other object to copy
*/
Intern::Intern(const Intern &other)
{
	(void)other;
	DEBUG_MSG("Intern copy constructor called");
}

/**
 * @brief destructor
*/
Intern::~Intern(void)
{
	DEBUG_MSG("Intern destructor called");
}

/**
 * @brief assignment operator
 *
 * @note This does nothing as this class has not saved anything
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	DEBUG_MSG("Intern assignment operator called");
	return (*this);
}

/**
* @brief searches for 'form_name' in 'form_name_list'
*
* Searches the string array 'form_name_list' for the string 'form_name'.
* If it finds it prints a message to std::cout and returns the index, where
* 'form_name' was found in 'form_name_list'. If it was not found the returned index
* is larger then the amount of forms listed in 'form_name_list'
*
* @param form_name form to search for
* @param form_name_list list of available forms
* @param form_name_list_size amount of forms in 'form_name_list'
*
* @return number <= amount of list elements
 */
static int getFormIndex(const std::string& form_name, const std::string form_name_list[], int form_name_list_size)
{
	int form_index = 0;

	while (form_index < form_name_list_size)
	{
		if (form_name_list[form_index] == form_name)
		{
			std::cout << "Intern creates " << form_name << std::endl;
			break ;
		}
		form_index++;
	}
	return (form_index);
}

/**
* @brief creates new form class based on name
*
* Creates a new AForm pointer to the wanted form, if it exists.
* If it doesn't exist, or isn't implemented, it will print an error
* to std::cerr and return '0'.
*
* @param form_name form to create
* @param form_target the target of the newly created form
*
* @return the new AForm pointer, or 0
*
* @note list of available forms is hard-coded and has to be expanded manually
* in the list and switch statement.
*
* @see getFormIndex()
 */
AForm* Intern::makeForm(const std::string& form_name, const std::string& form_target)
{
	const std::string	form_name_list[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int					form_name_list_size = sizeof(form_name_list) / sizeof(form_name_list[0]);
	int					form_index = getFormIndex(form_name, form_name_list, form_name_list_size);

	switch (form_index)
	{
	case 0:
		return (new ShrubberyCreationForm(form_target));
	case 1:
		return (new RobotomyRequestForm(form_target));
	case 2:
		return (new PresidentialPardonForm(form_target));
	default:
		std::cerr << RED << "Error: " << RESET << form_name << " -> form does not exist!" << std::endl;
	}
	return (NULL);
}
