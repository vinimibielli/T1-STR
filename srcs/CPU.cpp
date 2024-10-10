#include <iostream>
#include <string>
#include "CPU.h"
#include <vector>

Cpu::Cpu()
{
    grid = "";
    numPreemp = numContSwitch = 0;
    pid = -1;
    symbol = ' ';
    time = 0;
    deadline = -1;
}

Cpu::~Cpu() {}

void Cpu::load(int p, char s, int c, int d, int comput)
{
    symbol = s;
    deadline = d;
    if (pid == -1)
        pid = p;
    else
    {
        if (pid != p)
        {
            pid = p;
            ++numContSwitch;
            if (comput > 0)
                ++numPreemp;
        }
    }
}

void Cpu::run(int timeTP)
{
    if (pid != -1)
    {
        if (deadline != -1 && timeTP >= deadline)
            grid.append(1, tolower(symbol));
        else
            grid.append(1, symbol);
        ++time;
    }
    else
    {
        ++time;
        grid.append(1, '_');
    }
}

std::string Cpu::getGrid()
{
    return grid;
}

int Cpu::getNumPreemp()
{
    return numPreemp;
}

int Cpu::getNumContSwitch()
{
    return numContSwitch;
}

void Cpu::execute(std::vector<Periodicas> periodicas, std::vector<Aperiodicas> aperiodicas, int T, int pid)
{

    std::vector<std::pair<std::pair<int, int>, Periodicas>> TP;
    std::vector<std::pair<int, Aperiodicas>> TA;
    int tempo = 0;
    int tag = pid;
    bool flag = false;
    for (int i = 0; i < periodicas.size(); i++)
    {
        TP.push_back(std::make_pair(std::make_pair(0, 0), periodicas[i]));
    }
    for (int i = 0; i < aperiodicas.size(); i++)
    {
        TA.push_back(std::make_pair(0, aperiodicas[i]));
    }

    std::cout << TA.size() << std::endl;

    while (tempo < T)
    {
        std::cout << "Tamanho de TP: " << TP.size() << " Tempo: " << tempo << std::endl;
        for (int i = periodicas.size() - 1; i >= 0; i--)
        {
            if (tempo % periodicas[i].getPeriodo() == 0 && tempo != 0)
            {
                std::cout << "Preempcao da tarefa " << periodicas[i].getLetra() << std::endl;
                if (periodicas[i].getPeriodo() < TP[0].second.getPeriodo() && TP.size() != 0)
                {
                    TP.insert(TP.begin(), std::make_pair(std::make_pair(0, 0), periodicas[i]));
                    tag++;
                    TP[1].second.setPid(tag);
                }
                else
                {
                    TP.push_back(std::make_pair(std::make_pair(0, 0), periodicas[i]));
                }
                flag = true;
            }
        }

        if (TP.size() != 0)
        {
            load(TP[0].second.getPid(), TP[0].second.getLetra(), TP[0].second.getComputacao(), TP[0].second.getDeadline(), TP[0].first.first);
            run(TP[0].first.second);
            std::cout << "Tarefa " << TP[0].second.getLetra() << " executada" << std::endl;
            TP[0].first.first++;
        

        if (TP[0].first.first == TP[0].second.getComputacao())
        {
            //std::cout << "Tarefa " << TP[0].second.getLetra() << " finalizada" << std::endl;
            TP.erase(TP.begin());
        }

        for (int i = 0; i < TP.size(); i++)
        {
            TP[i].first.second++;
        }
        } else{
            if(TA.size() != 0 && TA[0].second.getChegada() <= tempo){

                load(TA[0].second.getPid(), TA[0].second.getLetra(), TA[0].second.getComputacao(), 30, TA[0].first);
                run(TA[0].first);
                std::cout << "Tarefa " << TA[0].second.getLetra() << " executada" << std::endl;
                TA[0].first++;
                if(TA[0].first == TA[0].second.getComputacao()){
                    TA.erase(TA.begin());
                }
            } else{
                load(0, '.', 0, 0, 0);
                run(0);   
            }
        }
        tempo++;
    }
    if(grid[grid.size() - 1] == '.'){
        numPreemp++;
        numContSwitch++;
    }
}
