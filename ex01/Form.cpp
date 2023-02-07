#include "Form.hpp"

Form::Form(void):
	formName("defaultFormName"), reqSign(50), reqExec(10) {
	isSigned = false;
}

Form::Form(std::string name, int signReq, int execReq):
	formName(name), reqSign(signReq), reqExec(execReq) {
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
