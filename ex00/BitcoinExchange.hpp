/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:40:05 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/13 21:28:18 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <regex>


class BitcoinExchange {
    public:
        BitcoinExchange(std::string const& dbFileName);
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange &operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void                            parseDB();
        std::string                     getDbFileName() const;
        std::map<std::string, float>    getExchangeRates() const;
        bool                            isInputDateValid(std::string dateStr) const;
        bool                            isBitcoinQuantityValid(float bitcoinQuantity) const;
        float                           getRateOnDate(const std::string& dateStr) const;

    private:
        std::string                     _dbFileName;
        std::map<std::string, float>    _exchangeRates;
};

# endif