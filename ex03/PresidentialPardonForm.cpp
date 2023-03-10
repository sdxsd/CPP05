#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon Form", 25, 5) {
	target = "Zhazhek";
	isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string targetName):
	AForm("Presidential Pardon Form", 25, 5) {
	target = targetName;
	isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy):
	AForm(toCopy.formName, toCopy.reqSign, toCopy.reqExec) {
	this->isSigned = toCopy.isSigned;
	this->target = toCopy.target;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy) {
	this->isSigned = toCopy.isSigned;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (czechCredentialsExec(executor) == 1 && isSigned == true) {
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else {
		throw ExecutionWhileUnsignedException();
	}
}
