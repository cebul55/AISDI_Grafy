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
        assert(argc != 1 ||argc != 2);
        switch (argc){
            case 1:{
                std::cout<<"Enter number of nodes and number of edges\n";
                int nodes, edges , a , b;
                std::cin>>nodes>>edges;
                numberOfNodes_=nodes;
                numberOfEdges_=edges;
                edgesVector_ = new std::vector<int> [numberOfEdges_];
                for(int i = 0 ; i < numberOfEdges_ ; i++){
                    std::cin>>a>>b;
                    assert( a<numberOfNodes_ || b < numberOfEdges_ );
                    edgesVector_[i].push_back(a);
                    edgesVector_[i].push_back(b);
                }
                break;
            }
            case 2:{
                /*reading text file*/
                std::string line,fileText;
                int edges = -1;
                line = argv[1];
                std::ifstream inputFile;
                inputFile.open(line);
                while(!inputFile.eof()){
                    getline(inputFile,line);
                    fileText+=line;
                    fileText+='\n';
                    ++edges;
                }
                inputFile.close();
                /*Adding edges and nodes to class InputMOde */
                numberOfNodes_=atoi(&fileText[0]);
                numberOfEdges_=edges;
                edgesVector_ = new std::vector<int> [numberOfEdges_];
                //starting from second char, because we have number of nodes already
                edges = 0;
                for(int i = 2; line[i]!='\0'; i = i+4){
                    edgesVector_[edges].push_back(atoi(&line[i]));
                    edgesVector_[edges].push_back(atoi(&line[i+2]));
                    ++edges;
                }
                for(int i = 0 ; i < numberOfEdges_ ; i++){
                    std::cout<<edgesVector_[i][0]<<" ";
                    std::cout<<edgesVector_[i][1]<<std::endl;
                }
                break;
            }

        }

    }
    ~InputMode(){
        delete [] edgesVector_;
    }
};

#endif //GRAFY_INPUTMODE_H
