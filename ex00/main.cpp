#include "Bureaucrat.hpp"

int main(void) {
	try {
		const Bureaucrat bob("bart", 151);
	}
	catch (Bureaucrat::GradeTooHighException& gthe) {
		std::cout << "Grade too high exception." << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& gtle) {
		std::cout << "Grade too low exception." << std::endl;
	}
}
