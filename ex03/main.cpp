/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:34:09 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/10 17:57:03 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "=== Testing Intern Form Creation ===" << std::endl;

    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm *form1 = NULL;
    AForm *form2 = NULL;
    AForm *form3 = NULL;
    AForm *form4 = NULL;

    std::cout << "\n--- Creating valid forms ---" << std::endl;
    form1 = intern.makeForm("shrubbery creation", "garden");
    form2 = intern.makeForm("robotomy request", "Bender");
    form3 = intern.makeForm("presidential pardon", "Arthur");

    std::cout << "\n--- Trying to create invalid form ---" << std::endl;
    form4 = intern.makeForm("coffee making", "kitchen");

    std::cout << "\n--- Testing created forms ---" << std::endl;
    if (form1) {
        std::cout << *form1 << std::endl;
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        std::cout << *form2 << std::endl;
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        std::cout << *form3 << std::endl;
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    if (form4) {
        delete form4;
    }

    return 0;
}
