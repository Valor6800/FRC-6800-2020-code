#include "ValorTrajectory.h"
#include <unordered_map>

class Trajectories {
    public:
        Trajectories();

        std::unordered_map<std::string, std::vector<ValorTrajectory>> paths;

        std::vector<ValorTrajectory> eightBallPath;
        std::vector<ValorTrajectory> tenBallPath;
    private:
        
}