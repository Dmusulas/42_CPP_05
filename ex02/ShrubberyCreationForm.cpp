/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:00:29 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/10 17:17:36 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Could not create file");
    }

    // Write ASCII trees
    file << "    oxoxoo    ooxoo\n"
            "  ooxoxo oo  oxoxooo\n"
            " oooo xxoxoo ooo ooox\n"
            " oxo o oxoxo  xoxxoxo\n"
            "  oxo xooxoooo o ooo\n"
            "    ooo\\oo\\  /o/o\n"
            "        \\  \\/ /\n"
            "         |   /\n"
            "         |  |\n"
            "         | D|\n"
            "         |  |\n"
            "         |  |\n"
            "  ______/____\\____\n";

    file.close();
    std::cout << "Shrubbery has been planted at " << target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
