/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:34:09 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/08 20:16:53 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Basic Bureaucrat Tests ===" << std::endl;

    try {
        // Test valid bureaucrat
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        // Test invalid bureaucrat
        Bureaucrat invalid("Invalid", 0);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Basic Form Tests ===" << std::endl;

    try {
        // Test valid form
        Form taxForm("Tax Form", 45, 30);
        std::cout << taxForm << std::endl;

        // Test invalid form
        Form invalidForm("Invalid", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Form Signing Tests ===" << std::endl;

    try {
        Bureaucrat alice("Alice", 40);
        Bureaucrat charlie("Charlie", 60);
        Form importantForm("Important Form", 45, 25);

        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;
        std::cout << importantForm << std::endl;

        // Alice should be able to sign (grade 40 < 45)
        alice.signForm(importantForm);
        std::cout << importantForm << std::endl;

        // Charlie should not be able to sign (grade 60 > 45)
        charlie.signForm(importantForm);

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Modification Tests ===" << std::endl;

    try {
        Bureaucrat worker("Worker", 2);
        std::cout << worker << std::endl;

        worker.promoteGrade(); // Should work (2 -> 1)
        std::cout << worker << std::endl;

        worker
            .promoteGrade(); // Should throw exception (can't go higher than 1)

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
