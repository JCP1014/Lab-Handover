#include "solution.h"

// Update the solution (without the source derived from)
Solution update_sol(Solution s, double newTimeX, double newTimeY, string newTable, string newLane)
{
    s.time[0] = newTimeX;
    s.time[1] = newTimeY;
    s.table = newTable;
    s.lane = newLane;
    return s;
}

// Update the solution (with the source derived from)
Solution update_sol(Solution s, double newTimeX, double newTimeY, string newTable, string newLane, Solution *newSrc)
{
    s.time[0] = newTimeX;
    s.time[1] = newTimeY;
    s.table = newTable;
    s.lane = newLane;
    s.src = newSrc;
    return s;
}

// Update the solution with the best one among all possible solutions
Solution choose_best_sol(Solution s, vector<Solution> solVec)
{
    double minMax = max(solVec[0].time[0], solVec[0].time[1]);
    double minSum;
    double minSrcSum, minSrcMax;
    int index = 0;
    double tmpMax, tmpMin, tmpSum, tmpSrcMax, tmpSrcMin, tmpSrcSum;

    for (int i = 1; i < solVec.size(); ++i)
    {
        // Compare max element of the tuple
        tmpMax = max(solVec[i].time[0], solVec[i].time[1]);
        if (tmpMax < minMax)
        {
            minMax = tmpMax;
            index = i;
        }
        else if (tmpMax == minMax)
        {
            // Compare sum of the tuple
            tmpSum = solVec[i].time[0] + solVec[i].time[1];
            minSum = solVec[index].time[0] + solVec[index].time[1];
            if (tmpSum < minSum)
            {
                minMax = tmpMax;
                index = i;
            }
            else if (tmpSum == minSum && solVec[i].src)
            {
                // Compare max element of the source solution
                tmpSrcMax = max(solVec[i].src->time[0], solVec[i].src->time[1]);
                minSrcMax = max(solVec[index].src->time[0], solVec[index].src->time[1]);
                if (tmpSrcMax < minSrcMax)
                {
                    minMax = tmpMax;
                    index = i;
                }
                else if (tmpSrcMax == minSrcMax)
                {
                    // Compare sum of the source solution
                    tmpSrcSum = solVec[i].src->time[0] + solVec[i].src->time[1];
                    minSrcSum = solVec[index].src->time[0] + solVec[index].src->time[1];
                    if (tmpSrcSum < minSrcSum)
                    {
                        minMax = tmpMax;
                        index = i;
                    }
                }
            }
        }
    }
    s = update_sol(s, solVec[index].time[0], solVec[index].time[1], solVec[index].table, solVec[index].lane);
    return s;
}

// Get which table the final optimal solution is in
string get_opt_table(vector<Solution> solVec)
{
    double minMax = max(solVec[0].time[0], solVec[0].time[1]);
    double minSum;
    double minSrcSum, minSrcMax;
    int index = 0;
    double tmpMax, tmpMin, tmpSum, tmpSrcMax, tmpSrcMin, tmpSrcSum;

    for (int i = 1; i < solVec.size(); ++i)
    {
        // Compare max element of the tuple
        tmpMax = max(solVec[i].time[0], solVec[i].time[1]);
        if (tmpMax < minMax)
        {
            minMax = tmpMax;
            index = i;
        }
        else if (tmpMax == minMax)
        {
            // Compare sum of the tuple
            tmpSum = solVec[i].time[0] + solVec[i].time[1];
            minSum = solVec[index].time[0] + solVec[index].time[1];
            if (tmpSum < minSum)
            {
                minMax = tmpMax;
                index = i;
            }
            else if (tmpSum == minSum && solVec[i].src)
            {
                // Compare max element of the source solution
                tmpSrcMax = max(solVec[i].src->time[0], solVec[i].src->time[1]);
                minSrcMax = max(solVec[index].src->time[0], solVec[index].src->time[1]);
                if (tmpSrcMax < minSrcMax)
                {
                    minMax = tmpMax;
                    index = i;
                }
                else if (tmpSrcMax == minSrcMax)
                {
                    // Compare sum of the source solution
                    tmpSrcSum = solVec[i].src->time[0] + solVec[i].src->time[1];
                    minSrcSum = solVec[index].src->time[0] + solVec[index].src->time[1];
                    if (tmpSrcSum < minSrcSum)
                    {
                        minMax = tmpMax;
                        index = i;
                    }
                }
            }
        }
    }

    // Get the name of table by the index
    switch (index)
    {
    case 0:
        return "AB";
    case 1:
        return "AC";
    case 2:
        return "BB";
    case 3:
        return "BC";
    default:
        return "AB";
    }
}

// Print out the content of a table for debugging
void print_3d_table(vector<vector<vector<Solution>>> &table)
{
    for (int k = 0; k < table[0][0].size(); ++k)
    {
        cout << "k = " << k << endl;
        for (int i = 0; i < table.size(); ++i)
        {
            for (int j = 0; j < table[0].size(); ++j)
                cout << table[i][j][k].time[0] << " " << table[i][j][k].time[1] << " " << table[i][j][k].table << " " << table[i][j][k].lane << " || ";
            cout << endl;
        }
        cout << endl;
    }
}