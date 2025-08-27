/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:49:26 by dmusulas          #+#    #+#             */
/*   Updated: 2025/08/27 19:13:34 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Parameterized constructor
Form::Form(const std::string &name, int const signGrade,
           int const executionGrade)
    : name(name), isSigned(false), signGrade(signGrade),
      executionGrade(executionGrade) {
    if (signGrade < maxGrade || executionGrade < maxGrade) {
        throw GradeTooHighException();
    }
    if (signGrade > minGrade || executionGrade > minGrade) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form &other)
    : signGrade(other.signGrade), executionGrade(other.executionGrade) {}

// Copy assignment operator
// Can't really copy const
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

const std::string &Form::getName() const { return this->name; }
bool Form::getStatus() const { return this->isSigned; }
int Form::getSignGrade() const { return this->signGrade; }
int Form::getExecutionGrade() const { return this->executionGrade; }

void Form::setIsSigned(bool status) { this->isSigned = status; }

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low to sign the form!";
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() >= this->getSignGrade()) {
        throw Form::GradeTooLowException();
    } else {
        setIsSigned(true);
    }
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    return os << form.getName() << ": signed=" << form.getStatus()
              << ", signGrade=" << form.getSignGrade()
              << ", executionGrade=" << form.getExecutionGrade() << std::endl;
}
