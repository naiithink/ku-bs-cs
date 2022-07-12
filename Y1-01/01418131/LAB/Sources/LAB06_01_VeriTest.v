// Verilog test fixture created from schematic /home/naiithink/in-Sync/Workspaces/Files/ISE_DS/CS131-LAB/Sources/LAB06_01.sch - Wed Sep  1 01:18:28 2021

`timescale 1ns / 1ps

module LAB06_01_LAB06_01_sch_tb();

// Inputs
   reg b;
   reg a;

// Output
   wire x;
   wire y;

// Bidirs

// Instantiate the UUT
   LAB06_01 UUT (
		.b(b), 
		.a(a), 
		.x(x), 
		.y(y)
   );
// Initialize Inputs
	
	integer count = 0;
	
	initial
		begin
		
			while (count < 4)
				begin
				
				count = count + 1;
				
				assign a = 0;
				assign b = 0;
				
				if (count == 3 || count == 4)
					begin
						assign a = 1;
					end
				
				if (count == 2 || count == 4)
					begin
						assign b = 1;
					end
				
				#5;
				
				end
		
		$finish;
		end
	
	initial
		begin
		
		$monitor("a = %d, b = %d  :  x = %d, y = %d	count = %2d", a, b, x, y, count);
		
		end

endmodule
