#ifndef _BALLOON_H_
# define _BALLOON_H_

#include <iostream>

class Balloon
{
private:
	float	xCoordStart;
	float	xCoordEnd;

public:
	/* Constructors */
	Balloon();
	/* Destructors */
	~Balloon();
	/* Operators */
	Balloon&				operator=(const Balloon& Balloon);
	bool					operator==(const Balloon& Balloon);
	friend std::ostream&	operator<<(const std::ostream& Os, const Balloon& Balloon);
	/* Setters */
	void					SetXCoordStart(const float& Value);
	void					SetXCoordEnd(const float& Value);
	/* Getters */
	float					GetXCoordStart() const;
	float					GetXCoordEnd() const;
};

#endif //_BALLOON_H_