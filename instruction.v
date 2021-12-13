`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/02 14:29:35
// Design Name: 
// Module Name: instruction
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module instruction(
  clk,
    pc,r_data
    
);
 input clk;
  input [31:0]pc;

    output reg [31:0]r_data;
     reg[31:0] mem[0:32767];
     initial $readmemh("/home/denjo/microprocess/b3exp/benchmarks/tests/Uart/code.hex",mem);

  
//     intial begin
//     end 
    //initial $readmemb 
    always @(posedge clk )begin
      
      r_data<=mem[pc[16:0]>>2];
   
     
    end
endmodule
