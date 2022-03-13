// Verilog test fixture created from schematic /home/naiithink/in-Sync/Workspaces/Files/ISE_DS/CS131-LAB/Sources/LAB06_02.sch - Wed Sep  1 07:24:08 2021

`timescale 1ns / 1ps

module LAB06_02_LAB06_02_sch_tb();

// Inputs
   reg B;
   reg C;
   reg D;
   reg A;

// Output
   wire S0;
   wire C1;
   wire S1;

// Bidirs

// Instantiate the UUT
   LAB06_02 UUT (
		.S0(S0), 
		.B(B), 
		.C(C), 
		.D(D), 
		.A(A), 
		.C1(C1), 
		.S1(S1)
   );
// Initialize Inputs
	
	integer count = 0;
	
	initial
		begin
		
			while (count < 7)
				begin
				
					count = count + 1;
				
					assign A = 0;
					assign B = 0;
					assign C = 0;
					assign D = 0;
					
					if (count >= 4)
						begin
						assign A = 1;
						end
						
					if (count != 1 && count != 4)
						begin
						assign B = 1;
						end
						
					if (count != 1 && count != 5)
						begin
						assign C = 1;
						end
					
					if (count != 1 && count != 2 && count != 6)
						begin
						assign D = 1;
						end
					
					#5;
			
				end
		
		$finish;
		end
		
		initial
			begin
			
			$monitor("A = %d, B = %d, C = %d, D = %d  :  C1 = %d, S1 = %d, S0 = %d", A, B, C, D, C1, S1, S0);
			end
		
endmodule
