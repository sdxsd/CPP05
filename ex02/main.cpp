#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Enter name and grade please. " << std::endl;
		return (0);
	}
	try {
		const Bureaucrat bob(argv[1], std::stoi(argv[2]));
		Form document("Treaty of the annexation of Belgium", 10, 50);
		std::cout << bob << std::endl;
		document.beSigned(bob);
	}
	catch (Bureaucrat::GradeTooHighException& gthe) {
		std::cout << "Grade too high exception." << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException& gtle) {
		std::cout << "Grade too low exception." << std::endl;
		return (1);
	}
	catch (AForm::GradeTooHighException& gthe) {
		std::cout << "Grade too high exception (form)" << std::endl;
		return (1);
	}
	catch (AForm::GradeTooLowException& gtle) {
		std::cout << "Grade too low exception (form)" << std::endl;
		return (1);
	}
}
