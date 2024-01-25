#include "TrainFare.hpp"
#include <string>
#include <iostream>

void inputDetails(FareType&);
void OutputDetails(FareType&);

int main()
{
	FareType ticket;
	inputDetails(ticket);
	OutputDetails(ticket);
}

void inputDetails(FareType& details)
{
	char fareClass = 'a';
	int days = 0;
	int endDays = 0;
	int onPeak = 0;

	std::ios_base::sync_with_stdio(false); // only needs to be flushed once
	std::cout << "The Ticket Types are (TicketType, input):\n";
	std::cout << "	- Adult: a\n";
	std::cout << "	- Concession: s\n";
	std::cout << "	- Child: c\n";
	std::cout << "	- Pensioner: p\n";

	std::cout << "\nInput Fare Type: "; // The type of fare used
	std::cout.flush(); // outputting to console
	std::ios_base::sync_with_stdio(true);

	std::cin >> fareClass;

	std::cout << "Number of Days Traveling: "; // total amount of days commuting
	std::cin >> days;

	std::cout << "Number of Days Weekend Days: "; // the number of days Friday to Sunday (inclusive) commuting
	std::cin >> endDays;

	std::cout << "Number of Peak Time Trips: "; // Number of times Peak time trips taken
	std::cin >> onPeak;

	if(fareClass == 'a') // adult prices
	{
		// to prevent further checks
		// adult option and most common so at front
		// constructed as these values
	}
	else if(fareClass == 's') // concession/student prices
	{
		details.setTicketType(Ticket::concession);
	}
	else if(fareClass == 'c') // child prices
	{
		details.setTicketType(Ticket::child);
	}
	else if(fareClass == 'p') // senior/pensioner prices
	{
		details.setTicketType(Ticket::pensioner);
	}
	else
	{
		// to cover any other inputs
		// default option to prevent issues defaulting to adult prices
	};

	details.setDays(days);
	details.setOnPeak(onPeak);
	details.setWeekendDays(endDays);
};

void OutputDetails(FareType& output)
{
	std::ios_base::sync_with_stdio(false); // only needs to be flushed once

	std::cout << "\nTotal Fare over a Week is:	" << output.totalFare() << "\n";
	std::cout << "Average Daily Fare is:		" << output.dailyFare() << "\n";
	std::cout << "with Airport Gate Cost of:	" << output.gateCost() << "\n";
	std::cout.flush();

	std::ios_base::sync_with_stdio(true);
}