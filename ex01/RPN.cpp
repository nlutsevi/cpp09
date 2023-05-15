/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:33:27 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/15 19:55:13 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"


RPN::RPN(std::string const& mathExpr) : _mathExpr(mathExpr) {
    prepareRPN();
}


RPN::RPN(const RPN& src) {
    *this = src;
}


RPN                 &RPN::operator=(const RPN& src) {
    this->_mathExpr = src.getMathExpr();
	this->_stack = src.getStack();
    return (*this);
}


RPN::~RPN() {};


std::string         RPN::getMathExpr(void) const {
    return this->_mathExpr;
}



std::stack<int>     RPN::getStack(void) const {
    return this->_stack;
}


int					RPN::getResult(void) const {
	return this->_result;
}



void                RPN::prepareRPN(void) {
    std::string     mathExpr = this->_mathExpr;
    std::string     numberToCalc;

    //remove untrailing spaces
    mathExpr.erase(mathExpr.find_last_not_of(" \n\r\t")+1);
    for (unsigned long i = 0; i < mathExpr.length(); i++) {
        char c = mathExpr[i];

        //skip space
        if (c == ' ')
            continue;
        else if (std::isdigit(c))
            numberToCalc += c;
        else if (this->isOperator(c)) {
            int num1;
			int num2;
			
			if (this->_stack.size() < 2)
				throw std::runtime_error("Error");
			num2 = this->_stack.top();
			this->_stack.pop();
			num1 = this->_stack.top();
			this->_stack.pop();
			this->calculateRPN(num1, num2, c);
        }
        else
            throw std::runtime_error("Error");
		if (!numberToCalc.empty()) {
			this->_stack.push(std::atoi(numberToCalc.c_str()));
            numberToCalc.clear();
        }
    }
	if (this->_stack.size() != 1)
		throw std::runtime_error("Error");
	this->_result = this->_stack.top();
	this->_stack.pop();
}


void				RPN::calculateRPN(int num1, int num2, char c) {
	int		result;

	if (c == '*')
		result = num1 * num2;
	else if (c == '/') {
		if (num2 == 0)
			throw std::runtime_error("Error");
		result = num1 / num2;
	}
	else if (c == '+')
		result = num1 + num2;
	else if (c == '-')
		result = num1 - num2;
	this->_stack.push(result);
}


bool                RPN::isOperator(char c) const {
    return (c == '*' || c == '/' || c == '+' || c == '-');
}