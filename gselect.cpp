#include <iostream>
#include "gselect.h"
GSelectBP::GSelectBP(int size, int ctrBits, int globalHistoryBits){
    phtHistoryBits = size * ctrBits;
    bBranch = sizeof(int) * 8;
    branchMask = (1 << bBranch) - 1;
    globalHistoryMask = (1 << globalHistoryBits) - 1;
    PHTThreshold = (1 << (ctrBits - 1));
    prevGLobalHistory = 0;
}

bool GSelectBP::lookup(int branch_address){
    //define 'n' bits of global history and 'm' bit of branch address
    int global_history = globalHistoryReg & globalHistoryMask;
    int branch_address_bits = branch_address & branchMask;

    //calculate PHTIdx using 'm' and 'n'
    int PHTIdx = (branch_address_bits ^ global_history) % (1 << phtHistoryBits);

    //modify the history using the thread to determine a prediction
    return predictorTable[PHTIdx] >= PHTThreshold;

}
void GSelectBP::update(int branch_address, bool taken, bool squashed){

    //modify the history.
    int global_history = globalHistoryReg & globalHistoryMask;
    int branch_address_bits = branch_address & branchMask;
    //if squashed {do something}, otherwise {do something else}.
    bool squashed = squash();
    if(squashed){
        // Restore global history if it was updated during the prediction of the branch
        // Do not update counters
        globalHistoryReg = prevGlobalHistory;
    }
    // Calculate PHTIdx using m and n
    int PHTIdx = (branch_address_bits ^ global_history) % (1 << phtHistoryBits);

    // Update PHTCounters accordingly to whether the branch is taken or not
    if (taken) {
        if (predictorTable[PHTIdx] < ((1 << phtcCTRbits) - 1)) {
            predictorTable[PHTIdx]++;
        }
    } else {
        if (predictorTable[PHTIdx] > 0) {
            predictorTable[PHTIdx]--;
        }
    }

    // Update global history
    previousGlobalHistory = globalHistoryReg;
    globalHistoryReg = ((globalHistoryReg << 1) | taken) & globalHistoryMask;

    // Delete the history (if needed, depending on the specific requirements)
    // Here, we reset any additional state variables that represent history
    
}
void GSelectBP::uBranch(bool taken){
    //modify the history using the thread
    //modify the prediction attribute and global attribute of the history
    globalHistoryReg = ((globalHistoryReg << 1) | taken) & globalHistoryMask;
}
void GSelectBP::btbUpdate(){
    //modify the globalHistoryReg of the thread
    globalHistoryReg = (globalHistoryReg << 1) & globalHistoryMask;
}
void GSelectBP::squash(){
    //modify the globalHistoryReg of the thread
    //delete the history
    globalHistoryReg = 0;
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
