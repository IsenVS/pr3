#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct Match {
    string team1;
    int score1;
    string team2;
    int score2;
};

int main() {
    vector<Match> matches = {
        {"Real Madrid", 2, "Barcelona", 1},
        {"Liverpool", 1, "Juventus", 1},
        {"Real Madrid", 3, "Liverpool", 0},
        {"Barcelona", 2, "Juventus", 2},
        {"Real Madrid", 1, "Juventus", 1},
        {"Barcelona", 3, "Liverpool", 2}
    };
    unordered_map<string, int> team_points;

    for (const auto& match : matches) {
        if (match.score1 > match.score2) {
            team_points[match.team1] += 3;
            team_points[match.team2] += 0; 
        } else if (match.score1 < match.score2) {
            team_points[match.team1] += 0; 
            team_points[match.team2] += 3; 
        } else {
            team_points[match.team1] += 1; 
            team_points[match.team2] += 1; 
        }
    }
    auto winner = max_element(team_points.begin(), team_points.end(), 
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });
    cout << "Победитель турнира: " << winner->first << " с " << winner->second << " очками." << endl;
    return 0;
}
