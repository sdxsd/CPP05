#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Enter name and grade please. " << std::endl;
		return (0);
	}
	try {
		const Bureaucrat bob(argv[1], std::atoi(argv[2]));
		PresidentialPardonForm form("Zjeop");
		form.beSigned(bob);
		form.execute(bob);
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
