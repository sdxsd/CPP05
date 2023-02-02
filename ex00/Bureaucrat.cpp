#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string title, int level): name(title)  {
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

int Bureaucrat::incGrade(void) {
	throw
}
