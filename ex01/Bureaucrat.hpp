/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:13:10 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/08 20:13:27 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// Includes
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
private:
    // Member variables
    std::string const name;
    int grade;

    // Const for grade validation
    static const int maxGrade = 1;   // Highest grade
    static const int minGrade = 150; // Lowest grade
    // Default constructor
    Bureaucrat();

public:
    // Orthodox Canonical Form

    // Parameterized constructor
    Bureaucrat(const std::string &name, int grade);

    // Copy constructor
    Bureaucrat(const Bureaucrat &other);

    // Copy assignment operator
    Bureaucrat &operator=(const Bureaucrat &other);

    // Destructor
    ~Bureaucrat();

    // Accessors
    const std::string &getName() const;
    int getGrade() const;

    // Incrementer and decrement functions
    void promoteGrade();
    void demoteGrade();

    // member functions
    void signForm(Form &form);

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif
