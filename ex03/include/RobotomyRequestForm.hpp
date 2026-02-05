/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:08:21 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 19:04:55 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>


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
