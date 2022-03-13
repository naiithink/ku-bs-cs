// Verilog test fixture created from schematic /home/naiithink/in-Sync/Workspaces/Files/ISE_DS/CS131-LAB/Sources/LAB05_01.sch - Tue Aug 31 21:06:37 2021

`timescale 1ns / 1ps

module LAB05_01_LAB05_01_sch_tb();

// Inputs
   reg B;
   reg A;

// Output
   wire X;
   wire Y;

// Bidirs

// Instantiate the UUT
   LAB05_01 UUT (
		.B(B), 
		.A(A), 
		.X(X), 
		.Y(Y)
   );
// Initialize Inputs
	initial begin
	A = 0;
	B = 0;
	#5;
	A = 0;
	B = 1;
	#5;
	A = 1;
	B = 0;
	#5;
	A = 1;
	B = 1;
	#5;
	$finish;
	end
	initial begin
	$monitor("A = %d, B = %d : X = %d, Y = %d", A, B, X, Y);
	end
endmodule
