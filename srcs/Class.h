#ifndef CLASS_H
#define CLASS_H

class Periodicas{
    private:
        int computacao;
        int periodo;
        int deadline;
        int auxComputacao;
        char letraP;
    public:
        Periodicas(int computacao, int periodo, int deadline, char letra);
        Periodicas();
        ~Periodicas();
        int getComputacao();
        int getPeriodo();
        int getDeadline();
        char getLetra();
        int getAuxComputacao();
        void setAuxComputacao();
};

class Aperiodicas{
    private:
        int computacao;
        int chegada;
        char letraAP;
    public:
        Aperiodicas(int chegada, int computacao, char letra);
        Aperiodicas();
        ~Aperiodicas();
        int getComputacao();
        int getChegada();
        char getLetra();
};

#endif