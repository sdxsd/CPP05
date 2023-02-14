#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

#define LOWEST_GRADE 150
#define TOP_GRADE 1

class Bureaucrat {
	private:
		const std::string	name;
		int			grade;
	public:
		class GradeTooHighException : std::exception  {
			public:
				std::string GradeTooHigh(void);
		};
		class GradeTooLowException : std::exception  {
			public:
				std::string GradeTooLow(void);
		};
		Bureaucrat(std::string title, int level);
		Bureaucrat(const Bureaucrat& toCopy);
		~Bureaucrat(void);
		std::string getName(void) const;
		int			getGrade(void) const;
		void		incGrade(void);
		void		decGrade(void);
		void		signForm(const std::string& formName, int reqGrade) const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& toPrint);

#endif // BUREAUCRAT_H
