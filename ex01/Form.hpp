/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:51:19 by dmusulas          #+#    #+#             */
/*   Updated: 2025/08/27 19:13:17 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

// Includes
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
    // Member variables
    std::string const name;
    bool isSigned;
    int const signGrade;
    int const executionGrade;
    // Const for grade validation
    static const int maxGrade = 1;   // Highest grade
    static const int minGrade = 150; // Lowest grade
    Form(); // we don't need default constructor in this case so it is made
            // private - declared not defined

public:
    // Orthodox Canonical Form

    // Parameterized constructor
    Form(const std::string &name, int const signGrade,
         int const executionGrade);

    // Copy constructor
    Form(const Form &other);

    // Copy assignment operator
    Form &operator=(const Form &other);

    // Destructor
    ~Form();

    // Public interface

    // Accessors
    const std::string &getName() const;
    bool getStatus() const;
    int getSignGrade() const;
    int getExecutionGrade() const;

    void setIsSigned(bool status);

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);

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
std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif
