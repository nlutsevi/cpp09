/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:54:18 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/22 19:21:57 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const& dbFileName) : _dbFileName(dbFileName) {
    try {
        parseDB();
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    *this = src;
}


BitcoinExchange         &BitcoinExchange::operator=(const BitcoinExchange& src) {
    this->_dbFileName = src.getDbFileName();
    return (*this);
}


BitcoinExchange::~BitcoinExchange() {};


void                    BitcoinExchange::parseDB() {
    std::ifstream                   file;
    std::string                     line;
    std::map<std::string, float>    _exchangeRates;

    file.open(this->_dbFileName);
    if (!file.is_open())
        throw std::runtime_error("Unable to open file with exchange rates data.");
    while (std::getline(file, line)) {
        std::istringstream  iss(line);
        std::string         dateStr;
        float               exchangeRate;

        if (std::getline(iss, dateStr, ',') && iss >> exchangeRate) {
            this->_exchangeRates.insert(std::pair<std::string, float>(dateStr, exchangeRate));
        }
    }
}


std::string               BitcoinExchange::getDbFileName(void) const {
    return (this->_dbFileName);
}


std::map<std::string, float>    BitcoinExchange::getExchangeRates(void) const {
    return (this->_exchangeRates);
}


bool                            BitcoinExchange::isInputValidFormat(std::string input) const {
    unsigned long i2 = 0;

    input.erase(input.find_last_not_of(" \n\r\t")+1);
    for (unsigned long i = 10; i < input.length(); i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\r' || input[i] == '\t')
            continue;
        else if (input[i] == '|') {
            i2 = i + 1;
            break;
        }
    }
    for (unsigned long i = i2; i < input.length(); i++) {
        if (!(std::isdigit(input[i]) || input[i] == ' ' || input[i] == '\n' || input[i] == '\r' || \
                input[i] == '\t' || input[i] == '.' || input[i] == '-')) {
            return false;
        }
    }
    return true;
}

bool                            BitcoinExchange::isInputDateValid(std::string dateStr) const {
    // Regular expression pattern: yyyy-mm-dd
    std::regex regexPattern("\\d{4}-\\d{2}-\\d{2}");

    if (std::regex_match(dateStr, regexPattern) == 1) {
		std::string year = dateStr.substr(0, 4);
    	std::string month = dateStr.substr(5, 2);
    	std::string day = dateStr.substr(8, 2);

		if (std::atoi(year.c_str()) >= 1 \
			&& std::atoi(month.c_str()) >= 1 && std::atoi(month.c_str()) <= 12 \
			&& std::atoi(day.c_str()) >= 1 && std::atoi(day.c_str()) <= 31) {
				return true;
			}
	}
    return false;
}


bool                            BitcoinExchange::isBitcoinQuantityValid(float bitcoinQuantity) const {
    if (bitcoinQuantity < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }  
    if (bitcoinQuantity > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    } 
    return true;
}


float                           BitcoinExchange::getRateOnDate(const std::string& dateStr) const {
    std::map<std::string, float>::const_iterator    it = this->_exchangeRates.find(dateStr);
    //if exact date not found
    if (it == this->_exchangeRates.end()) {
        //find the first smallest respective date
        std::map<std::string, float>::const_iterator lower = this->_exchangeRates.lower_bound(dateStr);

    //the target date is smaller than all dates in the map, returns the first date in the map
    if (lower == this->_exchangeRates.begin())
        //std::cout << lower->first << std::endl;
        return lower->second;

    //the target date is greater than all dates in the map, returns the last date in the map
    if (lower == this->_exchangeRates.end())
        //std::cout << lower->first << std::endl;
        return std::prev(lower)->second;

    //the target date is between two dates in the map, returns the date before the lower bound
    if (dateStr < lower->first)
        //std::cout << lower->first << std::endl;
        return std::prev(lower)->second;

    //std::cout << lower->first << std::endl;
    return lower->second;
    }
    else
        //std::cout << it->first << std::endl;
        return (it->second);
}
