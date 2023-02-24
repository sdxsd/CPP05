#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Enter name and grade please. " << std::endl;
		return (0);
	}
	try {
		const Bureaucrat wagie(argv[1], std::atoi(argv[2]));
		PresidentialPardonForm form("Zoep Zoep");
		form.beSigned(wagie);
		wagie.executeForm(form);
		ShrubberyCreationForm form_two;
		form_two.beSigned(wagie);
		wagie.executeForm(form_two);
		RobotomyRequestForm form_three;
		form_three.beSigned(wagie);
		wagie.executeForm(form_three);
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
	catch (ShrubberyCreationForm::GardeningFailureException& gfe) {
		std::cout << gfe.GardeningFailure() << std::endl;
	}
	return (1);
}
