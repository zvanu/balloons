#include "Balloon.h"


Balloon::Balloon()
{
	this->xCoordStart = 0;
	this->xCoordEnd = 0;
	this->hasArrow = false;
}

Balloon::Balloon(float xCoordStart, float xCoordEnd, bool hasArrow)
{
	this->xCoordStart = xCoordStart;
	this->xCoordEnd = xCoordEnd;
	this->hasArrow = hasArrow;
}

Balloon::~Balloon()
{
	;
}

Balloon& Balloon::operator=(const Balloon& Balloon)
{
	this->xCoordStart = Balloon.xCoordStart;
	this->xCoordEnd = Balloon.xCoordEnd;
	this->hasArrow = Balloon.hasArrow;
	return (*this);
}

bool Balloon::operator==(const Balloon& Balloon) const
{
	return (this->xCoordStart == Balloon.xCoordStart &&
		this->xCoordEnd == Balloon.xCoordEnd);
}

bool Balloon::operator<(const Balloon& Balloon) const
{
	return (this->xCoordEnd < Balloon.xCoordEnd);
}

bool Balloon::operator<=(const Balloon& Balloon) const
{
	return (this->xCoordEnd <= Balloon.xCoordEnd);
}

bool Balloon::operator>(const Balloon& Balloon) const
{
	return (this->xCoordEnd > Balloon.xCoordEnd);
}

bool Balloon::operator>=(const Balloon& Balloon) const
{
	return (this->xCoordEnd >= Balloon.xCoordEnd);
}


std::ostream& operator<<(std::ostream& Os, const Balloon& Balloon)
{
	Os << "X start: " << Balloon.getXCoordStart() << " | ";
	Os << "X end: " << Balloon.getXCoordEnd() << "\n";
	return (Os);
}

void Balloon::setXCoordStart(const float& Value)
{
	this->xCoordStart = Value;
}

void Balloon::setXCoordEnd(const float& Value)
{
	this->xCoordEnd = Value;
}

void Balloon::setArrowStatus(const bool& Value)
{
	this->hasArrow = Value;
}

float Balloon::getXCoordStart() const
{
	return (this->xCoordStart);
}

float Balloon::getXCoordEnd() const
{
	return (this->xCoordEnd);
}

bool Balloon::getArrowStatus() const
{
	return (this->hasArrow);
}