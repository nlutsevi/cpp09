/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:41:35 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/18 20:38:27 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"


int     main(int argc, char **argv) {
    std::ifstream   inputData;
    std::string     line;
    bool isFirstLine = true;  
    
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    try {      
        BitcoinExchange be("data.csv");
        inputData.open(argv[1]);
        if (!inputData.is_open())
            std::cout << "Error: could not open file." << std::endl;
        
        while (std::getline(inputData, line)) {
            std::istringstream    iss(line);
            std::string           dateStr;
            float                 bitcoinQuantity;
			std::string			  extraCheck;

            if (isFirstLine) {
                isFirstLine = false;
                continue;
            }
            if (std::getline(iss, dateStr, '|') && iss >> bitcoinQuantity) {
				try {
                    //Remove trailing whitespces from date
                    dateStr.erase(dateStr.find_last_not_of(" \n\r\t")+1);
					if (!be.isInputDateValid(dateStr)) {
                        std::cout << "Error: bad input => " << dateStr << std::endl;
                    }
                    else if (be.isBitcoinQuantityValid(bitcoinQuantity)) {
                        float   rate;
                        float   result;

                        rate = be.getRateOnDate(dateStr);
                        result = rate * bitcoinQuantity;
                        std::cout << dateStr << " => " << bitcoinQuantity << " = " << result << std::endl;
                        }
                    }
                catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else
                std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    exit(0);
}