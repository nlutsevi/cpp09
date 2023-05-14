/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:32:54 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/05/14 18:53:07 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>


class RPN {
    public:
        RPN(std::string const& mathExpr);
        RPN(const RPN& src);
        RPN &operator=(const RPN& src);
        ~RPN();

        std::string         getMathExpr(void) const;
        std::stack<int>     getStack(void) const;
        void                calculateRPN(void) const;
        bool                isOperator(char c);

    private:
        std::string         _mathExpr;
        std::stack<int>     _stack;
};

#endif
