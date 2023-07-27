#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <stdlib.h>

Intern::Intern(void) {;}
Intern::~Intern(void) {;}

int main(int argc, char *argv[]) {
	AForm				*form[4];
	Intern				Harold;
	if (argc != 3) {
		std::cout << "Enter name and grade please. " << std::endl;
		return (0);
	}
	try {
		const Bureaucrat	wagie(argv[1], std::atoi(argv[2]));
		try {
			form[0] = Harold.makeForm("Shrubbery Creation Form", "Znonk");
			form[1] = Harold.makeForm("Presidential Pardon Form", "Edward Snowden");
			form[2] = Harold.makeForm("Robotomy Request Form", "Mark Zuckerberg");
			form[3] = Harold.makeForm("Invalid Form Name", "Sneaky Pete");
			for (int i = 0; i < 4; i++) {
				if (form[i] != NULL) {
					form[i]->beSigned(wagie);
					wagie.executeForm(*form[i]);
					delete form[i];
			}
				else
					std::cout << "Invalid form detected. Intern fired!" << std::endl;;
			}
		}
		catch (AForm::GradeTooHighException& gthe) {
			std::cout << gthe.GradeTooHigh() << std::endl;
		}
		catch (AForm::GradeTooLowException& gtle) {
			std::cout << gtle.GradeTooLow() << std::endl;
		}
		catch (AForm::ExecutionWhileUnsignedException& ewus) {
			std::cout << ewus.ExecWhileUnsigned() << std::endl;
		}
		catch (ShrubberyCreationForm::GardeningFailureException& gfe) {
			std::cout << gfe.GardeningFailure() << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException& gthe) {
		std::cout << gthe.GradeTooHigh() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& gtle) {
		std:: cout << gtle.GradeTooLow() << std::endl;
	}
	return (1);
}
