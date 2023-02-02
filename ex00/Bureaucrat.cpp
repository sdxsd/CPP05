#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string title, int level): name(title)  {
	if (level < TOP_GRADE)
		throw GradeTooHighException();
	if (level > LOWEST_GRADE)
		throw GradeTooLowException();
	else
		grade = level;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy): name(toCopy.name) {
	grade = toCopy.grade;
}

Bureaucrat::~Bureaucrat(void) {
	;
}

std::string Bureaucrat::getName(void) const {
	return (name);
}

int Bureaucrat::getGrade(void) const {
	return (grade);
}

void Bureaucrat::incGrade(void) {
	if (grade > TOP_GRADE)
		grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decGrade(void) {
	if (grade < LOWEST_GRADE)
		grade++;
	else
		throw GradeTooLowException();
}
