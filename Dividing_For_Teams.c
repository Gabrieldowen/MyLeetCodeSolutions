/*
2491. Divide Players Into Teams of Equal Skill
Solved
Medium

Topics
Companies

Hint
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.
*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemistry = 0;

        sort(skill.begin(), skill.end());
    
        int TeamSkill = skill[0] + skill.back();
        int back = skill.size()-1;

        for(int front = 0; front < back; front++){
            cout << skill[front] + skill[back] << endl;

            if(skill[front] + skill[back] != TeamSkill) {return -1;}
            else {chemistry += (long long)skill[front] * skill[back];}

            back--;
        }


        return chemistry;
    }
};