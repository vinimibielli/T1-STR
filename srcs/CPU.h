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
public:
	Cpu();
	~Cpu();
	void load(int p, char s, int c, int d, int comput);
	void run(int timeTP);
	std::string getGrid();
	int getNumPreemp();
	int getNumContSwitch();
    void execute(std::vector<Periodicas> periodicas, std::vector<Aperiodicas> aperiodicas, int T, int pid);
};

#endif
