// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
	(START)
	@KBD
	D=M
	@WHITE_SCREEN
	D;JEQ

	(BLACK_SCREEN)
	@i
	M=0
	@8192 // Number of rows in screen map
	D=A
	@n
	M=D
	(FILL_BLACK_LOOP)
	@i
	D=M
	@n
	D=M-D
	@START
	D;JEQ
	@SCREEN
	D=A
	@i
	A=D+M
	M=-1 // set all pixels to 1
	@i
	M=M+1
	@FILL_BLACK_LOOP
	0;JMP

	

	(WHITE_SCREEN)
	@i
	M=0
	@8192 // Number of rows in screen map
	D=A
	@n
	M=D
	(FILL_WHITE_LOOP)
	@i
	D=M
	@n
	D=M-D
	@START
	D;JEQ
	@SCREEN
	D=A
	@i
	A=D+M
	M=0 // set all pixels to 1
	@i
	M=M+1
	@FILL_WHITE_LOOP
	0;JMP
	
