#ifndef FORM_H
#define FORM_H

#define LOWEST_GRADE 150
#define TOP_GRADE 1

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	formName;
		const int			reqSign;
		const int			reqExec;
		bool				isSigned;
	public:
		Form(void);
		Form(std::string name, int signReq, int execReq);
		Form(const Form& toCopy);
		~Form(void);
		Form& operator=(const Form& toCopy);
		std::string getName(void) const;
		int getReqSign(void) const;
		int getReqExec(void) const;
		bool getIsSigned(void) const;
		void beSigned(const Bureaucrat& wagie);
};

#endif // FORM_H
