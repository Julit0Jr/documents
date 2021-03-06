##############################################################################
#
#  KURS: 1DT016 2014.  Computer Architecture
#	
# DATUM:
#
#  NAMN:			
#
#  NAMN:
#
##############################################################################

	.data
	
ARRAY_SIZE:
	.word	10	# Change here to try other values (less than 10)
FIBONACCI_ARRAY:
	.word	1, 1, 2, 3, 5, 8, 13, 21, 34, 55
STR_str:
	.asciiz "Hunden, Katten, Glassen"

	.globl DBG
	.text

##############################################################################
#
# DESCRIPTION:  For an array of integers, returns the total sum of all
#		elements in the array.
#
# INPUT:        $a0 - address to first integer in array.
#		$a1 - size of array, i.e., numbers of integers in the array.
#
# OUTPUT:       $v0 - the total sum of all integers in the array.
#
##############################################################################
integer_array_sum:  

DBG:	##### DEBUGG BREAKPOINT ######

    addi $v0, $zero, 0      # Initialize Sum to zero.
	add	$t0, $zero, $zero	# Initialize array index i to zero.

for_all_in_array:

	#### Append a MIPS-instruktion before each of these comments
	beq	$t0, $a1, end_for_all# Done if i == N
	add $t1, $t0, $t0 		# 4*i
	add $t1, $t1, $t1
	add $t1, $a0, $t1 		# address = ARRAY + 4*i
	lw  $t2, 0($t1)			# n = A[i]
    add $v0, $v0, $t2   	# Sum = Sum + n
    add $t0, $t0, 1			# i++ 
	j 	for_all_in_array   	# next element
end_for_all:
	jr	$ra					# Return to caller.
	
##############################################################################
#
# DESCRIPTION: Gives the length of a string.
#
#       INPUT: $a0 - address to a NUL terminated string.
#
#      OUTPUT: $v0 - length of the string (NUL excluded).
#
#    EXAMPLE:  string_length("abcdef") == 6.
#
##############################################################################	
string_length:

	#### Write your solution here ####

	addi $v0, $zero, 0 					# Initialize length (counter) to zero 
	lb   $t1, STR_str 					# Loads the first character in $t1

for_all_in_str:

	beq $t1,0x00, end_for_str  	# DONE if $t1 is equal to a null character
	addi $v0, $v0, 1						#increment the length (counter)
	lb   $t1, STR_str($v0)
	j for_all_in_str						# next character

end_for_str:
	jr	$ra 										# Return to caller
	
##############################################################################
#
#  DESCRIPTION: For each of the characters in a string (from left to right),
#		call a callback subroutine.
#
#		The callback suboutine will be called with the address of
#	        the character as the input parameter ($a0).
#	
#        INPUT: $a0 - address to a NUL terminated string.
#
#		$a1 - address to a callback subroutine.
#
##############################################################################	
string_for_each:

    addiu $sp, $sp, -12             # Need 3 locals for $a0, $a1 and $ra
    sw  $ra, 0($sp)                 # Store $ra
    sw  $a1, 8($sp)                 # Store $a1

loop1:
    sw  $a0, 4($sp)                 # Store $a0 as it will be used for argument
    lb  $t0, 0($a0)                 # Get current character
    beq $t0, $zero, end_for_each    # Done when reaching NULL character
    jalr $a1                        # Call callback subroutine
    lw  $a0, 4($sp)                 # Reload $a0
    lw  $a1, 8($sp)                 # $a1 could have changed (calling convention)
    addi $a0, $a0, 1                # Increment to get next character in string
    j   loop1

end_for_each:
    lw  $ra, 0($sp)                 # Reload return address to caller
    addiu $sp, $sp, 12              # Free locals
    jr  $ra

##############################################################################
#
#  DESCRIPTION: Transforms a lower case character [a-z] to upper case [A-Z].
#	
#        INPUT: $a0 - address of a character 
#
##############################################################################		
to_upper:

	#### Write your solution here ####
	la $a0, STR_str
	addi $v0, $zero, 0

	loop3:

		lb $t0, 0($a0)
		
		beq $t0, $zero, end2
		
		blt $t0, 'a', inc_address
		sub $t0, $t0, 32
		
		sb $t0, 0($a0)

	inc_address:
		addi $a0, $a0, 1
		addi $v0, $v0, 1
		
		j loop3

	end2:
	jr	$ra


##############################################################################
##############################################################################
##
##	  You don't have to change anyghing below this line.
##	
##############################################################################
##############################################################################

	
##############################################################################
#
# Strings used by main:
#
##############################################################################

	.data

NLNL:	.asciiz "\n\n"
	
STR_sum_of_fibonacci_a:	
	.asciiz "The sum of the " 
STR_sum_of_fibonacci_b:
	.asciiz " first Fibonacci numbers is " 

STR_string_length:
	.asciiz	"\n\nstring_length(str) = "

STR_for_each_ascii:	
	.asciiz "\n\nstring_for_each(str, ascii)\n"

STR_for_each_to_upper:
	.asciiz "\n\nstring_for_each(str, to_upper)\n\n"	

	.text
	.globl main

##############################################################################
#
# MAIN: Main calls various subroutines and print out results.
#
##############################################################################	
main:
	addi	$sp, $sp, -4	# PUSH return address
	sw	$ra, 0($sp)

	##
	### integer_array_sum
	##
	
	li	$v0, 4
	la	$a0, STR_sum_of_fibonacci_a
	syscall

	lw 	$a0, ARRAY_SIZE
	li	$v0, 1
	syscall

	li	$v0, 4
	la	$a0, STR_sum_of_fibonacci_b
	syscall
	
	la	$a0, FIBONACCI_ARRAY
	lw	$a1, ARRAY_SIZE
	jal 	integer_array_sum

	# Print sum
	add	$a0, $v0, $zero
	li	$v0, 1
	syscall

	li	$v0, 4
	la	$a0, NLNL
	syscall
	
	la	$a0, STR_str
	jal	print_test_string

	##
	### string_length 
	##
	
	li	$v0, 4
	la	$a0, STR_string_length
	syscall

	la	$a0, STR_str
	jal 	string_length

	add	$a0, $v0, $zero
	li	$v0, 1
	syscall

	##
	### string_for_each(string, ascii)
	##
	
	li	$v0, 4
	la	$a0, STR_for_each_ascii
	syscall
	
	la	$a0, STR_str
	la	$a1, ascii
	jal	string_for_each

	##
	### string_for_each(string, to_upper)
	##
	
	li	$v0, 4
	la	$a0, STR_for_each_to_upper
	syscall

	la	$a0, STR_str
	la	$a1, to_upper
	jal	string_for_each
	
	la	$a0, STR_str
	jal	print_test_string

	lw	$ra, 0($sp)	# POP return address
	addi	$sp, $sp, 4	
	
	jr	$ra

##############################################################################
#
#  DESCRIPTION : Prints out 'str = ' followed by the input string surronded
#		 by double quotes to the console. 
#
#        INPUT: $a0 - address to a NUL terminated string.
#
##############################################################################
print_test_string:	

	.data
STR_str_is:
	.asciiz "str = \""
STR_quote:
	.asciiz "\""	

	.text

	add	$t0, $a0, $zero
	
	li	$v0, 4
	la	$a0, STR_str_is
	syscall

	add	$a0, $t0, $zero
	syscall

	li	$v0, 4	
	la	$a0, STR_quote
	syscall
	
	jr	$ra
	

##############################################################################
#
#  DESCRIPTION: Prints out the Ascii value of a character.
#	
#        INPUT: $a0 - address of a character 
#
##############################################################################
ascii:	
	.data
STR_the_ascii_value_is:
	.asciiz "\nAscii('X') = "

	.text

	la	$t0, STR_the_ascii_value_is

	# Replace X with the input character
	
	add	$t1, $t0, 8	# Position of X
	lb	$t2, 0($a0)	# Get the Ascii value
	sb	$t2, 0($t1)

	# Print "The Ascii value of..."
	
	add	$a0, $t0, $zero 
	li	$v0, 4
	syscall

	# Append the Ascii value
	
	add	$a0, $t2, $zero
	li	$v0, 1
	syscall


	jr	$ra
	