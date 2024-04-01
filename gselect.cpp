#include <iostream>
#include "gselect.h"
GSelectBP::GSelectBP(int size, int ctrBits, int globalHistoryBits){
    phtHistoryBits = size * ctrBits;
    bBranch = sizeof(int) * 8;
    branchMask  
}

bool GSelectBP::lookup(int branch_address){
    //define 'n' bits of global history and 'm' bit of branch address
    //calculate PHTIdx using 'm' and 'n'
    //modify the history using the thread to determine a prediction
}
void GSelectBP::update(int branch_address, bool taken, bool squashed){

    //modify the history.
    //if squashed {do something}, otherwise {do something else}.
    //calculate PHTIdx using m and n.
    //update PHTCounters accordingly to whether the branch is taken or not.
    //delete the history
    bool squashed = squash();
    if(squashed == true){

    }
    else{

    }
}
void GSelectBP::uBranch(bool taken){
    //modify the history using the thread
    //modify the prediction attribute and global attribute of the history
}
void GSelectBP::btbUpdate(){
    //modify the globalHistoryReg of the thread
}
void GSelectBP::squash(){
    //modify the globalHistoryReg of the thread
    //delete the history
}

int main(){
    int branch_addr = 0x12345678;
    bool prediction = predictor.lookup(branch_addr);
    bool actual_outcome = true;
    bool squashed = false;
    
    predictor.update(branch_addr, actual_outcome, squashed);
    predictor.uBranch(true);
    predictor.btbUpdate();
    predictor.squashed();
    
    return 0;
}