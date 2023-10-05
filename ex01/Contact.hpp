/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:48:57 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/04 18:02:48 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// # include "PhoneBook.hpp"
# include <iostream>


# define _END		"\033[0m"
# define _RED		"\033[0;31m"
# define _GREEN		"\033[0;32m"
# define _YELLOW	"\033[0;33m"
# define _CYAN		"\033[0;36m"
# define _PURPLE	"\033[0;35m"

class	Contact {

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_num;
		std::string _dark_secret;

	public:
		Contact(void);
		~Contact(void);

		void	set_first_name(void);
		void	set_last_name(void);
		void	set_nickname(void);
		void	set_phone_num(void);
		void	set_dark_secret(void);
		void	get_contact_infos(void);

		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		std::string get_phone_num(void);
		std::string get_dark_secret(void);

};

#endif