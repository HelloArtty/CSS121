#include <iostream>
#include <list>

struct PlayerScore 
{
    std::string name;
    int score;

    bool operator<(const PlayerScore &other) const 
    {
        return score > other.score;
    }
};

class ScoreBoard {
    private:
        std::list <PlayerScore> scores;
        
    public:
        void addScore(std::string name, int score) 
        {
            for (auto &playerScore : scores) 
            {
                if (playerScore.name == name) 
                {
                    if (score > playerScore.score) 
                    {
                        playerScore.score = score;
                    }
                    scores.sort();
                    return;
                }
            }
            scores.emplace_back(PlayerScore{name, score});
            scores.sort();
            while (scores.size() > 4) {
                scores.pop_back();
            }
        }
        
        void printScores() const {
            std::cout << "Score Board:" << std::endl;
            int number = 1;
            for (const auto &playerScore : scores) {
                std::cout << number << " : " << playerScore.name << " = " << playerScore.score << std::endl;
                number++;
            }
        }
};

int main()
{
    ScoreBoard scoreBoard;
    // declare variables
    std::string name;
    int score;
    int n = 4;
    // input
    for (int i = 0; i < n; i++)
    {
        std::cout << "Name " << i+1 << ": ";
        std::cin >> name;
        std::cout << "Score : ";
        std::cin >> score;
        scoreBoard.addScore(name, score);
    }
    scoreBoard.printScores();

    char addMore;
    std::cout << "add scores? (y/n) ";
    std::cin >> addMore;
    int i = n + 1;
    while (addMore == 'y')
    {
        std::cout << "Name " << i << ": ";
        std::cin >> name;
        std::cout << "Score : ";
        std::cin >> score;
        scoreBoard.addScore(name, score);
        scoreBoard.printScores();
        std::cout << "add score? (y/n) : ";
        std::cin >> addMore;
        i++;
    }
}
