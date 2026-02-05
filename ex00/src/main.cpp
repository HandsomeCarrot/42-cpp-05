/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:43:11 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 16:15:18 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

void test1(void)
{
	std::cout << BLUE << "\n-- TEST 1 - 'overambitious bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("t1", 2);
		std::cout << b << " (creation)" << std::endl;
		b.promote();
		std::cout << b << " (first promotion)" << std::endl;
		b.promote();
		std::cout << b << " (second promotion)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << RED << "Test FAILED: should return an exception" << RESET << std::endl;
}

void test2(void)
{
	std::cout << BLUE << "\n-- TEST 2 - 'slacking bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("t2", 149);
		std::cout << b << " (creation)" << std::endl;
		b.demote();
		std::cout << b << " (first demotion)" << std::endl;
		b.demote();
		std::cout << b << " (second demotion)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << RED << "Test FAILED: should return an exception" << RESET << std::endl;
}

void test3(void)
{
	std::cout << BLUE << "\n-- TEST 3 - 'unqualified bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("t3", 1000);
		std::cout << b << " (creation)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << RED << "Test FAILED: should return an exception" << RESET << std::endl;
}

void test4(void)
{
	std::cout << BLUE << "\n-- TEST 4 - 'overqualified bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("t4", 0);
		std::cout << b << " (creation)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << GREEN << "SUCCESS: Test caught an exception: " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << RED << "Test FAILED: should return an exception" << RESET << std::endl;
}

void test5(void)
{
	std::cout << BLUE << "\n-- TEST 5 - 'average bureaucrat' --\n" << RESET << std::endl;
	try
	{
		Bureaucrat b("t5", 75);
		std::cout << b << " (creation)" << std::endl;
		b.promote();
		std::cout << b << " (first promotion)" << std::endl;
		b.promote();
		std::cout << b << " (second promotion)" << std::endl;
		b.demote();
		std::cout << b << " (first demotion)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Test FAILED: Test caught an exception: " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "SUCCESS: no exception, as expected" << RESET << std::endl;
}

void test6_crash(void)
{
	std::cout << BLUE << "\n-- TEST 6 - 'triggered bureaucrat' --\n" << RESET << std::endl;
	
	Bureaucrat b("t6", -5);
	std::cout << RED << "FAIL: should not print this" << b << RESET << std::endl;
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	// test6_crash();
	return (0);
}
