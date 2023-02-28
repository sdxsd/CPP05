#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		// Intern(const Intern& toCopy);
		~Intern(void);
		// Intern& operator=(const Intern& toCopy);
		AForm *makeForm(std::string formName, std::string targetName);
};

#endif // INTERN_H
