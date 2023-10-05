/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:19:23 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/05 11:40:35 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	readline(std::string prompt, const char *color) {
	std::string	buff;

	do {
		std::cout << color << prompt << _END << std::flush;
		std::getline(std::cin, buff);
		if (std::cin.eof())
			exit(1);
		if (buff.empty())
			std::cout << _RED << "Empty answers are invalid" << _END << std::endl;
	} while (buff.empty());
	return (buff);
}