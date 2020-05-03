#pragma once

#include <cstdint>
#include <string>

#include "argonishche.h"

namespace cpuid {
    class CpuId {
    public:
        explicit CpuId(int i);
        const int& EAX() const;
        const int& EBX() const;
        const int& ECX() const;
        const int& EDX() const;

        static constexpr int FlagAVX2BMI12 =  (1 << 5) | (1 << 3) | (1 << 8);
        static constexpr int FlagFMAMOVBEOSXSAVE = ((1 << 12) | (1 << 22) | (1 << 27));
        static constexpr int FlagSSE41 = 1 << 19;
        static constexpr int FlagSSE42 = 1 << 20;
        static constexpr int FlagSSSE3 = 1 << 9;
        static constexpr int FlagSSE2 = 1 << 26;

    public:
        static std::string GetVendor();
        static argonishche::InstructionSet GetBestSet();
        static bool HasAVX2BMI12();
        static bool HasSSE41();
        static bool HasSSE42();
        static bool HasSSSE3();
        static bool HasSSE2();

    protected:
        int regs[4];
    };
}
