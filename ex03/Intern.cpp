#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {
	;
}

Intern::Intern(const Intern& toCopy) {
	;
}

Intern::~Intern(void) {
	;
}

Intern& Intern::operator=(const Intern& toCopy) {
	return (*this);
}

AForm *makeForm(std::string formName, std::string targetName) {
	AForm *choice = NULL;
	AForm *forms[3] = {
		new ShrubberyCreationForm(targetName),
		new PresidentialPardonForm(targetName),
		new RobotomyRequestForm(targetName)
	};
	for (int i = 0; i < 3; i++) {
		if (forms[i]->getName() == formName)
			choice = forms[i];
		else
			delete forms[i];
	}
	if (choice == NULL)
		std::cerr << "Form specified does not exist." << std::endl;
	return (choice);
}
