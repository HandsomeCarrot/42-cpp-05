/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:08:25 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 19:04:51 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "debug.hpp"
#include <cstdlib> //srand(), rand()
#include <ctime>

/**
 * @brief default constructor
*/
RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("Robotomy Request Form", "undefined", 72, 45)
{
	DEBUG_MSG("RobotomyRequestForm default constructor called");
}

/**
 * @brief parameterized constructor
*/
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", target, 72, 45)
{
	DEBUG_MSG("RobotomyRequestForm parameterized constructor called");
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other)
{
	DEBUG_MSG("RobotomyRequestForm copy constructor called");
}

/**
 * @brief destructor
*/
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	DEBUG_MSG("RobotomyRequestForm destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	DEBUG_MSG("RobotomyRequestForm assignment operator called");
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void generateRandomSeed(void)
{
	static bool	seeded = false;

	if (!seeded)
	{
		time_t seed = std::time(0);
		if (seed == (std::time_t)(-1))
			seed = 123456789;
		std::srand(seed);
		DEBUG_MSG("generated random seed");
		seeded = true;
	}
}

static bool flipCoin(void)
{
	generateRandomSeed();
	DEBUG_MSG("flipping coin");
	return (rand() % 2 == 0);
}

/**
 * Required grades: sign 72, exec 45
 *
 * Makes some drilling noises, then informs that <target> has been
 * robotomized successfully 50% of the time.
 * Otherwise, it informs that the robotomy failed.
 */
void	RobotomyRequestForm::startExecution(void) const
{
	std::cout << "<drilling noise>\n....\n<drilling noise>" << std::endl;
	if (flipCoin())
		std::cout << this->getTarget() << " robotomized successfully" << std::endl;
	else
		std::cout << "robotomy on " << this->getTarget() << " failed" << std::endl;
}
