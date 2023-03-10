#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
		public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string targetName);
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);
		void execute(Bureaucrat const & executor) const;
};

#endif // PRESIDENTIALPARDONFORM_H
