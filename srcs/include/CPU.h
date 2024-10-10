#ifndef CPU_H
#define CPU_H
#include <string>
#include <vector>
#include "Class.h"

class Cpu {
private:
	int pid;
	char symbol;
	int numPreemp;
	int numContSwitch;
	std::string grid;
	int deadline;
	unsigned int time;
    std::vector<std::pair<std::pair<int, int>, char>> gridTempos;
public:
	Cpu();
	~Cpu();
	void load(int p, char s, int c, int d, int comput);
	void run(int timeTP);
	std::string getGrid();
	int getNumPreemp();
	int getNumContSwitch();
    void execute(std::vector<Periodicas> periodicas, std::vector<Aperiodicas> aperiodicas, int T, int pid);
    void setgridTempo(std::vector<std::pair<std::pair<int, int>, char>> gridTempos);
    std::vector<std::pair<std::pair<int, int>, char>> getgridTempo();
};

#endif
