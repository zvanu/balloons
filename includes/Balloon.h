#ifndef _BALLOON_H_
# define _BALLOON_H_

#include <iostream>

class Balloon
{
private:
	float	xCoordStart;
	float	xCoordEnd;
	bool	hasArrow;

public:
	/* Constructors */
	Balloon();
	Balloon(float xCoordStart, float xCoordEnd, bool hasArrow);
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