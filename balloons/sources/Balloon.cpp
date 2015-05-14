#include "Balloon.h"


Balloon::Balloon()
{
	this->xCoordStart = 0;
	this->xCoordEnd = 0;
}

Balloon::~Balloon()
{
	;
}

Balloon&		Balloon::operator=(const Balloon& Balloon)
{
	this->xCoordStart = Balloon.xCoordStart;
	this->xCoordEnd = Balloon.xCoordEnd;
	return (*this);
}

bool			Balloon::operator==(const Balloon& Balloon)
{
	return (this->xCoordStart == Balloon.xCoordStart &&
		this->xCoordEnd == Balloon.xCoordEnd);
}

std::ostream&	operator<<(std::ostream& Os, const Balloon& Balloon)
{
	Os << "X start: " << Balloon.GetXCoordStart() << " | ";
	Os << "X end: " << Balloon.GetXCoordEnd() << "\n";
	return (Os);
}

void Balloon::SetXCoordStart(const float& Value)
{
	this->xCoordStart = Value;
}

void Balloon::SetXCoordEnd(const float& Value)
{
	this->xCoordEnd = Value;
}

float Balloon::GetXCoordStart() const
{
	return (this->xCoordStart);
}

float Balloon::GetXCoordEnd() const
{
	return (this->xCoordEnd);
}