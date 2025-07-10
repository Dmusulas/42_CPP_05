/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:13:15 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/10 17:42:49 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade) {
    if (grade < maxGrade) {
        throw GradeTooHighException();
    }
    if (grade > minGrade) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::promoteGrade() {
    if (this->grade - 1 < Bureaucrat::maxGrade) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
    std::cout << "Promotion! New grade of " << this->name << " is "
              << this->grade << std::endl;
}

void Bureaucrat::demoteGrade() {
    if (this->grade + 1 > Bureaucrat::minGrade) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
    std::cout << "Demotion :( New grade of " << this->name << " is "
              << this->grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (highest grade is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (lowest grade is 150)";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    return os << bureaucrat.getName() << ", bureaucrat grade "
              << bureaucrat.getGrade() << "." << std::endl;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
