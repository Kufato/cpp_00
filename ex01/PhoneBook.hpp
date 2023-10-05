/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:37:19 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/04 18:02:53 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>

# define _END		"\033[0m"
# define _RED		"\033[0;31m"
# define _GREEN		"\033[0;32m"
# define _YELLOW	"\033[0;33m"
# define _CYAN		"\033[0;36m"
# define _PURPLE	"\033[0;35m"

class	PhoneBook {

	private:
		int		_nb_contact;
		int		_oldest_contact;
		Contact	_contacts[8];

		int		erase_contact(void);
		void	add(void);
		void	search(void);
		void	display(void);
		void	draw_phonebook(Contact *contacts);	

	public:
		PhoneBook(void);
		~PhoneBook(void);

		int routine(void);
};

std::string	readline(std::string prompt, const char *color);

#endif