/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:23 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/05 11:26:25 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::get_contact_infos(void) {
	this->set_first_name();
	this->set_last_name();
	this->set_nickname();
	this->set_phone_num();
	this->set_dark_secret();
	return ;
}

void	Contact::set_first_name(void) {
	this->_first_name = readline("First name:\t", _CYAN);
	return ;
}

void	Contact::set_last_name(void) {
	this->_last_name = readline("Last name:\t", _CYAN);
	return ;
}

void	Contact::set_nickname(void) {
	this->_nickname = readline("Nickname:\t", _CYAN);
	return ;
}

void	Contact::set_phone_num(void) {
	this->_phone_num = readline("Phone number:\t", _CYAN);
	return ;
}

void	Contact::set_dark_secret(void) {
	this->_dark_secret = readline("Darkest secret:\t", _CYAN);
	return ;
}

std::string	Contact::get_first_name(void) {
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) {
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) {
	return (this->_nickname);
}

std::string	Contact::get_phone_num(void) {
	return (this->_phone_num);
}

std::string	Contact::get_dark_secret(void) {
	return (this->_dark_secret);
}