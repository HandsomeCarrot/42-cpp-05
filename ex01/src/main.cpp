/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:43:11 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 16:44:32 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

void test1(void)
{
	std::cout << BLUE << "\n-- TEST 1 - 'qualified bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("b-t1", 1);
		Form f("f-t1", 2, 150);

		std::cout << "NEW BUREAUCRAT:\n" << b << std::endl;
		std::cout << "\nNEW FORM:\n" << f << std::endl;

		b.signForm(f);

		std::cout << "\nFORM STATUS:\n" << f << std::endl;

		std::cout << GREEN << "SUCCESS: no exception caught" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "FAIL: Test caught an unwanted exception: " << e.what() << RESET << std::endl;
	}
}

void test2(void)
{
	std::cout << BLUE << "\n-- TEST 2 - 'unqualified bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("b-t2", 3);
		Form f("f-t2", 2, 1);

		std::cout << "NEW BUREAUCRAT:\n" << b << std::endl;
		std::cout << "\nNEW FORM:\n" << f << std::endl;

		b.signForm(f);

		std::cout << "\nFORM STATUS:\n" << f << std::endl;

		std::cout << GREEN << "SUCCESS: no exception caught" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "FAIL: Test caught an unwanted exception: " << e.what() << RESET << std::endl;
	}
}

void test3(void)
{
	std::cout << BLUE << "\n-- TEST 3 - 'too unimportant form (sign)' --\n" << RESET << std::endl;
	try
	{
		Form f("f-t3", 200, 150);
		std::cout << RED << "FAIL: code should have triggered exception before this message" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
	}
}

void test4(void)
{
	std::cout << BLUE << "\n-- TEST 4 - 'too important form (sign)' --\n" << RESET << std::endl;
	try
	{
		Form f("f-t4", 0, 150);
		std::cout << RED << "FAIL: code should have triggered exception before this message" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
	}
}

void test5(void)
{
	std::cout << BLUE << "\n-- TEST 5 - 'too unimportant form (exec)' --\n" << RESET << std::endl;
	try
	{
		Form f("f-t5", 150, 151);
		std::cout << RED << "FAIL: code should have triggered exception before this message" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
	}
}

void test6(void)
{
	std::cout << BLUE << "\n-- TEST 6 - 'too important form (exec)' --\n" << RESET << std::endl;
	try
	{
		Form f("f-t6", 150, 0);
		std::cout << RED << "FAIL: code should have triggered exception before this message" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
	}
}
int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return (0);
}
