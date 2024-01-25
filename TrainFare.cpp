#include "TrainFare.hpp"

FareType::FareType()
	: numberOfDays(0), onPeakTrips(0), weekendDays(0), fare(9.84), airPass(16.68),
		dailyMax(17.80), weekendMax(9.80), weeklyMax(50.00), airMax(33.84) {}

void FareType::setDays(int input)
{
	numberOfDays = input;
}

void FareType::setOnPeak(int input)
{
	onPeakTrips = input;
}

void FareType::setWeekendDays(int input)
{
	weekendDays = input;
}

double FareType::totalFare() const
{
	int trips = ((numberOfDays - weekendDays) * 2) - onPeakTrips;
	double offPeak = fare * 0.70;

	if((offPeak * 2) > dailyMax)
	{
		offPeak = dailyMax/2;
	}
	double weekTotal = trips * offPeak;

	double onPeak = onPeakTrips * fare;
	double airCost = (numberOfDays * 2) * airPass;

	if((offPeak * 2) > weekendMax)
	{
		offPeak = weekendMax;
	}
	double weekEnd = weekendDays * offPeak;

	if(weekTotal > weeklyMax)
	{
		weekTotal = weeklyMax;
	}
	if(airCost > airMax)
	{
		airCost = airMax;
	}

	return (weekTotal + weekEnd + onPeak + airCost);
}

double FareType::dailyFare() const
{
	return totalFare() / numberOfDays;
}

double FareType::gateCost() const
{
	double gateCost = numberOfDays * airPass;
	if(gateCost > airMax)
	{
		gateCost = airMax;
	}
	return gateCost;
}

void FareType::setTicketType(Ticket input)
{
	if(input == Ticket::concession)
	{
		fare = 4.92;
		airPass = 14.92;
		dailyMax = 8.90;
		weekendMax = 4.45;
		weeklyMax = 25;
		airMax = 30.33;
	}
}
