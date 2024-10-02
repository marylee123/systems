#include <stdio.h>
int main(){
    char c = 'a';
    int i = 0;
    long l = 1;
    
    //values
    printf("Values:\n");
    printf("char c = %c\n", c);
    printf("int i = %d\n", i);
    printf("long l = %ld\n", l);
    printf("\n");
    //addresses
    printf("Address of...\n");
    printf("char: hex = %p, decimal = %lu\n", &c, &c);
    printf("int: hex = %p, decimal = %lu\n", &i, &i);
    printf("long: hex = %p, decimal = %lu\n", &l, &l);
    printf("\n");
    // NOTE: addresses change when program is rerun
    // NOTE: &c = &i + 7 = &l + 19
    
    int* c_ptr = &c;
    char* i_ptr = &i;
    long* l_ptr = &l;
    //values using pointers
    printf("Values using pointers:\n");
    printf("char c = %c\n", *c_ptr);
    printf("int i = %d\n", *i_ptr);
    printf("long l = %ld\n", *l_ptr);
    printf("\n");
    
    //modifying values using pointers
    *c_ptr = 'b';
    *i_ptr = 1;
    *l_ptr = 2;
    printf("Modified Values (using pointers):\n");
    printf("char c = %c\n", *c_ptr);
    printf("int i = %d\n", *i_ptr);
    printf("long l = %ld\n", *l_ptr);
    printf("\n");
    
    unsigned int twice_ptd = 1 + 2 + 4 + 256 + 512 + 1024 + 2048;
    int* int_ptr = &twice_ptd;
    char* char_ptr = &twice_ptd;
    
    // address of char and int pointers, pointing to same var
    printf("2 Pointers to one var:\n");
    printf("int_ptr: %p, int_ptr points to %d\n", int_ptr, *int_ptr);
    printf("char_ptr: %p, char_ptr points to %c\n", char_ptr, *char_ptr);
    printf("\n");
    
    //value of unsigned int in decimal and hex
    printf("Value of unsigned int:\n");
    printf("decimal: %u\n", twice_ptd);
    printf("hex: %x\n", twice_ptd);
    printf("\n");
    
    printf("Individual bytes of unsigned int: %hhu\n", *char_ptr);
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+1));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+2));
    printf("\n");
    // returns value of each byte
    
    *char_ptr += 1;
    *(char_ptr+1) += 1;
    printf("decimal format of unsigned int: %u\n", twice_ptd);
    printf("hex format of unsigned int: %x\n", twice_ptd);
    printf("Individual bytes of unsigned int: %hhu\n", *char_ptr);
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+1));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+2));
    printf("\n");
    
    *char_ptr += 16;
    *(char_ptr+1) += 16;
    printf("decimal format of unsigned int: %u\n", twice_ptd);
    printf("hex format of unsigned int: %x\n", twice_ptd);
    printf("Individual bytes of unsigned int: %hhu\n", *char_ptr);
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+1));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+2));
    printf("\n");
    
    *char_ptr += 32;
    *(char_ptr+1) += 32;
    printf("decimal format of unsigned int: %u\n", twice_ptd);
    printf("hex format of unsigned int: %x\n", twice_ptd);
    printf("Individual bytes of unsigned int: %hhu\n", *char_ptr);
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+1));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_ptr+2));
    printf("\n");
    
    // new large unsigned int
    unsigned int bill = 2200000000;
    int* int_bill = &bill;
    char* char_bill = &bill;
    printf("decimal format of 2 billion unsigned int: %u\n", bill);
    printf("hex format of 2 billion unsigned int: %x\n", bill);
    printf("Individual bytes of unsigned int: %hhu\n", *char_bill);
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+1));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+2));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+3));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+4));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+5));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+6));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+7));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+8));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+9));
    printf("\n");
    
    *char_bill += 16;
    *(char_bill+1) += 16;
    *(char_bill+2) += 16;
    *(char_bill+3) += 16;
    *(char_bill+4) += 16;
    *(char_bill+5) += 16;
    *(char_bill+6) += 16;
    *(char_bill+7) += 16;
    *(char_bill+8) += 16;

    printf("decimal format of increased 2 billion unsigned int: %u\n", bill);
    printf("hex format of increased 2 billion unsigned int: %x\n", bill);
    printf("Individual bytes of unsigned int: %hhu\n", *char_bill);
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+1));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+2));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+3));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+4));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+5));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+6));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+7));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+8));
    printf("Individual bytes of unsigned int: %hhu\n", *(char_bill+9));
    printf("\n");
    
    // new regular int
    int reg = 2200000000;
    int* int_reg = &reg;
    char* char_reg = &reg;
    
    printf("decimal format of regular int: %u\n", reg);
    printf("hex format of regular int: %x\n", reg);
    printf("Individual bytes of int: %hhu\n", *char_reg);
    printf("Individual bytes of int: %hhu\n", *(char_reg+1));
    printf("Individual bytes of int: %hhu\n", *(char_reg+2));
    printf("Individual bytes of int: %hhu\n", *(char_reg+3));
    printf("Individual bytes of int: %hhu\n", *(char_reg+4));
    printf("Individual bytes of int: %hhu\n", *(char_reg+5));
    printf("Individual bytes of int: %hhu\n", *(char_reg+6));
    printf("Individual bytes of int: %hhu\n", *(char_reg+7));
    printf("Individual bytes of int: %hhu\n", *(char_reg+8));
    printf("Individual bytes of int: %hhu\n", *(char_reg+9));
    printf("\n");
    
    *char_reg += 16;
    *(char_reg+1) += 16;
    *(char_reg+2) += 16;
    *(char_reg+3) += 16;
    *(char_reg+4) += 16;
    *(char_reg+5) += 16;
    *(char_reg+6) += 16;
    *(char_reg+7) += 16;
    *(char_reg+8) += 16;

    printf("decimal format of regular int: %u\n", reg);
    printf("hex format of regular int: %x\n", reg);
    printf("Individual bytes of int: %hhu\n", *char_reg);
    printf("Individual bytes of int: %hhu\n", *(char_reg+1));
    printf("Individual bytes of int: %hhu\n", *(char_reg+2));
    printf("Individual bytes of int: %hhu\n", *(char_reg+3));
    printf("Individual bytes of int: %hhu\n", *(char_reg+4));
    printf("Individual bytes of int: %hhu\n", *(char_reg+5));
    printf("Individual bytes of int: %hhu\n", *(char_reg+6));
    printf("Individual bytes of int: %hhu\n", *(char_reg+7));
    printf("Individual bytes of int: %hhu\n", *(char_reg+8));
    printf("Individual bytes of int: %hhu\n", *(char_reg+9));
    printf("\n");
    return 0;
}

     
