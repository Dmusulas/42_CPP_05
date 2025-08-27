/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:51:19 by dmusulas          #+#    #+#             */
/*   Updated: 2025/08/27 19:18:03 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

// Includes
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
    // Member variables
    std::string const name;
    bool isSigned;
    int const signGrade;
    int const executionGrade;
    static const int maxGrade = 1;   // Highest grade
    static const int minGrade = 150; // Lowest grade
    AForm(); // we don't need default constructor in this case so it is made
             // private - declared not defined

protected:
    virtual void executeAction() const = 0;

public:
    // Orthodox Canonical Form

    // Parameterized constructor
    AForm(const std::string &name, int const signGrade,
          int const executionGrade);

    // Copy constructor
    AForm(const AForm &other);

    // Copy assignment operator
    AForm &operator=(const AForm &other);

    // Destructor
    virtual ~AForm();

    // Public interface

    // Accessors
    const std::string &getName() const;
    bool getStatus() const;
    int getSignGrade() const;
    int getExecutionGrade() const;

    void setIsSigned(bool status);

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
