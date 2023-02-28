#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern {
	private:
		Intern(const Intern& toCopy);
		Intern& operator=(const Intern& toCopy);
	public:
		Intern(void);
		~Intern(void);
		AForm *makeForm(std::string formName, std::string targetName);
};

#endif // INTERN_H
