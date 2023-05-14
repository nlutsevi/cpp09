/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:42:49 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/14 22:39:08 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <stdexcept>
# include <list>
# include <vector>
# include <ctime>
#include <cctype>
# include <algorithm>
# include <iomanip>

class PmergeMe {
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& src);
		PmergeMe &operator=(const PmergeMe& src);
		~PmergeMe();

		int					getArgsSize(void) const;
		char**				getArgv(void) const;
		std::list<int>		getSortedListArgs(void) const;
		std::vector<int>	getSortedVectArgs(void) const;
		void				processSort();

	private:
		int					_argsSize;
		char**				_argv;
		std::list<int>		_prevArgs;
		std::list<int>		_sortedListArgs;
		std::vector<int>	_sortedVectArgs;
};

#endif
