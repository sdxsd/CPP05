#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Enter name and grade please. " << std::endl;
		return (0);
	}
	try {
		const Bureaucrat bob(argv[1], std::atoi(argv[2]));
		PresidentialPardonForm form("Zoep Zoep");
		form.beSigned(bob);
		bob.executeForm(form);
		std::cout << bob << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& gthe) {
		std::cout << gthe.GradeTooHigh() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& gtle) {
		std:: cout << gtle.GradeTooLow() << std::endl;
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
	return (1);
}
