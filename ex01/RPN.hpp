/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:32:54 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/15 19:54:11 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdexcept>


class RPN {
    public:
        RPN(std::string const& mathExpr);
        RPN(const RPN& src);
        RPN &operator=(const RPN& src);
        ~RPN();

        std::string         getMathExpr(void) const;
        std::stack<int>     getStack(void) const;
		int					getResult(void) const;
        void                prepareRPN(void);
		void                calculateRPN(int num1, int num2, char c);
        bool                isOperator(char c) const;

    private:
        std::string         _mathExpr;
        std::stack<int>		_stack;
		int					_result;
};

#endif
