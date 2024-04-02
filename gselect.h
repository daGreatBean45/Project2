#ifndef GSELECT_HH
#define GSELECT_HH

#include <vector>

class GSelectBP{
    public:
        //testing to see if this shows up on the github
        GSelectBP(int size, int ctrBits, int globalHistoryBits);
        bool lookup(int branch_address);
        void update(int branch_address, bool taken, bool squashed);
        void uBranch(bool taken);
        void btbUpdate();
        bool squash(bool bp_history);
    private:
        int bBranch;
        int size;
        int branchMask;
        int phtHistoryBits;
        int predictorSize;
        int phtcCTRbits;
        int globalHistoryBits;
        int globalHistoryMask;
        int globalHistoryReg;
        int prevGlobalHistory;
        int PHTThreshold;
        std::vector<bool> globalHistory;
        std::vector<int> predictorTable;
};
#endif