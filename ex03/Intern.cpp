#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm *Intern::makeForm(std::string formName, std::string targetName) {
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
		std::cerr << "Intern cannot create form of type " << formName << std::endl;
	else
		std::cout << "Intern creates " << choice->getName() << std::endl;
	return (choice);
}
