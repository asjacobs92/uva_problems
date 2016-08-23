#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main ()
{
    int num_samples = -1;
    while (cin >> num_samples && num_samples != 0)
    {
        vector<int> samples;
        for (int i = 0; i < num_samples; i++)
        {
            int sample;
            cin >> sample;
            samples.push_back(sample);
        }

        int num_peaks = 0;
        for (int i = 0; i < samples.size(); i++)
        {
            int after = (i + 1) % samples.size();
            int before = i - 1;
            if (i == 0)
            {
                before = samples.size() - 1;
            }

            if ((samples[i] < samples[before] && samples[i] < samples[after]) ||
                (samples[i] > samples[before] && samples[i] > samples[after]))
            {
                num_peaks++;
            }
        }
        cout << num_peaks << endl;
    }
    return 0;
}
