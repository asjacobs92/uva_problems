#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int numGuests, budget, numHotels, numWeeks;
    while (cin >> numGuests >> budget >> numHotels >> numWeeks)
    {
        int smallestPrice = 0;
        int currentPrice = 0;

        for (int i = 0; i < numHotels; i++)
        {
            int hotelPrice;
            cin >> hotelPrice;
            currentPrice = hotelPrice * numGuests;
            int weekBeds[numWeeks];
            for (int j = 0; j < numWeeks; j++)
            {
                cin >> weekBeds[j];
                if (currentPrice <= budget && numGuests <= weekBeds[j])
                {
                    if (smallestPrice == 0 || currentPrice < smallestPrice)
                        smallestPrice = currentPrice;
                }
            }
        }

        if (smallestPrice == 0)
            cout << "stay home" << endl;
        else
            cout << smallestPrice << endl;
    }

    return 0;
}
