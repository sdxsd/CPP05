#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
		public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string targetName);
		ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& toCopy);
		void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERYCREATIONFORM_H
