#ifndef GSELECT_HH
#define GSELECT_HH

#include <vector>

class GSelectBP{
    public:
        GSelectBP(int size, int ctrBits, int hstryBits);
        bool lookup(int branch_address);
        void update(int branch_address, bool taken, bool squashed);
        void uBranch(bool taken);
        void btbUpdate();
        void squash(int bpHistory);
    private:
        int bpHistory;
        int size;
        int branchMask;
        int phtHistoryBits;
        int predictorSize;
        int phtcCTRbits;
        int globalHistoryBits;
        int globalHistory;
        std:vector<int> predictorTable;
}
#endif