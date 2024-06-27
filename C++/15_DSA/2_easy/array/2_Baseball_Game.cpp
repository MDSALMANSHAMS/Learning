/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game,
you start with an empty record. You are given a list of strings operations, where operations[i]
is the ith operation you must apply to the record and is one of the following:
An integer x. Record a new score of x.
'+'. Record a new score that is the sum of the previous two scores.
'D'. Record a new score that is the double of the previous score.
'C'. Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.
The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit
integer and that all operations are valid.

Example 1:
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

Example 3:
Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int calPoints(vector<string> &ops)
{
    stack<int> scores;

    for (const string &op : ops)
    {
        if (op == "C")
        {
            if (!scores.empty())
            {
                scores.pop();
            }
        }
        else if (op == "D")
        {
            if (!scores.empty())
            {
                int lastScore = scores.top();
                scores.push(lastScore * 2);
            }
        }
        else if (op == "+")
        {
            if (scores.size() >= 2)
            {
                int last1 = scores.top();
                scores.pop();
                int last2 = scores.top();
                scores.push(last1);
                scores.push(last1 + last2);
            }
        }
        else
        {
            // Assuming op is a valid number string
            int num = stoi(op);
            scores.push(num);
        }
    }

    int sum = 0;
    while (!scores.empty())
    {
        sum += scores.top();
        scores.pop();
    }

    return sum;
}

int main()
{
    vector<string> ops1 = {"5", "2", "C", "D", "+"};
    cout << "Output for ops1: " << calPoints(ops1) << endl;

    vector<string> ops2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    cout << "Output for ops2: " << calPoints(ops2) << endl;

    vector<string> ops3 = {"1", "C"};
    cout << "Output for ops3: " << calPoints(ops3) << endl;

    return 0;
}
