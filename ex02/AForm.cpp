/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:49:26 by dmusulas          #+#    #+#             */
/*   Updated: 2025/08/27 19:18:17 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Parameterized constructor
AForm::AForm(const std::string &name, int const signGrade,
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
AForm::AForm(const AForm &other)
    : signGrade(other.signGrade), executionGrade(other.executionGrade) {}

// Copy assignment operator
// Can't really copy const
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

const std::string &AForm::getName() const { return this->name; }
bool AForm::getStatus() const { return this->isSigned; }
int AForm::getSignGrade() const { return this->signGrade; }
int AForm::getExecutionGrade() const { return this->executionGrade; }

void AForm::setIsSigned(bool status) { this->isSigned = status; }

void AForm::execute(const Bureaucrat &executor) const {
    if (!this->isSigned) {
        throw FormNotSignedException();
    }

    if (executor.getGrade() > this->executionGrade) {
        throw GradeTooLowException();
    }

    this->executeAction();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() >= this->getSignGrade()) {
        throw AForm::GradeTooLowException();
    } else {
        setIsSigned(true);
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    return os << form.getName() << ": signed=" << form.getStatus()
              << ", signGrade=" << form.getSignGrade()
              << ", executionGrade=" << form.getExecutionGrade() << std::endl;
}
