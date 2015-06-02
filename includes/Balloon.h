/**************************************************************************************************\
| Balloon implementation                                                                           |
|**************************************************************************************************|
| Main methods:                                                                                    |
|   - operator=                                                                                    |
|   - operator==                                                                                   |
|   - operator<                                                                                    |
|   - operator>                                                                                    |
|   - operator<= (not used in solution)                                                            |
|   - operator>= (not used in solution)                                                            |
|   - operator<< (for printing)								                                       |
|   - operator<< (for printing)								                                       |
|   - operator<< (for printing)								                                       |
|   - operator<< (for printing)								                                       |
|   - setXCoordStart (setter)                                                                      |
|   - setXCoordEnd (setter)							                                               |
|   - setArrowStatus (setter)							                                           |
|   - getXCoordStart (getter)							                                           |
|   - getXCoordEnd (getter)							                                               |
|   - getArrowStatus (getter)							                                           |
|**************************************************************************************************|
| General rules used:                                                                              |
|   - All parameter variables start with capital letter (e.g 'Node').                              |
|   - Private or Protected variables have an underscore suffix.                                    |
|   - Some Operators, Constructors, Destructors, Setters or Getters are not specified              |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifndef _BALLOON_H_
# define _BALLOON_H_

#include <iostream>

class Balloon
{
private:
	float	xCoordStart_;
	float	xCoordEnd_;
	bool	hasArrow_;

public:
	/* Constructors */
	Balloon();
	Balloon(float XCoordStart, float XCoordEnd, bool HasArrow);
	/* Destructors */
	~Balloon();
	/* Operators */
	Balloon& operator=(const Balloon& Balloon);
	bool operator==(const Balloon& Balloon) const;
	bool operator<(const Balloon& Balloon) const;
	bool operator>(const Balloon& Balloon) const;
	bool operator<=(const Balloon& Balloon) const;
	bool operator>=(const Balloon& Balloon) const;
	friend std::ostream& operator<<(const std::ostream& Os, const Balloon& Balloon);
	/* Setters */
	void setXCoordStart(const float& Value);
	void setXCoordEnd(const float& Value);
	void setArrowStatus(const bool& Value);
	/* Getters */
	float getXCoordStart() const;
	float getXCoordEnd() const;
	bool getArrowStatus() const;
};

#endif //_BALLOON_H_