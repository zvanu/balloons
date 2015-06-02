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
|   - Operators, Constructors, Destructors, Setters and Getters are not specified                  |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#include "Balloon.h"

/*
	Default constructor
*/
Balloon::Balloon()
{
	this->xCoordStart_ = 0;
	this->xCoordEnd_ = 0;
	this->hasArrow_ = false;
}

/*
	Data-given constructor
*/
Balloon::Balloon(float XCoordStart, float XCoordEnd, bool HasArrow)
{
	this->xCoordStart_ = XCoordStart;
	this->xCoordEnd_ = XCoordEnd;
	this->hasArrow_ = HasArrow;
}

Balloon::~Balloon()
{
	;
}

Balloon& Balloon::operator=(const Balloon& Balloon)
{
	this->xCoordStart_ = Balloon.xCoordStart_;
	this->xCoordEnd_ = Balloon.xCoordEnd_;
	this->hasArrow_ = Balloon.hasArrow_;
	return (*this);
}

bool Balloon::operator==(const Balloon& Balloon) const
{
	return (this->xCoordStart_ == Balloon.xCoordStart_ &&
		this->xCoordEnd_ == Balloon.xCoordEnd_);
}

bool Balloon::operator<(const Balloon& Balloon) const
{
	return (this->xCoordEnd_ < Balloon.xCoordEnd_);
}

bool Balloon::operator<=(const Balloon& Balloon) const
{
	return (this->xCoordEnd_ <= Balloon.xCoordEnd_);
}

bool Balloon::operator>(const Balloon& Balloon) const
{
	return (this->xCoordEnd_ > Balloon.xCoordEnd_);
}

bool Balloon::operator>=(const Balloon& Balloon) const
{
	return (this->xCoordEnd_ >= Balloon.xCoordEnd_);
}


std::ostream& operator<<(std::ostream& Os, const Balloon& Balloon)
{
	Os << "X start: " << Balloon.getXCoordStart() << " | ";
	Os << "X end: " << Balloon.getXCoordEnd() << "\n";
	return (Os);
}

void Balloon::setXCoordStart(const float& Value)
{
	this->xCoordStart_ = Value;
}

void Balloon::setXCoordEnd(const float& Value)
{
	this->xCoordEnd_ = Value;
}

void Balloon::setArrowStatus(const bool& Value)
{
	this->hasArrow_ = Value;
}

float Balloon::getXCoordStart() const
{
	return (this->xCoordStart_);
}

float Balloon::getXCoordEnd() const
{
	return (this->xCoordEnd_);
}

bool Balloon::getArrowStatus() const
{
	return (this->hasArrow_);
}