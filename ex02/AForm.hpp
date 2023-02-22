#ifndef AFORM_H
#define AFORM_H

#define LOWEST_GRADE 150
#define TOP_GRADE 1

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	protected:
		const std::string		formName;
		const int			reqSign;
		const int			reqExec;
		bool				isSigned;
		std::string			target;
	public:
		class GradeTooHighException : std::exception  {
			public:
				std::string GradeTooHigh(void);
		};
		class GradeTooLowException : std::exception  {
			public:
				std::string GradeTooLow(void);
		};
		AForm(void);
		AForm(std::string name, int signReq, int execReq);
		AForm(const AForm& toCopy);
		virtual ~AForm(void);
		AForm& operator=(const AForm& toCopy);
		std::string getName(void) const;
		int	getReqSign(void) const;
		int	getReqExec(void) const;
		bool	getIsSigned(void) const;
		void	beSigned(const Bureaucrat& wagie);
		int	czechCredentialsSign(Bureaucrat const& wagie);
		int	czechCredentialsExec(Bureaucrat const& wagie);
		virtual void beExecuted(Bureaucrat const& executor) = 0;
};

#endif // AFORM_H
