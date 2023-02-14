#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
		public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);
		void beExecuted(const Bureaucrat& wagie, std::string target);
};

#endif // PRESIDENTIALPARDONFORM_H
