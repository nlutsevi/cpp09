/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:45:00 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/14 22:40:20 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv) : _argsSize(argc), _argv(argv) {
	for (int i = 1; i < this->_argsSize; i++) {		
		for (unsigned long j = 0; j < std::string(this->_argv[i]).length(); j++) {
			if (!std::isdigit(this->_argv[i][j]) || std::atoi(this->_argv[i]) <= 0) {
				throw std::runtime_error("Error");
			}
			else {
			this->_prevArgs.push_back(std::atoi(this->_argv[i]));
			this->_sortedListArgs.push_back(std::atoi(this->_argv[i]));
			this->_sortedVectArgs.push_back(std::atoi(this->_argv[i]));
			}
		}
	}
};


PmergeMe::PmergeMe(const PmergeMe& src) {
	*this = src;
}

PmergeMe			&PmergeMe::operator=(const PmergeMe& src) {
	this->_argsSize = src.getArgsSize();
	this->_argv = src.getArgv();
	this->_sortedListArgs = src.getSortedListArgs();
	this->_sortedVectArgs = src.getSortedVectArgs();
	return (*this);
}

PmergeMe::~PmergeMe() {};


int					PmergeMe::getArgsSize(void) const {
	return this->_argsSize;
}


char**				PmergeMe::getArgv(void) const {
	return this->_argv;
}


std::list<int>		PmergeMe::getSortedListArgs(void) const {
	return this->_sortedListArgs;
}


std::vector<int>		PmergeMe::getSortedVectArgs(void) const {
	return this->_sortedVectArgs;
}


void				PmergeMe::processSort(void) {
	//display unordered digits
	std::cout << "Before:	";
	for (std::list<int>::iterator it = this->_prevArgs.begin(); it != this->_prevArgs.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//display ordered list
	std::cout << "After:	";
	clock_t	startTimeList = clock();
	this->_sortedListArgs.sort();
	clock_t	endTimeList = clock();
	double listProcessTime = double(endTimeList - startTimeList) / CLOCKS_PER_SEC;
	for (std::list<int>::iterator it = this->_sortedListArgs.begin(); it != this->_sortedListArgs
	.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//calcuate time to order the vector
	clock_t	startTimeVect = clock();
	std::sort(this->_sortedVectArgs.begin(), this->_sortedVectArgs.end());
	clock_t	endTimeVect = clock();
	double vectProcessTime = double(endTimeVect - startTimeVect) / CLOCKS_PER_SEC;


	//display time
	std::cout << "Time to process a range of " << this->_sortedVectArgs.size() << 
	" elements with std::list<int>	:	" << std::fixed << std::setprecision(6) << (listProcessTime * 100) << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_sortedVectArgs.size() << 
	" elements with std::vector<int>	:	" << std::fixed << std::setprecision(6) << (vectProcessTime * 100) << " us" << std::endl;
}
