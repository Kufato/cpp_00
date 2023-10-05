/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:49:01 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/05 12:41:13 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_nb_contact = 0;
	this->_oldest_contact = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Bye, have a nice day !" << std::endl;
	return ; 
}

void	PhoneBook::display(void) {
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < this->_nb_contact; i++) {
		std::cout << "|         " << i;
		if (this->_contacts[i].get_first_name().length() > 10)
			std::cout << "|" << this->_contacts[i].get_first_name().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].get_first_name();
		if (this->_contacts[i].get_last_name().length() > 10)
			std::cout << "|" << this->_contacts[i].get_last_name().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].get_last_name();
		if (this->_contacts[i].get_nickname().length() > 10)
			std::cout << "|" << this->_contacts[i].get_nickname().substr(0, 9) << ".|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].get_nickname() << "|" << std::endl;
		std::cout << "+----------+----------+----------+----------+" << std::endl;
	}
}

void	PhoneBook::search(void) {
	int			index;
	std::string	buff;

	if (this->_nb_contact == 0) {
		std::cout << _RED << "Warning, no contact is registered" << _END << std::endl;
		return ;
	}
	do {
		this->display();
		std::cout << _GREEN << "Please enter the desired contact index:" << _END << std::endl;
		buff = readline("$> ", _END);
		index = std::atoi(buff.c_str());
		if (buff.length() > 1 || !isdigit(buff[0]))
			std::cout << _RED << "Sorry, you must enter a number" << _END << std::endl;
		if (index < 0 || index >= this->_nb_contact)
			std::cout << _RED << "Sorry but there is no contact at this index" << _END << std::endl;
	} while ((index < 0 || index >= this->_nb_contact) || (buff.length() > 1 || !isdigit(buff[0])));
	std::cout << _GREEN << "First name:\t" << _END << this->_contacts[index].get_first_name() << std::endl;
	std::cout << _GREEN << "Last name:\t" << _END << this->_contacts[index].get_last_name() << std::endl;
	std::cout << _GREEN << "Nickname:\t" << _END << this->_contacts[index].get_nickname() << std::endl;
	std::cout << _GREEN << "Phone number:\t" << _END << this->_contacts[index].get_phone_num() << std::endl;
	std::cout << _GREEN << "Darkest secret:\t" << _END << this->_contacts[index].get_dark_secret() << std::endl;
}

void	PhoneBook::add(void) {
	Contact	contact;

	contact.get_contact_infos();
	if (this->_nb_contact == 8) {
		if (erase_contact())
			return ;
		this->_contacts[_oldest_contact] = contact;
		this->_oldest_contact++;
		if (this->_oldest_contact == 8)
			this->_oldest_contact = 0;
	}
	else {
		this->_contacts[_nb_contact] = contact;
		this->_nb_contact++;
	}
	return ;
}

int PhoneBook::erase_contact(void) {
	Contact		oldest_contact;
	std::string	buff;

	oldest_contact = this->_contacts[this->_oldest_contact];
	std::cout << _RED << "Warning: you will delete the following contact:\t" << _END;
	std::cout << oldest_contact.get_first_name() << " ";
	std::cout << oldest_contact.get_last_name() << std::endl;
	std::cout << _GREEN << "Continue [y/n]" << _END << std::endl;
	buff = readline("$> ", _END);
	do {
		if (buff == "n" || buff == "N")
			return (1);
		else if (buff == "y" || buff == "Y") 
			return (0);
		if (buff.empty() || buff != "n" || buff != "N" || buff != "y" || buff != "Y")
			std::cout << _RED << "Invalid choice" << _END << std::endl;
	} while (buff.empty() || buff != "n" || buff != "N" || buff != "y" || buff != "Y");
	return (0);
}

int PhoneBook::routine(void) {
	std::string	buff;

	buff = readline("$> ", _END);
	if (buff != "ADD" && buff != "SEARCH" && buff != "EXIT")
		std::cout << _RED << "Sorry, but you can't write that here" << _END << std::endl;
	if (buff == "ADD")
		this->add();
	else if (buff == "SEARCH")
		this->search();
	else if (buff == "EXIT")
		return (0);
	return (1);
}