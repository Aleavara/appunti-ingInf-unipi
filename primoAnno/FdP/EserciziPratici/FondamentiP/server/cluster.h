//
// Created by Alessio Avarappattu on 19/11/25.
//

#ifndef WORKSPACE_FONDAMENTI_CLUSTER_H
#define WORKSPACE_FONDAMENTI_CLUSTER_H
struct processo {
    char* nome;
    int carico;
    processo* next;
};

class cluster {
    private:
    processo** servers;
    int* capacita_max;
    int n_servers;

    public:
    cluster(int n,int cap_default);
};


#endif //WORKSPACE_FONDAMENTI_CLUSTER_H