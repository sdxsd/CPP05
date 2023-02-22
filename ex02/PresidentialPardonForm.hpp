#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
		public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);
		void beExecuted(Bureaucrat const & executor);
};

#endif // PRESIDENTIALPARDONFORM_H
