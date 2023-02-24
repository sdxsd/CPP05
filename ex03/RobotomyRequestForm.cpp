#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request Form", 72, 45) {
	target = "Bob WannabeBot";
	isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string targetName):
	AForm("Robotomy Request Form", 72, 45) {
	target = targetName;
	isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy):
	AForm(toCopy.formName, toCopy.reqSign, toCopy.reqExec) {
	this->isSigned = toCopy.isSigned;
	this->target = toCopy.target;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy) {
	this->isSigned = toCopy.isSigned;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (czechCredentialsExec(executor) == 1 && isSigned == true) {
		srand(time(NULL));
		int result = rand() % 2;
		if (result) {
			std::cout << "* BZZZZ! *" << std::endl
					  << "* DRZZZZ! *" << std::endl
					  << target << " sucessfully robotomized" << std::endl;
		}
		else {
			std::cout << "* BZZZZ! *" << std::endl
					  << "* DRZZZZ! *" << std::endl
					  << "Robotomy failed, " << target << " in transfer to waste disposal" << std::endl;
		}
	}
	else {
		throw ExecutionWhileUnsignedException();
	}
}
