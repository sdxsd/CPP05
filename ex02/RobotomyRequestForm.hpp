#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
		public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string targetName);
		RobotomyRequestForm(const RobotomyRequestForm& toCopy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& toCopy);
		void execute(Bureaucrat const & executor) const;
};

#endif // ROBOTOMYREQUESTFORM_H
