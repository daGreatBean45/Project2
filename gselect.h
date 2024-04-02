#ifndef GSELECT_HH
#define GSELECT_HH

#include <vector>

class GSelectBP{
    public:
        //testing to see if this shows up on the github
        GSelectBP(int size, int ctrBits, int hstryBits);
        bool lookup(int branch_address);
        void update(int branch_address, bool taken, bool squashed);
        void uBranch(bool taken);
        void btbUpdate();
        bool squash();
    private:
        int bpHistory;
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
        int prevGlobalHistory;
        int PHTThreshold;
        std::vector<int> predictorTable;
};
#endif