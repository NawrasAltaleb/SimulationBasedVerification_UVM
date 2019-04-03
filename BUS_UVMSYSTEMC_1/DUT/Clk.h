#ifndef SYSTEMC_Clk_H
#define SYSTEMC_Clk_H


#include "systemc.h"
#include "Interfaces.h"
#include "Data_Types.h"

  struct Clk : public sc_module {

    enum Sections {run};
    Sections section;

    slave_out<bool> clk1;
    slave_out<bool> clk2;
    slave_out<bool> clk3;
    slave_out<bool> clk4;
    slave_out<bool> clk5;
    slave_out<bool> clk6;

    //functions



    void FSM(){
        while(true) {
          if (section==run) {
            if(!coveragePoints["Clk_1"]){
              coveragePoints["Clk_1"] = true;
              coveragePointsCount++;
            }
            clk1->nb_write(true);
            clk2->nb_write(true);
            clk3->nb_write(true);
            clk4->nb_write(true);
            clk5->nb_write(true);
            clk6->nb_write(true);
          }
          wait(SC_ZERO_TIME);
        }//end of while
    }//end of FSM
    int coveragePointsTotal = 1;
    int coveragePointsCount = 0;
    std::map<std::string, bool> coveragePoints;

    SC_HAS_PROCESS(Clk);

    Clk(sc_module_name name) :
      section(run)    {
      SC_THREAD(FSM);
      for(int i = 1; i < coveragePointsTotal; i++)
            coveragePoints.insert(std::make_pair("Clk_"+to_string(i),false));
      }
    };//end of module


#endif //SYSTEMC_Clk_H
