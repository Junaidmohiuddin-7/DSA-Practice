https : // leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
        class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int travelP = 0;
        int pickP = 0;
        int lasthouseP = 0;
        int travelG = 0;
        int pickG = 0;
        int lasthouseG = 0;

        int travelM = 0;
        int pickM = 0;
        int lasthouseM = 0;
        for (int i = 0; i < garbage.size(); i++)
        {
            string currenthouse = garbage[i];
            for (int j = 0; j < garbage[i].length(); j++)
            {
                char current = currenthouse[j];
                if (current == 'P')
                {
                    pickP++;
                    lasthouseP = i;
                }
                if (current == 'M')
                {
                    pickM++;
                    lasthouseM = i;
                }
                if (current == 'G')
                {
                    pickG++;
                    lasthouseG = i;
                }
            }
        }
        for (int i = 0; i < lasthouseP; i++)
        {
            travelP = travelP + travel[i];
        }
        for (int i = 0; i < lasthouseG; i++)
        {
            travelG = travelG + travel[i];
        }
        for (int i = 0; i < lasthouseM; i++)
        {
            travelM = travelM + travel[i];
        }
        int totalpicktime = pickP + pickG + pickM;
        int totaltraveltime = travelP + travelM + travelG;
        int totaltime = totalpicktime + totaltraveltime;

        return totaltime;
    }
};