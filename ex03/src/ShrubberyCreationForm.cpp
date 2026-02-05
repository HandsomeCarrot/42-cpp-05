/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:25:50 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/04 18:58:48 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "debug.hpp"
#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief default constructor
*/
ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation Form", "undefined", 145, 137)
{
	DEBUG_MSG("ShrubberyCreationForm default constructor called");
}

/**
 * @brief parameterized constructor
 *
 * @param target the target of the form
*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation Form", target, 145, 137)
{
	DEBUG_MSG("ShrubberyCreationForm parameterized constructor called");
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other)
{
	DEBUG_MSG("ShrubberyCreationForm copy constructor called");
}

/**
 * @brief destructor
*/
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	DEBUG_MSG("ShrubberyCreationForm destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	DEBUG_MSG("ShrubberyCreationForm assignment operator called");
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

/**
* @brief creates a file with the given file name.
*
* Tries to open the given file stream with write permissions,
* if does not exist it will create the file. If opening the file fails
* then it will print an error message and return 0. If the operation succeeds
* it will return 1.
*
* @param fileName the file name of the given file stream
* @param file the file stream to open
*
* @return 0 on failure, 1 on success
 */
static int createFile(std::string &fileName, std::ofstream &file)
{
	file.open(fileName.c_str());

	if (!file.is_open())
	{
		std::cerr << RED << "Error: " << RESET \
		<< fileName << " -> file could not be opened!" << std::endl;
		return (0);
	}
	return (1);
}

/**
* @brief writes ASCII trees into the given file stream
*
* Checks if the given file stream 'file' is open, if not it prints an error
* message and cancels execution.
* If the file stream is open it writes the ascii trees into the file stream.
* After that it will print an error message if the file stream failed.
*
* @param fileName the file name of the given file stream
* @param file the file stream to open
 */
static void writeToFile(std::string &fileName, std::ofstream &file)
{
	if (!file.is_open())
	{
		std::cerr << RED << "Error: " << RESET \
		<< fileName << " -> can not write to closed file!" << std::endl;
		return ;
	}

	file << "      ^        ^           ^      ^      " << std::endl;
	file << "    ^/|\\    ^ /|\\    ^    /|\\    /|\\ " << std::endl;
	file << "   /|/|\\ ^ /|\\/|\\   /| ^  /|\\    /|\\" << std::endl;
	file << "   /| ^ /|\\/|\\/ ^ ^ /|/|\\ /|\\ ^  /|\\" << std::endl;
	file << "  ^ |/|\\/|\\ ^  /|\\| ^ /|\\    /|\\    " << std::endl;
	file << " /|\\ /|\\/|\\/|\\ /|\\|/|\\/|\\    /|\\ " << std::endl;
	file << " /|\\ /|\\   /|\\ /|\\|/|\\       /|\\   " << std::endl;
	file << " /|\\     ^ /|\\ ^   /|\\                " << std::endl;
	file << "    ^   /|\\   /|\\             ^        " << std::endl;
	file << "   /|\\  /|\\   /|\\      ^     /|\\     " << std::endl;
	file << "   /|\\  /|\\   /|\\     /|\\    /|\\    " << std::endl;
	file << "   /|\\                /|\\    /|\\      " << std::endl;
	file << "                      /|\\               " << std::endl;

	if (file.fail())
	{
		std::cerr << RED << "Error: " << RESET \
		<< fileName << " -> failed to write to file!" << std::endl;
	}
}

/**
 * @note Required grades: sign 145, exec 137
 *
 * @brief creates a file <target>_shrubbery
 * in the working directory and writes ASCII trees inside it.
 *
 * First checks if the file exists. If it doesn't exist, it will go ahead to
 * create it and write the ascii trees inside it. It will close the file stream
 * before returning.
 */
void	ShrubberyCreationForm::startExecution(void) const
{
	std::string fileName = getTarget() + "_shrubbery";
	std::ofstream file;

	if (!createFile(fileName, file))
		return ;
	writeToFile(fileName, file);
	file.close();
}
