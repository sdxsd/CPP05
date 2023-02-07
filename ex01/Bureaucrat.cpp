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

std::string Bureaucrat::GradeTooHighException::GradeTooHigh(void) {
	return ("Computer says no.");
}

std::string Bureaucrat::GradeTooLowException::GradeTooLow(void) {
	return ("You cannot be more worthless than you already are.");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& toPrint) {
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade();
	return (os);
}

void Bureaucrat::signForm(const std::string& formName) const {
	std::cout << name << " signed form " << formName << std::endl;
	// TODO:
	// Check if form has been sucessfully signed. Needs if else condition.
}
