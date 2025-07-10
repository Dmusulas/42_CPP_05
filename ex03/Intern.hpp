/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:55:39 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/10 17:55:46 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
private:
    AForm *createShrubberyCreationForm(const std::string &target);
    AForm *createRobotomyRequestForm(const std::string &target);
    AForm *createPresidentialPardonForm(const std::string &target);

public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    // Main function
    AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
