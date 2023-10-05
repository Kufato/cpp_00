/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:01:07 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/05 12:52:08 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {

	std::string	str;
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; argv[i]; i++) {
			str.append(argv[i]);
			for (int j = 0; str[j]; j++)
				str[j] = (char)std::toupper(str[j]);
		}
	}
	std::cout << str << std::endl;
	return (0);
}
