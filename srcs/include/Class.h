#ifndef CLASS_H
#define CLASS_H

class Periodicas{
    private:
        int computacao;
        int periodo;
        int deadline;
        char letraP;
        int pid;
    public:
        Periodicas(int computacao, int periodo, int deadline, char letra, int pid);
        Periodicas();
        ~Periodicas();
        int getComputacao();
        int getPeriodo();
        int getDeadline();
        char getLetra();
        int getPid();
        void setPid(int pid);
        };

class Aperiodicas{
    private:
        int computacao;
        int chegada;
        char letraAP;
        int pid;
    public:
        Aperiodicas(int chegada, int computacao, char letra, int pid);
        Aperiodicas();
        ~Aperiodicas();
        int getComputacao();
        int getChegada();
        char getLetra();
        int getPid();
};

#endif