// Verilog test fixture created from schematic /home/naiithink/in-Sync/Workspaces/Files/ISE_DS/CS131-LAB/Sources/LAB05_02.sch - Tue Aug 31 21:35:28 2021

`timescale 1ns / 1ps

module LAB05_02_LAB05_02_sch_tb();

// Inputs
   reg B;
   reg D;
   reg E;
   reg H;
   reg S;

// Output
   wire Buzzer;

// Bidirs

// Instantiate the UUT
   LAB05_02 UUT (
		.B(B), 
		.D(D), 
		.E(E), 
		.H(H), 
		.S(S), 
		.Buzzer(Buzzer)
   );
// Initialize Inputs
	
	
	initial
		begin
		//17.1
		H = 1;
		E = 0;
		#5;
		
		// reset
		B = 0;
		E = 0;
		D = 0;
		S = 0;
		H = 0;
		#5;
		
		//17.2
		S = 1;
		E = 1;
		B = 0;
		#5;
		
		// reset
		B = 0;
		E = 0;
		D = 0;
		S = 0;
		H = 0;
		#5;
		
		//17.3
		H = 1;
		E = 0;
		
		#5;
		// reset
		B = 0;
		E = 0;
		D = 0;
		S = 0;
		H = 0;
		#5;
		
		//17.4
		B = 1;
		E = 1;
		S = 0;
		
		#5;
		
		$finish;
		end
		
	initial
		begin
		$monitor("B = %d, E = %d, D = %d, H = %d, S = %d  :  Buzzer = %d", B, E, D, H, S, Buzzer);
		end
	
endmodule
