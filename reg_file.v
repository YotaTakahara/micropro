`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/01 23:44:28
// Design Name: 
// Module Name: alu
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

`include "define.vh"

module reg_file( clk,reg_we,rs1_addr,rs2_addr,w_addr
  ,rs1_data,rs2_data,w_data
  
);
input clk,reg_we;
input [4:0]rs1_addr,rs2_addr,w_addr;
input [31:0]w_data;
output wire[31:0]rs1_data,rs2_data;
reg[31:0]mem[0:31];
//initial $readmemb("code.hex",mem);
 //initial $readmemb 
 //initial  $readmemh("/home/denjo/microprocess/b3exp/benchmarks/tests/ZeroRegister/code.hex",mem);
 
 initial begin
 mem[0]=32'd0;
 end

  always @(posedge clk)begin
    if(reg_we)begin
  
       if(w_addr!=5'd0)mem[w_addr]=w_data;
    end
   
  end
  assign   rs1_data=mem[rs1_addr];
  assign   rs2_data=mem[rs2_addr];

endmodule