#include "AForm.hpp"

AForm::AForm(void):
	formName("defaultFormName"), reqSign(50), reqExec(10) {
	isSigned = false;
}

AForm::AForm(std::string name, int signReq, int execReq):
	formName(name), reqSign(signReq), reqExec(execReq) {
	if (signReq < TOP_GRADE)
		throw GradeTooHighException();
	if (signReq > LOWEST_GRADE)
		throw GradeTooLowException();
	isSigned = false;
}

AForm::AForm(const AForm& toCopy):
	formName(toCopy.getName()), reqSign(toCopy.getReqSign()), reqExec(toCopy.getReqExec()) {
	isSigned = toCopy.getIsSigned();
}

AForm::~AForm(void) {
	;
}

AForm& AForm::operator=(const AForm& toCopy) {
	this->isSigned = toCopy.getIsSigned();
	return (*this);
}

std::string AForm::getName(void) const {
	return (formName);
};

int AForm::getReqSign(void) const {
	return (reqSign);
}

int AForm::getReqExec(void) const {
	return (reqExec);
}

bool AForm::getIsSigned(void) const {
	return (isSigned);
}

void AForm::beSigned(const Bureaucrat& wagie) {
	if (wagie.getGrade() <= reqSign) {
		isSigned = true;
		wagie.signForm(formName, reqSign);
	}
	else {
		wagie.signForm(formName, reqSign);
		throw GradeTooLowException();
	}
}

int AForm::czechCredentialsExec(const Bureaucrat& wagie) const {
	if (wagie.getGrade() > reqExec)
		throw GradeTooLowException();
	else
		return (1);
}

int AForm::czechCredentialsSign(const Bureaucrat& wagie) const {
	if (wagie.getGrade() > reqSign)
		throw GradeTooLowException();
	else
		return (1);
}

std::string AForm::GradeTooHighException::GradeTooHigh(void) {
	return ("AForm needs to be signed by someone.");
}

std::string AForm::GradeTooLowException::GradeTooLow(void) {
	return ("AForm cannot be signed by anyone.");
}

std::string AForm::ExecutionWhileUnsignedException::ExecWhileUnsigned(void) {
	return ("Uh oh... filing error....");
}
