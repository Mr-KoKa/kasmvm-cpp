#include <iostream>
#include <random>
#include <thread>

#include "helper.h"

#include "vm.h"

class Instructions {
    public:
        
    const static int32_t MICROCODE_MAX = 269;
    const static intptr_t BY_MICROCODE[MICROCODE_MAX + 1][3];    

    static inline void mov_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, i);
    }

    static inline void mov_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, vm.getReg(r2));
    }

    static inline void mov_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, vm.getMem(p));
    }

    static inline void mov_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, vm.getMem(vm.getReg(rp)));
    }

    static inline void mov_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, i);
    }

    static inline void mov_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, vm.getReg(r));
    }

    static inline void mov_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, vm.getMem(p2));
    }

    static inline void mov_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, vm.getMem(vm.getReg(rp)));
    }

    static inline void mov_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), i);
    }

    static inline void mov_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), vm.getReg(r));
    }

    static inline void mov_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), vm.getMem(p));
    }

    static inline void mov_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), vm.getMem(vm.getReg(rp2)));
    }



    static inline void cmp_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, a
            cmp eax, b    
            pushf
            pop flags
        }

        vm.setFlags(flags);
    }

    static inline void cmp_int_int(VM &vm, int32_t i1, int32_t i2){
        cmp_helper(vm, i1, i2);
    }

    static inline void cmp_int_reg(VM &vm, int32_t i, int32_t r){
        cmp_helper(vm, i, vm.getReg(r));
    }

    static inline void cmp_int_ptr(VM &vm, int32_t i, int32_t p){
        cmp_helper(vm, i, vm.getMem(p));
    }

    static inline void cmp_int_regptr(VM &vm, int32_t i, int32_t rp){
        cmp_helper(vm, i, vm.getMem(vm.getReg(rp)));
    }

    static inline void cmp_reg_int(VM &vm, int32_t r, int32_t i){
        cmp_helper(vm, vm.getReg(r), i);
    }

    static inline void cmp_reg_reg(VM &vm, int32_t r1, int32_t r2){
        cmp_helper(vm, vm.getReg(r1), vm.getReg(r2));
    }

    static inline void cmp_reg_ptr(VM &vm, int32_t r, int32_t p){
        cmp_helper(vm, vm.getReg(r), vm.getMem(p));
    }

    static inline void cmp_reg_regptr(VM &vm, int32_t r, int32_t rp){
        cmp_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp)));
    }

    static inline void cmp_ptr_int(VM &vm, int32_t p, int32_t i){
        cmp_helper(vm, vm.getMem(p), i);
    }

    static inline void cmp_ptr_reg(VM &vm, int32_t p, int32_t r){
        cmp_helper(vm, vm.getMem(p), vm.getReg(r));
    }

    static inline void cmp_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        cmp_helper(vm, vm.getMem(p1), vm.getMem(p2));
    }

    static inline void cmp_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        cmp_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp)));
    }

    static inline void cmp_regptr_int(VM &vm, int32_t rp, int32_t i){
        cmp_helper(vm, vm.getMem(vm.getReg(rp)), i);
    }

    static inline void cmp_regptr_reg(VM &vm, int32_t rp, int32_t r){
        cmp_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r));
    }

    static inline void cmp_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        cmp_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p));
    }

    static inline void cmp_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        cmp_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2)));
    }



    static inline void test_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, a
            test eax, b    
            pushf
            pop flags
        }

        vm.setFlags(flags);
    }

    static inline void test_int_int(VM &vm, int32_t i1, int32_t i2){
        test_helper(vm, i1, i2);
    }

    static inline void test_int_reg(VM &vm, int32_t i, int32_t r){
        test_helper(vm, i, vm.getReg(r));
    }

    static inline void test_int_ptr(VM &vm, int32_t i, int32_t p){
        test_helper(vm, i, vm.getMem(p));
    }

    static inline void test_int_regptr(VM &vm, int32_t i, int32_t rp){
        test_helper(vm, i, vm.getMem(vm.getReg(rp)));
    }

    static inline void test_reg_int(VM &vm, int32_t r, int32_t i){
        test_helper(vm, vm.getReg(r), i);
    }

    static inline void test_reg_reg(VM &vm, int32_t r1, int32_t r2){
        test_helper(vm, vm.getReg(r1), vm.getReg(r2));
    }

    static inline void test_reg_ptr(VM &vm, int32_t r, int32_t p){
        test_helper(vm, vm.getReg(r), vm.getMem(p));
    }

    static inline void test_reg_regptr(VM &vm, int32_t r, int32_t rp){
        test_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp)));
    }

    static inline void test_ptr_int(VM &vm, int32_t p, int32_t i){
        test_helper(vm, vm.getMem(p), i);
    }

    static inline void test_ptr_reg(VM &vm, int32_t p, int32_t r){
        test_helper(vm, vm.getMem(p), vm.getReg(r));
    }

    static inline void test_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        test_helper(vm, vm.getMem(p1), vm.getMem(p2));
    }

    static inline void test_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        test_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp)));
    }

    static inline void test_regptr_int(VM &vm, int32_t rp, int32_t i){
        test_helper(vm, vm.getMem(vm.getReg(rp)), i);
    }

    static inline void test_regptr_reg(VM &vm, int32_t rp, int32_t r){
        test_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r));
    }

    static inline void test_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        test_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p));
    }

    static inline void test_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        test_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2)));
    }



    static inline void jmp_int(VM &vm, int32_t i){
        vm.setControl(i);
    }

    static inline void jmp_reg(VM &vm, int32_t r){
        vm.setControl(vm.getReg(r));
    }

    static inline void jmp_ptr(VM &vm, int32_t p){
        vm.setControl(vm.getMem(p));
    }

    static inline void jmp_regptr(VM &vm, int32_t rp){
        vm.setControl(vm.getMem(vm.getReg(rp)));
    }



    static inline void jz_int(VM &vm, int32_t i){
        if(vm.flagZero){
            vm.setControl(i);
        }
    }

    static inline void jnz_int(VM &vm, int32_t i){
        if(!vm.flagZero){
            vm.setControl(i);
        }
    }

    static inline void js_int(VM &vm, int32_t i){
        if(vm.flagSign){
            vm.setControl(i);
        }
    }

    static inline void jns_int(VM &vm, int32_t i){
        if(!vm.flagSign){
            vm.setControl(i);
        }
    }

    static inline void jo_int(VM &vm, int32_t i){
        if(vm.flagOverflow){
            vm.setControl(i);
        }
    }

    static inline void jno_int(VM &vm, int32_t i){
        if(!vm.flagOverflow){
            vm.setControl(i);
        }
    }

    static inline void je_int(VM &vm, int32_t i){
        if(vm.flagZero){
            vm.setControl(i);
        }
    }

    static inline void jne_int(VM &vm, int32_t i){
        if(!vm.flagZero){
            vm.setControl(i);
        }
    }

    static inline void jg_int(VM &vm, int32_t i){
        if(!vm.flagZero && (vm.flagSign == vm.flagOverflow)){
            vm.setControl(i);
        }
    }

    static inline void jge_int(VM &vm, int32_t i){
        if(vm.flagSign == vm.flagOverflow){
            vm.setControl(i);
        }
    }

    static inline void jl_int(VM &vm, int32_t i){
        if(vm.flagSign != vm.flagOverflow){
            vm.setControl(i);
        }
    }

    static inline void jle_int(VM &vm, int32_t i){
        if(vm.flagZero || (vm.flagSign != vm.flagOverflow)){
            vm.setControl(i);
        }
    }



    static inline int32_t add_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, b
            add a, eax
            pushf
            pop flags
        }

        vm.setFlags(flags);

        return a;
    }

    static inline void add_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, add_helper(vm, vm.getReg(r), i));
    }

    static inline void add_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, add_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void add_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, add_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void add_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, add_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void add_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, add_helper(vm, vm.getMem(p), i));
    }

    static inline void add_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, add_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void add_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, add_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void add_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, add_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void add_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), add_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void add_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), add_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void add_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), add_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void add_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), add_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline int32_t sub_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, b
            sub a, eax
            pushf
            pop flags
        }

        vm.setFlags(flags);

        return a;
    }

    static inline void sub_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, sub_helper(vm, vm.getReg(r), i));
    }

    static inline void sub_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, sub_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void sub_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, sub_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void sub_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, sub_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void sub_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, sub_helper(vm, vm.getMem(p), i));
    }

    static inline void sub_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, sub_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void sub_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, sub_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void sub_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, sub_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void sub_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), sub_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void sub_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), sub_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void sub_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), sub_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void sub_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), sub_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline void push_int(VM &vm, int32_t i){
        vm.pushStack(i);
    }

    static inline void push_reg(VM &vm, int32_t r){
        vm.pushStack(vm.getReg(r));
    }

    static inline void push_ptr(VM &vm, int32_t p){
        vm.pushStack(vm.getMem(p));
    }

    static inline void push_regptr(VM &vm, int32_t rp){
        vm.pushStack(vm.getMem(vm.getReg(rp)));
    }



    static inline void pop_reg(VM &vm, int32_t r){
        vm.setReg(r, vm.popStack());
    }

    static inline void pop_ptr(VM &vm, int32_t p){
        vm.setMem(p, vm.popStack());
    }

    static inline void pop_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), vm.popStack());
    }



    static inline void call_int(VM &vm, int32_t i){
        vm.pushStack(vm.getControl());
        vm.setControl(i);
    }

    static inline void call_reg(VM &vm, int32_t r){
        vm.pushStack(vm.getControl());
        vm.setControl(vm.getReg(r));
    }

    static inline void call_ptr(VM &vm, int32_t p){
        vm.pushStack(vm.getControl());
        vm.setControl(vm.getMem(p));
    }

    static inline void call_regptr(VM &vm, int32_t rp){
        vm.pushStack(vm.getControl());
        vm.setControl(vm.getMem(vm.getReg(rp)));
    }



    static inline void ret_(VM &vm){
        vm.setControl(vm.popStack());
    }



    static inline void int_helper(VM &vm, int32_t value){
        vm.interrupt(value, vm.getReg(0), vm.getReg(3), vm.getReg(2), vm.getReg(1));
    }

    static inline void int_int(VM &vm, int32_t i){
        int_helper(vm, i);
    }

    static inline void int_reg(VM &vm, int32_t r){
        int_helper(vm, vm.getReg(r));
    }

    static inline void int_ptr(VM &vm, int32_t p){
        int_helper(vm, vm.getMem(p));
    }

    static inline void int_regptr(VM &vm, int32_t rp){
        int_helper(vm, vm.getMem(vm.getReg(rp)));
    }



    static inline void xwi_int(VM &vm, int32_t i){
        std::cout << i;
    }

    static inline void xwi_reg(VM &vm, int32_t r){
        std::cout << vm.getReg(r);
    }

    static inline void xwi_ptr(VM &vm, int32_t p){
        std::cout << vm.getMem(p);
    }

    static inline void xwi_regptr(VM &vm, int32_t rp){
        std::cout << vm.getMem(vm.getReg(rp));
    }



    static inline void xwr_int(VM &vm, int32_t i){
        //std::cout << "[" << i << "]";
        std::cout << UnicodeToUTF8(i);
    }

    static inline void xwr_reg(VM &vm, int32_t r){
        //std::cout << "[" << vm.getReg(r) << "]";
        std::cout << UnicodeToUTF8(vm.getReg(r));
    }

    static inline void xwr_ptr(VM &vm, int32_t p){
        //std::cout << "[" << vm.getMem(p) << "]";
        std::cout << UnicodeToUTF8(vm.getMem(p));
    }

    static inline void xwr_regptr(VM &vm, int32_t rp){
        //std::cout << "[" << vm.getMem(vm.getReg(rp)) << "]";
        std::cout << UnicodeToUTF8(vm.getMem(vm.getReg(rp)));
    }

    static inline void xwr_helper(VM &vm, int32_t ptr, int32_t length){
        vm.interrupt(0x80, 4, length, ptr, 1);
    }

    static inline void xwr_int_int(VM &vm, int32_t i1, int32_t i2){
        xwr_helper(vm, i1, i2);
    }

    static inline void xwr_int_reg(VM &vm, int32_t i, int32_t r){
        xwr_helper(vm, i, vm.getReg(r));
    }

    static inline void xwr_int_ptr(VM &vm, int32_t i, int32_t p){
        xwr_helper(vm, i, vm.getMem(p));
    }

    static inline void xwr_int_regptr(VM &vm, int32_t i, int32_t rp){
        xwr_helper(vm, i, vm.getMem(vm.getReg(rp)));
    }

    static inline void xwr_reg_int(VM &vm, int32_t r, int32_t i){
        xwr_helper(vm, vm.getReg(r), i);
    }

    static inline void xwr_reg_reg(VM &vm, int32_t r1, int32_t r2){
        xwr_helper(vm, vm.getReg(r1), vm.getReg(r2));
    }

    static inline void xwr_reg_ptr(VM &vm, int32_t r, int32_t p){
        xwr_helper(vm, vm.getReg(r), vm.getMem(p));
    }

    static inline void xwr_reg_regptr(VM &vm, int32_t r, int32_t rp){
        xwr_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp)));
    }

    static inline void xwr_ptr_int(VM &vm, int32_t p, int32_t i){
        xwr_helper(vm, vm.getMem(p), i);
    }

    static inline void xwr_ptr_reg(VM &vm, int32_t p, int32_t r){
        xwr_helper(vm, vm.getMem(p), vm.getReg(r));
    }

    static inline void xwr_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        xwr_helper(vm, vm.getMem(p1), vm.getMem(p2));
    }

    static inline void xwr_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        xwr_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp)));
    }

    static inline void xwr_regptr_int(VM &vm, int32_t rp, int32_t i){
        xwr_helper(vm, vm.getMem(vm.getReg(rp)), i);
    }

    static inline void xwr_regptr_reg(VM &vm, int32_t rp, int32_t r){
        xwr_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r));
    }

    static inline void xwr_regptr_ptr(VM &vm, int32_t rp, int32_t p2){
        xwr_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p2));
    }

    static inline void xwr_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        xwr_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2)));
    }



    static inline void xrd_helper(VM &vm, int32_t ptr, int32_t length){
        vm.interrupt(0x80, 3, length, ptr, 0);
    }

    static inline void xrd_int_int(VM &vm, int32_t i1, int32_t i2){
        xrd_helper(vm, i1, i2);
    }

    static inline void xrd_int_reg(VM &vm, int32_t i, int32_t r){
        xrd_helper(vm, i, vm.getReg(r));
    }

    static inline void xrd_int_ptr(VM &vm, int32_t i, int32_t p){
        xrd_helper(vm, i, vm.getMem(p));
    }

    static inline void xrd_int_regptr(VM &vm, int32_t i, int32_t rp){
        xrd_helper(vm, i, vm.getMem(vm.getReg(rp)));
    }

    static inline void xrd_reg_int(VM &vm, int32_t r, int32_t i){
        xrd_helper(vm, vm.getReg(r), i);
    }

    static inline void xrd_reg_reg(VM &vm, int32_t r1, int32_t r2){
        xrd_helper(vm, vm.getReg(r1), vm.getReg(r2));
    }

    static inline void xrd_reg_ptr(VM &vm, int32_t r, int32_t p){
        xrd_helper(vm, vm.getReg(r), vm.getMem(p));
    }

    static inline void xrd_reg_regptr(VM &vm, int32_t r, int32_t rp){
        xrd_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp)));
    }

    static inline void xrd_ptr_int(VM &vm, int32_t p, int32_t i){
        xrd_helper(vm, vm.getMem(p), i);
    }

    static inline void xrd_ptr_reg(VM &vm, int32_t p, int32_t r){
        xrd_helper(vm, vm.getMem(p), vm.getReg(r));
    }

    static inline void xrd_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        xrd_helper(vm, vm.getMem(p1), vm.getMem(p2));
    }

    static inline void xrd_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        xrd_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp)));
    }

    static inline void xrd_regptr_int(VM &vm, int32_t rp, int32_t i){
        xrd_helper(vm, vm.getMem(vm.getReg(rp)), i);
    }

    static inline void xrd_regptr_reg(VM &vm, int32_t rp, int32_t r){
        xrd_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r));
    }

    static inline void xrd_regptr_ptr(VM &vm, int32_t rp, int32_t p2){
        xrd_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p2));
    }

    static inline void xrd_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        xrd_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2)));
    }



    static inline void xrd_int(VM &vm, int32_t i){
        vm.setReg(0, vm.getReg(0) * i);
    }

    static inline void xrd_reg(VM &vm, int32_t r){
        vm.setReg(0, vm.getReg(0) * vm.getReg(r));
    }

    static inline void xrd_ptr(VM &vm, int32_t p){
        vm.setReg(0, vm.getReg(0) * vm.getMem(p));
    }

    static inline void xrd_regptr(VM &vm, int32_t rp){
        vm.setReg(0, vm.getReg(0) * vm.getMem(vm.getReg(rp)));
    }



    static inline void mul_int(VM &vm, int32_t i){
        vm.setReg(0, (vm.getReg(0) * i));
    }

    static inline void mul_reg(VM &vm, int32_t r){
        vm.setReg(0, (vm.getReg(0) * vm.getReg(r)));
    }

    static inline void mul_ptr(VM &vm, int32_t p){
        vm.setReg(0, (vm.getReg(0) * vm.getMem(p)));
    }

    static inline void mul_regptr(VM &vm, int32_t rp){
        vm.setReg(0, (vm.getReg(0) * vm.getMem(vm.getReg(rp))));
    }



    static inline void div_helper(VM &vm, int32_t b){
        if(b == 0){
            throw VM::ERROR_DIVISION_BY_ZERO;
        }

        const int32_t a = vm.getReg(0);
        vm.setReg(0, a / b);
        vm.setReg(3, a % b);
    }

    static inline void div_int(VM &vm, int32_t i){
        div_helper(vm, i);
    }

    static inline void div_reg(VM &vm, int32_t r){
        div_helper(vm, vm.getReg(r));
    }

    static inline void div_ptr(VM &vm, int32_t p){
        div_helper(vm, vm.getMem(p));
    }

    static inline void div_regptr(VM &vm, int32_t rp){
        div_helper(vm, vm.getMem(vm.getReg(rp)));
    }



    static inline int32_t dec_helper(VM &vm, int32_t a){
        int16_t flags;

        __asm {
            dec a
            pushf
            pop flags
        }

        vm.setFlags(flags);
        return a;
    }

    static inline void dec_reg(VM &vm, int32_t r){
        vm.setReg(r, dec_helper(vm, vm.getReg(r)));
    }

    static inline void dec_ptr(VM &vm, int32_t p){
        vm.setMem(p, dec_helper(vm, vm.getMem(p)));
    }

    static inline void dec_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), dec_helper(vm, vm.getMem(vm.getReg(rp))));
    }



    static inline int32_t inc_helper(VM &vm, int32_t a){
        int16_t flags;

        __asm {
            inc a
            pushf
            pop flags
        }

        vm.setFlags(flags);
        return a;
    }

    static inline void inc_reg(VM &vm, int32_t r){
        vm.setReg(r, inc_helper(vm, vm.getReg(r)));
    }

    static inline void inc_ptr(VM &vm, int32_t p){
        vm.setMem(p, inc_helper(vm, vm.getMem(p)));
    }

    static inline void inc_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), inc_helper(vm, vm.getMem(vm.getReg(rp))));
    }



    static inline int32_t neg_helper(VM &vm, int32_t a){
        int16_t flags;

        __asm {
            neg a
            pushf
            pop flags
        }

        vm.setFlags(flags);
        return a;
    }

    static inline void neg_reg(VM &vm, int32_t r){
        vm.setReg(r, neg_helper(vm, vm.getReg(r)));
    }

    static inline void neg_ptr(VM &vm, int32_t p){
        vm.setMem(p, neg_helper(vm, vm.getMem(p)));
    }

    static inline void neg_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), neg_helper(vm, vm.getMem(vm.getReg(rp))));
    }



    static inline int32_t shl_helper(VM &vm, int32_t a, uint8_t b){
        b &= 0x1F;
        if(b == 0){
            return a;
        }

        int16_t flags;

        __asm {
            mov cl, b
            shl a, cl
            pushf
            pop flags
        }

        vm.setFlags(flags, b == 1);
        return a;
    }

    static inline void shl_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, shl_helper(vm, vm.getReg(r), i));
    }

    static inline void shl_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, shl_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void shl_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, shl_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void shl_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, shl_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void shl_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, shl_helper(vm, vm.getMem(p), i));
    }

    static inline void shl_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, shl_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void shl_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, shl_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void shl_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, shl_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void shl_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), shl_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void shl_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), shl_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void shl_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), shl_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void shl_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), shl_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline int32_t shr_helper(VM &vm, int32_t a, uint8_t b){
        b &= 0x1F;
        if(b == 0){
            return a;
        }

        int16_t flags;

        __asm {
            mov cl, b
            shr a, cl
            pushf
            pop flags
        }

        vm.setFlags(flags, b == 1);
        return a;
    }

    static inline void shr_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, shr_helper(vm, vm.getReg(r), i));
    }

    static inline void shr_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, shr_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void shr_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, shr_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void shr_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, shr_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void shr_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, shr_helper(vm, vm.getMem(p), i));
    }

    static inline void shr_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, shr_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void shr_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, shr_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void shr_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, shr_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void shr_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), shr_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void shr_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), shr_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void shr_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), shr_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void shr_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), shr_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline void not_reg(VM &vm, int32_t r){
        vm.setReg(r, ~vm.getReg(r));
    }

    static inline void not_ptr(VM &vm, int32_t p){
        vm.setMem(p, ~vm.getMem(p));
    }

    static inline void not_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), ~vm.getMem(vm.getReg(rp)));
    }



    static inline int32_t xrnd_helper(){
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int32_t> distribution((std::numeric_limits<int32_t>::min)(), (std::numeric_limits<int32_t>::max)());

        return distribution(gen);
    }

    static inline void xrnd_(VM &vm){
        vm.setReg(0, xrnd_helper());
    }

    static inline void xrnd_reg(VM &vm, int32_t r){
        vm.setReg(r, xrnd_helper());
    }

    static inline void xrnd_ptr(VM &vm, int32_t p){
        vm.setMem(p, xrnd_helper());
    }

    static inline void xrnd_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), xrnd_helper());
    }



    static inline int32_t and_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, b
            and a, eax
            pushf
            pop flags
        }

        vm.setFlags(flags);
        return a;
    }

    static inline void and_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, and_helper(vm, vm.getReg(r), i));
    }

    static inline void and_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, and_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void and_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, and_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void and_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, and_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void and_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, and_helper(vm, vm.getMem(p), i));
    }

    static inline void and_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, and_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void and_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, and_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void and_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, and_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void and_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), and_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void and_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), and_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void and_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), and_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void and_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), and_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline int32_t or_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, b
            or a, eax
            pushf
            pop flags
        }

        vm.setFlags(flags);
        return a;
    }

    static inline void or_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, or_helper(vm, vm.getReg(r), i));
    }

    static inline void or_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, or_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void or_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, or_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void or_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, or_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void or_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, or_helper(vm, vm.getMem(p), i));
    }

    static inline void or_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, or_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void or_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, or_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void or_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, or_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void or_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), or_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void or_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), or_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void or_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), or_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void or_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), or_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline int32_t xor_helper(VM &vm, int32_t a, int32_t b){
        int16_t flags;

        __asm {
            mov eax, b
            xor a, eax
            pushf
            pop flags
        }

        vm.setFlags(flags);
        return a;
    }

    static inline void xor_reg_int(VM &vm, int32_t r, int32_t i){
        vm.setReg(r, xor_helper(vm, vm.getReg(r), i));
    }

    static inline void xor_reg_reg(VM &vm, int32_t r1, int32_t r2){
        vm.setReg(r1, xor_helper(vm, vm.getReg(r1), vm.getReg(r2)));
    }

    static inline void xor_reg_ptr(VM &vm, int32_t r, int32_t p){
        vm.setReg(r, xor_helper(vm, vm.getReg(r), vm.getMem(p)));
    }

    static inline void xor_reg_regptr(VM &vm, int32_t r, int32_t rp){
        vm.setReg(r, xor_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp))));
    }

    static inline void xor_ptr_int(VM &vm, int32_t p, int32_t i){
        vm.setMem(p, xor_helper(vm, vm.getMem(p), i));
    }

    static inline void xor_ptr_reg(VM &vm, int32_t p, int32_t r){
        vm.setMem(p, xor_helper(vm, vm.getMem(p), vm.getReg(r)));
    }

    static inline void xor_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        vm.setMem(p1, xor_helper(vm, vm.getMem(p1), vm.getMem(p2)));
    }

    static inline void xor_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        vm.setMem(p, xor_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp))));
    }

    static inline void xor_regptr_int(VM &vm, int32_t rp, int32_t i){
        vm.setMem(vm.getReg(rp), xor_helper(vm, vm.getMem(vm.getReg(rp)), i));
    }

    static inline void xor_regptr_reg(VM &vm, int32_t rp, int32_t r){
        vm.setMem(vm.getReg(rp), xor_helper(vm, vm.getMem(vm.getReg(rp)), vm.getReg(r)));
    }

    static inline void xor_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        vm.setMem(vm.getReg(rp), xor_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p)));
    }

    static inline void xor_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        vm.setMem(vm.getReg(rp1), xor_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2))));
    }



    static inline int32_t rdtsc_helper(){
        int32_t a;
        
        __asm {
            rdtsc        
            mov a, eax
        }

        return a;
    }

    static inline void rdtsc_(VM &vm){
        vm.setReg(0, rdtsc_helper());
    }

    static inline void rdtsc_reg(VM &vm, int32_t r){
        vm.setReg(r, rdtsc_helper());
    }

    static inline void rdtsc_ptr(VM &vm, int32_t p){
        vm.setMem(p, rdtsc_helper());
    }

    static inline void rdtsc_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), rdtsc_helper());
    }



    static inline void xtime_(VM &vm){
        vm.setReg(0, vm.getExecutionTime());
    }

    static inline void xtime_reg(VM &vm, int32_t r){
        vm.setReg(r, vm.getExecutionTime());
    }

    static inline void xtime_ptr(VM &vm, int32_t p){
        vm.setMem(p, vm.getExecutionTime());
    }

    static inline void xtime_regptr(VM &vm, int32_t rp){
        vm.setMem(vm.getReg(rp), vm.getExecutionTime());
    }



    static inline void xflush_(VM &vm){
        vm.flushStdin();
    }



    static inline void xslp_helper(int32_t a){
        if(a == 0){
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            return;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(a));
    }

    static inline void xslp_int(VM &vm, int32_t i){
        xslp_helper(i);
    }

    static inline void xslp_reg(VM &vm, int32_t r){
        xslp_helper(vm.getReg(r));
    }

    static inline void xslp_ptr(VM &vm, int32_t p){
        xslp_helper(vm.getMem(p));
    }

    static inline void xslp_regptr(VM &vm, int32_t rp){
        xslp_helper(vm.getMem(vm.getReg(rp)));
    }



    static inline void xti_helper(VM &vm, int32_t address, int32_t length){
        vm.checkAddress(address);
        vm.checkAddress(address + length - 1);

        int32_t *sliceBegin = vm.getMemory() + address;
        int32_t *sliceEnd = sliceBegin + length;
        std::string str = UnicodeToUTF8(sliceBegin, sliceEnd);
        
        size_t pos;

        try {
            int32_t i = std::stoi(str, &pos, 10);
            if(pos == str.length()){
                vm.flagOverflow = false;
                vm.setReg(0, i);
            } else {
                vm.setReg(0, 1); //Invalid string error code 1
                vm.flagOverflow = true;
                return;
            }
        } catch(std::invalid_argument &iae){
            vm.setReg(0, 1); //Invalid string error code 1
            vm.flagOverflow = true;
            return;
        } catch(std::out_of_range &oore){
            vm.setReg(0, 0); //String integer value too large error code 0
            vm.flagOverflow = true;
            return;
        }
    }

    static inline void xti_int_int(VM &vm, int32_t i1, int32_t i2){
        xti_helper(vm, i1, i2);
    }

    static inline void xti_int_reg(VM &vm, int32_t i, int32_t r){
        xti_helper(vm, i, vm.getReg(r));
    }

    static inline void xti_int_ptr(VM &vm, int32_t i, int32_t p){
        xti_helper(vm, i, vm.getMem(p));
    }

    static inline void xti_int_regptr(VM &vm, int32_t i, int32_t rp){
        xti_helper(vm, i, vm.getMem(vm.getReg(rp)));
    }

    static inline void xti_reg_int(VM &vm, int32_t r, int32_t i){
        xti_helper(vm, vm.getReg(r), i);
    }

    static inline void xti_reg_reg(VM &vm, int32_t r1, int32_t r2){
        xti_helper(vm, vm.getReg(r1), vm.getReg(r2));
    }

    static inline void xti_reg_ptr(VM &vm, int32_t r, int32_t p){
        xti_helper(vm, vm.getReg(r), vm.getMem(p));
    }

    static inline void xti_reg_regptr(VM &vm, int32_t r, int32_t rp){
        xti_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp)));
    }

    static inline void xti_ptr_int(VM &vm, int32_t p, int32_t i){
        xti_helper(vm, vm.getMem(p), i);
    }

    static inline void xti_ptr_reg(VM &vm, int32_t p, int32_t r){
        xti_helper(vm, vm.getMem(p), vm.getReg(r));
    }

    static inline void xti_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        xti_helper(vm, vm.getMem(p1), vm.getMem(p2));
    }

    static inline void xti_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        xti_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp)));
    }

    static inline void xti_regptr_int(VM &vm, int32_t rp, int32_t i){
        xti_helper(vm, vm.getMem(vm.getReg(rp)), i);
    }

    static inline void xti_regptr_reg(VM &vm, int32_t rp, int32_t r){
        xti_helper(vm, vm.getMem(vm.getReg(rp)),vm.getReg(r));    
    }

    static inline void xti_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        xti_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p));    
    }

    static inline void xti_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        xti_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2)));    
    }



    static inline void xts_helper(VM &vm, int32_t address, int32_t length){
        vm.checkAddress(address);
        vm.checkAddress(address + length - 1);
        
        std::u32string encodedString = UTF8ToUnicode(std::to_string(vm.getReg(0)));

        if(encodedString.length() > length){
            vm.setReg(0, 0); //String integer value longer than given memory length error code 0
            return;
        }

        int32_t *slice = address + vm.getMemory();
        int32_t *sliceEnd = slice + length;

        const char32_t *stringPtr = encodedString.c_str();

        while(slice != sliceEnd){
            *(slice++) = *(stringPtr++);
        }

        vm.setReg(0, encodedString.length());    
    }

    static inline void xts_int_int(VM &vm, int32_t i1, int32_t i2){
        xts_helper(vm, i1, i2);
    }

    static inline void xts_int_reg(VM &vm, int32_t i, int32_t r){
        xts_helper(vm, i, vm.getReg(r));
    }

    static inline void xts_int_ptr(VM &vm, int32_t i, int32_t p){
        xts_helper(vm, i, vm.getMem(p));
    }

    static inline void xts_int_regptr(VM &vm, int32_t i, int32_t rp){
        xts_helper(vm, i, vm.getMem(vm.getReg(rp)));
    }

    static inline void xts_reg_int(VM &vm, int32_t r, int32_t i){
        xts_helper(vm, vm.getReg(r), i);
    }

    static inline void xts_reg_reg(VM &vm, int32_t r1, int32_t r2){
        xts_helper(vm, vm.getReg(r1), vm.getReg(r2));
    }

    static inline void xts_reg_ptr(VM &vm, int32_t r, int32_t p){
        xts_helper(vm, vm.getReg(r), vm.getMem(p));
    }

    static inline void xts_reg_regptr(VM &vm, int32_t r, int32_t rp){
        xts_helper(vm, vm.getReg(r), vm.getMem(vm.getReg(rp)));
    }

    static inline void xts_ptr_int(VM &vm, int32_t p, int32_t i){
        xts_helper(vm, vm.getMem(p), i);
    }

    static inline void xts_ptr_reg(VM &vm, int32_t p, int32_t r){
        xts_helper(vm, vm.getMem(p), vm.getReg(r));
    }

    static inline void xts_ptr_ptr(VM &vm, int32_t p1, int32_t p2){
        xts_helper(vm, vm.getMem(p1), vm.getMem(p2));
    }

    static inline void xts_ptr_regptr(VM &vm, int32_t p, int32_t rp){
        xts_helper(vm, vm.getMem(p), vm.getMem(vm.getReg(rp)));
    }

    static inline void xts_regptr_int(VM &vm, int32_t rp, int32_t i){
        xts_helper(vm, vm.getMem(vm.getReg(rp)), i);
    }

    static inline void xts_regptr_reg(VM &vm, int32_t rp, int32_t r){
        xts_helper(vm, vm.getMem(vm.getReg(rp)),vm.getReg(r));    
    }

    static inline void xts_regptr_ptr(VM &vm, int32_t rp, int32_t p){
        xts_helper(vm, vm.getMem(vm.getReg(rp)), vm.getMem(p));    
    }

    static inline void xts_regptr_regptr(VM &vm, int32_t rp1, int32_t rp2){
        xts_helper(vm, vm.getMem(vm.getReg(rp1)), vm.getMem(vm.getReg(rp2)));    
    }

};