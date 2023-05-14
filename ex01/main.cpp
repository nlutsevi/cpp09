/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:39:11 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/14 20:18:50 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"


int		main(int argc, char **argv) {
	try {
		if (argc == 2) {
			RPN r(argv[1]);
			std::cout << r.getResult() << std::endl;
		}
			
		else
			throw std::runtime_error("Wrong number of arguments.");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}