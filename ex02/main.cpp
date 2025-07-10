/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:34:09 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/10 17:45:02 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "=== Testing Form Execution ===" << std::endl;

    // Create bureaucrats with different grades
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 100);

    // Create forms
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << "\n--- Signing forms ---" << std::endl;
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << "\n--- Boss executing forms ---" << std::endl;
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << "\n--- Worker trying to execute forms ---" << std::endl;
    worker.executeForm(shrub);
    worker.executeForm(robot);
    worker.executeForm(pardon);

    std::cout << "\n--- Trying to execute unsigned form ---" << std::endl;
    RobotomyRequestForm unsigned_form("R2D2");
    boss.executeForm(unsigned_form);

    return 0;
}
