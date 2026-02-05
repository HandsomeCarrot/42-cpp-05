/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:08:21 by vpoka             #+#    #+#             */
/*   Updated: 2026/01/26 20:03:28 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "debug.hpp"
# include <iostream>
# include <string>
# include <cstdlib> //srand(), rand()
# include <ctime>

class RobotomyRequestForm: public AForm
{
private:
	virtual void	startExecution(void) const;

	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
