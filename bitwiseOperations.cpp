#include<iostream>
using namespace std;

class bitwiseOp {
    int x, y;

    public:
        bitwiseOp(int a, int b):x(a), y(b) {}
        
        // using XOR will make sure if both the bits are same then bit will be turned off
        // if both the bits are different then bit will be turned on.
        string 
        equalOrNot() const {
            string res;
            res = (!(x ^ y) ? "equal": "not equal");
            return res;
        }

        // Focus on last LSB bit set to 1 or 0.
        // to get the res use '&' opertion and left shift to get the single bit value.
        string
        oddOrEven(int num) const {
            int res = (num & 1) << (num-1);
            return (res ? "odd":"even");
        }

        //
        //    x: 3-> 101
        //    y: 2-> 010
        //   ===============
        //    x = x ^ y  // 111
        //    y = x ^ y; // 101
        //    x = x ^ y; // 010
        //
        void
        swap(int &x, int &y) {
            x = x ^ y;
            y = x ^ y;
            x = x ^ y;
        }

        // Detect LSB bit set or not using op '&'
        // count if bit is set
        // Move the processed bit out usin right shift. 
        // 
        int
        getSetBits(int num) {
            int count = 0;
            while(num) {
                if (num&1) {
                    count += ((num << (num-1)) ? 1 : 0);
                }
                num >>= 1;
            }
            return count;
        }

        // Detect if the last bit is set ot not 
        // use XOR 1 op with the num , since if bit is set it will turn off.
        int
        clearRightMostSetBit(int num) {
            int res = ((num & 1) << (num-1) ? (num ^ 1) : num);
            return res;
        }

        // To set the bit on a number we can make use of OR op.
        int
        enableNthBit(int num, int bitPos) {
            return num |= (1<<bitPos);
        }

        // bit pos start with 0 .... n
        // n ... (n-1) .. (n-2) ........... 4..2..1..0
        // MSB                                      LSB
        // Logic here is focus on bit whihc we are intrested in,
        // retrive that by doing right shift
        // later, verify if the bit set of not using & op.
        bool
        isNthBitSet(int num, int bitPos) {
            int x = num >> bitPos;
            if (x&1) {
                x = x << (x-1);
                return (x ? true : false);
            }
            return false;
        }


        // First detect if the Nth bit is set or not.
        // Use XOR op to turn off the bit if set.
        int 
        disableNthBit(int num, int bitPos) {
            // check if the Nth bit is set first
            int x = num >> bitPos;
            int res = num;
            // isvalid num ?
            if (x&1) {
                // retrive single bit
                x = x << (x-1);
                // if bit set
                if (x) {
                    res ^= (1 << bitPos); // XOR will turn off the same bits.
                }
            }

            return res;
        }

        // XOR op will toggle the bits.
        // if bit is set we will turn off the bit 
        // if bit is not set we will enable the bit.
        int
        toggleNthBit(int num, int bitPos) {
            return (num ^ (1<<bitPos));
        }


        // Logic is to get the total set bits.
        // ideally we should get set bit count 1 if num
        // is power of 2.
        string
        isNumPowerOf2(int num) {
            int count =0;
            // count the set bits.
            while(num) {
                if (num&1) {
                    count++;
                }
                num >>=1;
            }
            // If the num is power of 2, then we must get the total set bit as 1.
            return (count == 1 ? "yes" : "No");

            // Alternative soln
            // !(num & (num-1));

        }
};

int main() {

    int x{10}, y{21};
    int a{10}, b{10};

    bitwiseOp obj1(x,y);
    bitwiseOp obj2(a,b);    

    // Equal or not verification:
    cout << "Equal or not verification:" << endl;
    cout << "Numbers " << x <<" and " << y << " are " << obj1.equalOrNot() << endl;
    cout << "Numbers " << a <<" and " << b << " are " << obj2.equalOrNot() << endl;

    cout << endl;
    // Even Odd verification
    cout << "Even Or Odd Verification:" << endl;
    cout << "Number " << x << " is " << obj1.oddOrEven(x) << endl;
    cout << "Number " << y << " is " << obj1.oddOrEven(y) << endl;

    cout << endl;
    // Swap verification:
    cout << "Before swap numbers x:" << x << " y:" << y << endl;
    obj1.swap(x,y);
    cout << "After swap numbers x:" << x << " y:" << y << endl;

    cout << endl;
    // Set Bit verification:
    cout << "Set Bit verification: " << endl;    
    cout << "Total set bits in number " << x << " is:" << obj1.getSetBits(x) << endl;
    cout << "Total set bits in number " << y << " is:" << obj1.getSetBits(y) << endl;
    
    cout << endl;
    // Clear Right most set Bit verification:
    cout << "Clear right most set Bit verification: " << endl; 
    cout << "Before clearing the right most set bit: number " << x << endl;
    cout << "After clearing the right most set bit: number " << obj1.clearRightMostSetBit(x) << endl;

    cout << endl;
    // Enable the Nth bit of a number verification:
    cout << "Enable the Nth bit of a number verification:: " << endl; 
    cout << "Before Enabling the bit: number " << y << endl;
    int pos{4};
    cout << "After Enabling the bit pos " << pos << " number is " << obj1.enableNthBit(y, pos) << endl;

    cout << endl;
    // Check if the Nth bit of a number is set or not verification:
    cout << "Check the Nth bit of a number set or not verification:: " << endl; 
    cout << "Check bit pos " << pos << " of number " << y << " is set ? : "<< obj1.isNthBitSet(y, pos) << endl;

    cout << endl;
    // Disable Nth bit of a number verification:
    cout << "Disable Nth bit of a number verification: " << endl; 
    cout << "After disabling bit pos " << pos-1 << " of number " << y << " is : "<< obj1.disableNthBit(y, pos-1) << endl;

    cout << endl;
    // Toggle Nth bit of a number verification:
    cout << "Toggle Nth bit of a number verification: " << endl; 
    cout << "Toggle bit pos " << pos << " of number " << y << " is : "<< obj1.toggleNthBit(y, pos) << endl;


    cout << endl;
    // Power of 2 verification:
    cout << "Power of 2 verification: " << endl; 
    cout << "is Number " << y << " is power of 2 ? "<< obj1.isNumPowerOf2(y) << endl;
    cout << "is Number " << 128 << " is power of 2 ? "<< obj1.isNumPowerOf2(128) << endl;

    return 0;
}


// Sample output of a program:
//=======================================================================
// PS C:\Raghavendra\Programs\bitwise> cd "c:\Raghavendra\Programs\bitwise\" ; if ($?) { g++ bitwiseOperations.cpp -o bitwiseOperations } ; if ($?) { .\bitwiseOperations }
// Equal or not verification:
// Numbers 10 and 21 are not equal
// Numbers 10 and 10 are equal

// Even Or Odd Verification:
// Number 10 is even
// Number 21 is odd

// Before swap numbers x:10 y:21
// After swap numbers x:21 y:10

// Set Bit verification:
// Total set bits in number 21 is:3
// Total set bits in number 10 is:2

// Clear right most set Bit verification:
// Before clearing the right most set bit: number 21
// After clearing the right most set bit: number 20

// Enable the Nth bit of a number verification::
// Before Enabling the bit: number 10
// After Enabling the bit pos 4 number is 26

// Check the Nth bit of a number set or not verification::
// Check bit pos 4 of number 10 is set ? : 0

// Disable Nth bit of a number verification:
// After disabling bit pos 3 of number 10 is : 2

// Toggle Nth bit of a number verification:
// Toggle bit pos 4 of number 10 is : 26

// Power of 2 verification:
// is Number 10 is power of 2 ? No
// is Number 128 is power of 2 ? yes
// PS C:\Raghavendra\Programs\bitwise> 
