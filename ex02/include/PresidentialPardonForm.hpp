/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:48:05 by vpoka             #+#    #+#             */
/*   Updated: 2026/01/23 16:13:16 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "debug.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm: public AForm
{
private:
	virtual void	startExecution(void) const;

	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
