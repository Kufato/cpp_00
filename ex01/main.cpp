/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:56 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/04 17:05:32 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook	phonebook;
	std::cout << "Welcome to the super phonebook !" << std::endl;
	std::cout << "A not-so-crazy phonebook" << std::endl;
	std::cout << "You can choose between three super actions" << std::endl;
	std::cout << _CYAN <<  "ADD" << _END << ": you can add a new contact (so crazy)" << std::endl;
	std::cout << _GREEN << "SEARCH" << _END <<": you can search an existing contact (more crazy)" << std::endl;
	std::cout << _RED << "EXIT" << _END << ": this one just closes the program" << std::endl;
	while (phonebook.routine());
	return (0);
}