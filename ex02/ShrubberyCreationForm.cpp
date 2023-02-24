#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Presidential Pardon Form", 145, 137) {
	target = "barbary";
	isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetName):
	AForm("Shrubbery Creation Form", 145, 137) {
	target = targetName;
	isSigned = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy):
	AForm(toCopy.formName, toCopy.reqSign, toCopy.reqExec) {
	this->isSigned = toCopy.isSigned;
	this->target = toCopy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy) {
	this->isSigned = toCopy.isSigned;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (czechCredentialsExec(executor) == 1 && isSigned == true) {
		std::ofstream shrubbery;
		shrubbery.open(target + "_shrubbery");
		if (shrubbery.fail() == false) {
			shrubbery << "###" << std::endl
					  << "###" << std::endl
					  << " | " << std::endl;
			shrubbery.close();
		}
		else
			throw GardeningFailureException();
	}
	else {
		throw ExecutionWhileUnsignedException();
	}
}

std::string ShrubberyCreationForm::GardeningFailureException::GardeningFailure(void) {
	return ("Shrubbery creation failed.");
}
