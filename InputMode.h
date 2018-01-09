//
// Created by Bartosz Cybulski on 09.01.2018.
//

#ifndef GRAFY_INPUTMODE_H
#define GRAFY_INPUTMODE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <string>

class InputMode{
    int numberOfNodes_;
    int numberOfEdges_;
    std::vector<int> *edgesVector_;
public:
    InputMode(int argc , char ** argv){
        assert(argc == 1 || argc == 2);
        int nodes, edges , a , b;
        switch (argc){
            case 1:{
                std::cout<<"Enter number of nodes and number of edges\n";

                std::cin>>nodes>>edges;
                numberOfNodes_=nodes;
                numberOfEdges_=edges;
                edgesVector_ = new std::vector<int> [numberOfEdges_];
                for(int i = 0 ; i < numberOfEdges_ ; i++){
                    std::cin>>a>>b;
                    edgesVector_[i].push_back(a);
                    edgesVector_[i].push_back(b);
                }
                break;
            }
            case 2:{
                /*reading text file*/
                std::string line,fileText;
                edges = -1;
                line = argv[1];
                std::ifstream inputFile;

                inputFile.open(line);
                //if(inputFile == NULL )
                  //  throw std::perror("Error opening file");

                while(!inputFile.eof()){
                    getline(inputFile,line);
                    fileText+=line;
                    fileText+='\n';
                    ++edges;
                }
                inputFile.close();
                /*Adding edges and nodes to class InputMOde */
                numberOfEdges_=edges;
                edges=0;
                edgesVector_ = new std::vector<int> [numberOfEdges_];
                for(int i = 0 ; fileText[i]!='\0' ;){
                    if(i == 0)
                        numberOfNodes_=atoi(&fileText[i]);
                    else{
                        a=atoi(&fileText[i]);

                        while(fileText[i]!=' ')
                            i++;

                        b=atoi(&fileText[i]);
                        edgesVector_[edges].push_back(a);
                        edgesVector_[edges].push_back(b);
                        ++edges;
                    }
                    while(fileText[i]!='\n'){
                        ++i;
                    }
                    ++i;
                }
                /*for(int i = 0 ; i < numberOfEdges_ ; i++){
                    std::cout<<edgesVector_[i][0]<<" ";
                    std::cout<<edgesVector_[i][1]<<std::endl;
                }*/
                break;
            }

        }

    }
    ~InputMode(){
        delete [] edgesVector_;
    }
    int getNumberOfEdges(){
        return numberOfEdges_;
    }
    int getNumberOfNodes(){
        return numberOfNodes_;
    }
    std::vector<int>* getEdgesVector(){
        return edgesVector_;
    }
};

#endif //GRAFY_INPUTMODE_H
