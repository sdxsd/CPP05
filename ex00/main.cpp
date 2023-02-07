#include "Bureaucrat.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Enter name and grade please. " << std::endl;
		return (0);
	}
	try {
		const Bureaucrat bob(argv[1], atoi(argv[2]));
		std::cout << bob << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& gthe) {
		std::cout << "Grade too high exception." << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException& gtle) {
		std::cout << "Grade too low exception." << std::endl;
		return (1);
	}
}
