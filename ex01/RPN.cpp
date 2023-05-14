/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:33:27 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/14 19:01:43 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const& mathExpr) : _mathExpr(mathExpr) {
    calculateRPN();
}


RPN::RPN(const RPN& src) {
    *this = src;
}


RPN                 &RPN::operator=(const RPN& src) {
    this->_mathExpr = src.getMathExpr();
    return (*this);
}


RPN::~RPN() {};


std::string         RPN::getMathExpr(void) const {
    return this->_mathExpr;
}



std::stack<int>     RPN::getStack(void) const {
    return this->_stack;
}

void                RPN::calculateRPN(void) const {
    std::string     mathExpr = this->_mathExpr;
    std::string     numberToCalc;
    int             digitsCount = 0;
    
    //remove untrailing spaces
    mathExpr.erase(mathExpr.find_last_not_of(" \n\r\t")+1);
    for (int i = 0; i < mathExpr.length(); i++) {
        char c = mathExpr[i];

        //more than 10 numbers passed
        if (digitsCount >= 10)
            throw std::runtime_error("Too many numbers passed.");
        //skip space
        if (c == ' ')
            continue;
        else if (std::isdigit(c)) {
            numberToCalc += c;
            digitsCount += 1;
        }
        else if (this->isOperator(c)) {
            //calculate
        }
        else
            throw std::runtime_error("Error");
        if (!numberToCalc.empty()) {
            this->_stack.push(std::atoi(numberToCalc.c_str()));
            numberToCalc.clear();
        }
    }
}


bool                RPN::isOperator(char c) {
    return (c == '*' || c == '/' || c == '+' || c == '-');
}