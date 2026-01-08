// main.cpp - improved test harness for PolySet (stack-allocated bags)
#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"

#include <cstdlib>
#include <iostream>

static void sep() { std::cout << "-------------------------------\n"; }

int main()
{
    // 1) Build original bags with duplicates (stack allocation to avoid delete-through-base UB)
    searchable_array_bag arr;
    searchable_tree_bag  tr;

    int inputs[] = { 1, 2, 2, 3, 3, 3, 4, 1 };
    std::cout << "Inserting:";
    for (size_t i = 0; i < sizeof(inputs)/sizeof(inputs[0]); ++i) {
        std::cout << ' ' << inputs[i];
        arr.insert(inputs[i]);
        tr.insert(inputs[i]);
    }
    std::cout << std::endl;
    sep();

    // 2) Print originals
    std::cout << "Original array bag (allows duplicates): "; arr.print();
    std::cout << "Original tree  bag (unique / tree order): "; tr.print();
    sep();

    // 3) Make sets from originals (should deep-copy inside set ctor)
    set sa(arr); // set from array bag (passes const searchable_bag&)
    set st(tr);  // set from tree bag

    std::cout << "Set sa (from array bag) : "; sa.print();
    std::cout << "Set st (from tree bag)  : "; st.print();
    sep();

    // 4) Modify originals -> expect sets NOT to change if deep-copy worked
    std::cout << "Clearing original array bag and inserting 99 into it.\n";
    arr.clear();
    arr.insert(99);

    std::cout << "Original array bag (after clear+insert 99): "; arr.print();
    std::cout << "Set sa (should be unchanged):                  "; sa.print();
    sep();

    std::cout << "Clearing original tree bag and inserting 42 into it.\n";
    tr.clear();
    tr.insert(42);

    std::cout << "Original tree bag (after clear+insert 42): "; tr.print();
    std::cout << "Set st (should be unchanged):                "; st.print();
    sep();

    // 5) Modify sets -> expect originals NOT to change
    std::cout << "Inserting 123 into set sa and clearing set st.\n";
    sa.insert(123);
    st.clear();

    std::cout << "Set sa (after insert 123): "; sa.print();
    std::cout << "Original array bag (should still be 99 only): "; arr.print();
    std::cout << "Set st (after clear): "; st.print();
    std::cout << "Original tree bag (should still be 42): "; tr.print();
    sep();

    // 6) Test copying sets (copy ctor and assignment) and independence
    std::cout << "Copying sets: sb = sa (copy ctor), sc assigned from sa.\n";
    set sb(sa);        // copy ctor
    set sc = sa;       // copy ctor (or assignment)
    set sd(st);        // copy of st (which was cleared earlier)

    std::cout << "sa: "; sa.print();
    std::cout << "sb: "; sb.print();
    std::cout << "sc: "; sc.print();
    std::cout << "sd (copy of cleared st): "; sd.print();
    sep();

    std::cout << "Now modify original sa (insert 7) and clear original arr again.\n";
    sa.insert(7);
    arr.clear();

    std::cout << "sa (after insert 7): "; sa.print();
    std::cout << "sb (should NOT have 7): "; sb.print();
    std::cout << "Original arr (cleared): "; arr.print();
    sep();

    // 7) Final check: ensure get_bag() returns an independent underlying bag reference
    std::cout << "Calling sa.get_bag().print(): "; sa.get_bag().print();
    std::cout << "Calling sb.get_bag().print(): "; sb.get_bag().print();
    sep();

    std::cout << "Test complete.\n";
    return 0;
}
