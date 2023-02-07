#include "Form.hpp"

Form::Form(void):
	formName("defaultFormName"), reqSign(50), reqExec(10) {
	isSigned = false;
}

Form::Form(std::string name, int signReq, int execReq):
	formName(name), reqSign(signReq), reqExec(execReq) {
	if (signReq < TOP_GRADE)
		throw GradeTooHighException();
	if (signReq > LOWEST_GRADE)
		throw GradeTooLowException();
	isSigned = false;
}

Form::Form(const Form& toCopy):
	formName(toCopy.getName()), reqSign(toCopy.getReqSign()), reqExec(toCopy.getReqExec()) {
	isSigned = toCopy.getIsSigned();
}

Form::~Form(void) {
	;
}

Form& Form::operator=(const Form& toCopy) {
	this->isSigned = toCopy.getIsSigned();
	return (*this);
}

std::string Form::getName(void) const {
	return (formName);
};

int Form::getReqSign(void) const {
	return (reqSign);
}

int Form::getReqExec(void) const {
	return (reqExec);
}

bool Form::getIsSigned(void) const {
	return (isSigned);
}

void Form::beSigned(const Bureaucrat& wagie) {
	if (wagie.getGrade() <= reqSign) {
		isSigned = true;
		wagie.signForm(formName, reqSign);
	}
	else {
		wagie.signForm(formName, reqSign);
		throw GradeTooLowException();
	}
}

std::string Form::GradeTooHighException::GradeTooHigh(void) {
	return ("You cannot be cooler than you are now.");
}

std::string Form::GradeTooLowException::GradeTooLow(void) {
	return ("You cannot be more foolish than you are now.");
}
