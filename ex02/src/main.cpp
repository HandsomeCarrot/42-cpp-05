/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:27:34 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 16:45:40 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

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
	printTest(1, "successful Presidential Pardon");
	try
	{
		Bureaucrat b("bureaucrat-t1", 1);
		PresidentialPardonForm p("target-t1");

		announceBureaucrat(b);
		announceForm(p);

		b.signForm(p);
		std::cout << std::endl;
		b.executeForm(p);

		announceFormStatus(p);

		printSuccess("no exception caught");
	}
	catch (std::exception& e)
	{
		printFail("Test caught an unwanted exception");
		printException(e.what());
	}
}

void test2(void)
{
	printTest(2, "failed Presidential Pardon");
	try
	{
		Bureaucrat b("bureaucrat-t2", 6);
		PresidentialPardonForm p("target-t2");

		announceBureaucrat(b);
		announceForm(p);

		b.signForm(p);
		std::cout << std::endl;
		b.executeForm(p);

		announceFormStatus(p);

		printSuccess("exception caught internally");
	}
	catch (std::exception& e)
	{
		printFail("Test caught an unwanted exception");
		printException(e.what());
	}
}

void test3(void)
{
	printTest(3, "mass robotomization");
	try
	{
		Bureaucrat b("bureaucrat-t3", 45);
		announceBureaucrat(b);

		const int numForms = 5; //* set to amount of requests you want

		RobotomyRequestForm* forms[numForms];
		for (int i = 0; i < numForms; i++)
		{
			std::stringstream name;
			name << "target-t3." << (i + 1);
			forms[i] = new RobotomyRequestForm(name.str());
		}

		std::cout << "Created " << numForms << " RobotomyRequestForm(s)" << std::endl;
		announceForm(*forms[0]);

		for (int i = 0; i < numForms; i++)
			b.signForm(*forms[i]);

		std::cout << std::endl;
		announceFormStatus(*forms[0]);

		for (int i = 0; i < numForms; i++)
		{
			b.executeForm(*forms[i]);
			std::cout << std::endl;
		}

		for (int i = 0; i < numForms; i++)
			delete forms[i];

		printSuccess("no exception caught");
	}
	catch (std::exception& e)
	{
		printFail("Test caught an unwanted exception");
		printException(e.what());
	}
}

void test4(void)
{
	printTest(4, "a Shrubbery Creation");
	try
	{
		Bureaucrat b("bureaucrat-t4", 45);
		ShrubberyCreationForm s("target-t4");

		announceBureaucrat(b);
		announceForm(s);

		b.signForm(s);
		std::cout << std::endl;
		b.executeForm(s);

		announceFormStatus(s);

		printSuccess("no exception caught");
	}
	catch (std::exception& e)
	{
		printFail("Test caught an unwanted exception");
		printException(e.what());
	}
}

void test5(void)
{
	printTest(5, "double shrubb");
	try
	{
		Bureaucrat b("bureaucrat-t5", 45);
		ShrubberyCreationForm s1("target-t5");
		ShrubberyCreationForm s2("target-t5");

		announceBureaucrat(b);
		announceForm(s1);
		announceForm(s2);

		b.signForm(s1);
		b.signForm(s2);
		std::cout << std::endl;
		b.executeForm(s1);
		b.executeForm(s2);

		announceFormStatus(s1);
		announceFormStatus(s2);

		printSuccess("no exception caught");
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
	test4();
	test5();
	return (0);
}
