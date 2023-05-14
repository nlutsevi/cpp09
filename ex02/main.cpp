/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:42:29 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/14 22:20:08 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int		main(int argc, char **argv) {
	try {
		if (argc == 1)
			throw std::runtime_error("No argumets privided.");
		else {
			PmergeMe pmm(argc, argv);
			pmm.processSort();
		}
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}