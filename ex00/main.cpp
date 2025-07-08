/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:34:09 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/08 18:47:53 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdio>

int main(void) {
    Bureaucrat bob = Bureaucrat("Bob", 1);
    Bureaucrat alice = Bureaucrat("Alice", 150);

    try {
        std::cout << bob;
        bob.demoteGrade();
        bob.promoteGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << alice;
        alice.demoteGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
