#ifndef RANDOSTUFF_TRAINFARE_HPP
#define RANDOSTUFF_TRAINFARE_HPP

enum class Ticket
{
	adult,
	concession,
	child,
	pensioner,
};

class FareType
{
public:
	/* Constructor */
	FareType();

	/* Setters */
	void setTicketType(Ticket);
	void setDays(int);
	void setOnPeak(int);
	void setWeekendDays(int);

	/* Getters */
	double totalFare() const;
	double dailyFare() const;
	double gateCost() const;

private:
	// Trip information
	int numberOfDays;
	int onPeakTrips;
	int weekendDays;

	// Trip cost
	double fare;
	double airPass;

	// Maximums
	double dailyMax;
	double weekendMax;
	double weeklyMax;
	double airMax;
};

#endif //RANDOSTUFF_TRAINFARE_HPP
