#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon Form", 25, 5) {
	isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy):
	AForm(toCopy.formName, toCopy.reqSign, toCopy.reqExec) {
	this->isSigned = toCopy.isSigned;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy) {
	this->isSigned = toCopy.isSigned;
	return (*this);
}

void PresidentialPardonForm::beExecuted(Bureaucrat const & executor) {
	if (executor.getGrade() <= reqExec)
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else {
		throw GradeTooLowException();
	}
}
