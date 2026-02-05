/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:27:34 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/05 18:42:32 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "colors.h"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

void printTest(int test_num, std::string message)
{
	std::cout << BLUE << "\n--" << RESET \
	<< BOLDBLUE << " [TEST " << test_num << "]" << RESET \
	<< BLUE << " - '" << message << "' --\n" << RESET << std::endl;
}

void printSuccess(std::string message)
{
	std::cout << GREEN << "SUCCESS: " << message << RESET << std::endl;
}

void printFail(std::string message)
{
	std::cout << RED << "FAIL: " << message << RESET << std::endl;
}

void printException(const char *exception)
{
	std::cout << YELLOW << "Exception: " << exception << RESET << std::endl;
}

void announceBureaucrat(Bureaucrat& b)
{
	std::cout << "NEW BUREAUCRAT:\n" << b << "\n" << std::endl;
}

void announceForm(AForm& f)
{
	std::cout << "NEW FORM:\n" << f << "\n" << std::endl;
}

void announceFormStatus(AForm& f)
{
	std::cout << "FORM STATUS:\n" << f << "\n" << std::endl;
}

void test1(void)
{
	printTest(1, "intern abuse");
	try
	{
		Intern i;
		AForm* f1;
		AForm* f2;
		AForm* f3;

		f1 = i.makeForm("presidential pardon", "target-t1.1");
		f2 = i.makeForm("robotomy request", "target-t1.2");
		f3 = i.makeForm("shrubbery creation", "target-t1.3");

		if (f1 == NULL || f2 == NULL || f3 == NULL)
		{
			printFail("new form creation failed");
			return ;
		}

		delete f1;
		delete f2;
		delete f3;

		printSuccess("no exception, or error caught");
	}
	catch (std::exception& e)
	{
		printFail("Test caught an unwanted exception");
		printException(e.what());
	}
}

void test2(void)
{
	printTest(2, "unknown form creation");
	
	Bureaucrat b("bureaucrat-t2", 1);
	Intern i;

	announceBureaucrat(b);

	AForm* f = i.makeForm("undefined", "target-t2");

	if (f != NULL)
	{
		printFail("expected form creation failure");
		delete f;
	}
	else
		printSuccess("form creation failed successfully");
}

void test3(void)
{
	printTest(3, "bureaucracy at 100%");
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 45);
		Bureaucrat b3("b3", 137);

		Intern i;

		AForm* pardon = i.makeForm("presidential pardon", "target-t3.1");
		AForm* robotomy = i.makeForm("robotomy request", "target-t3.2");
		AForm* shrubbery = i.makeForm("shrubbery creation", "target-t3.3");

		if (pardon == NULL || robotomy == NULL || shrubbery == NULL)
		{
			printFail("new form creation failed");
			if (pardon)
				delete pardon;
			if (robotomy)
				delete robotomy;
			if (shrubbery)
				delete shrubbery;
			return ;
		}

		std::cout << std::endl;
		announceForm(*pardon);
		announceBureaucrat(b1);
		b1.signForm(*pardon);
		std::cout << std::endl;
		b1.executeForm(*pardon);

		std::cout << std::endl;
		announceForm(*robotomy);
		announceBureaucrat(b2);
		b2.signForm(*robotomy);
		std::cout << std::endl;
		b2.executeForm(*robotomy);
		b2.executeForm(*robotomy);
		b2.executeForm(*robotomy);

		std::cout << std::endl;
		announceForm(*shrubbery);
		announceBureaucrat(b3);
		b3.signForm(*shrubbery);
		std::cout << std::endl;
		b3.executeForm(*shrubbery);

		delete pardon;
		delete robotomy;
		delete shrubbery;

		printSuccess("all forms created and executed successfully");
	}
	catch (std::exception& e)
	{
		printFail("Test caught an unwanted exception");
		printException(e.what());
	}
}

int	main(void)
{
	test1();
	test2();
	test3();
	return (0);
}

